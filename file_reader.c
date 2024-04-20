//
// Created by Admin on 16/01/2024.
//

#include "file_reader.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <errno.h>
#include "tested_declarations.h"
#include "rdebug.h"

struct disk_t* disk_open_from_file(const char* volume_file_name){
    if(volume_file_name==NULL) {
        errno=EFAULT;
        return NULL;
    }
    struct disk_t* result=malloc(sizeof(struct disk_t));
    if(result==NULL) {
        errno=ENOENT;
        return NULL;
    }
    result->fp=fopen(volume_file_name,"rb");
    if(result->fp==NULL){
        free(result);
        errno=ENOMEM;
        return NULL;
    }
    return result;
}

int disk_close(struct disk_t* pdisk){
    if(pdisk==NULL) {
        errno=EFAULT;
        return -1;
    }
    if(pdisk->fp==NULL) return -1;
    fclose(pdisk->fp);
    free(pdisk);
    return 0;
}

int disk_read(struct disk_t* pdisk, int32_t first_sector, void* buffer, int32_t sectors_to_read){
    if(pdisk==NULL||pdisk->fp==NULL||buffer==NULL||sectors_to_read<1||first_sector<0) {
        errno = EFAULT;
        return -1;
    }
    fseek(pdisk->fp,first_sector*BYTES_PER_BLOCK,SEEK_SET);
    if((int)fread(buffer, BYTES_PER_BLOCK,sectors_to_read,pdisk->fp)!=sectors_to_read){
        errno=ENOMEM;
        return -1;
    }
    return 0;
}

struct volume_t* fat_open(struct disk_t* pdisk, uint32_t first_sector){
    if (pdisk==NULL||pdisk->fp==NULL) {
        errno=EFAULT;
        return NULL;
    }
    struct fat_super_t *super=malloc(sizeof(struct fat_super_t));
    if(super==NULL) {
        errno=ENOMEM;
        return NULL;
    }
    if(disk_read(pdisk,(int32_t )first_sector,super,1)!=0){
        free(super);
        errno=EINVAL;
        return NULL;
    }
    if ( super->magic != FAT_MAGIC_NUMBER ) {
        free(super);
        errno=EINVAL;
        return NULL;
    }
    struct volume_t* result=malloc(sizeof(struct volume_t));
    if(result==NULL) {
        free(super);
        errno=ENOMEM;
        return NULL;
    }
    result->pdisk=pdisk;
    result->super=super;
    result->volume_size=super->logical_sectors16 == 0 ? super->logical_sectors32 : super->logical_sectors16;
    int fat_start_1=super->reserved_sectors;
    int fat_start_2=fat_start_1+super->sectors_per_fat;
    result->fat=malloc(super->sectors_per_fat*super->bytes_per_sector);
    if(result->fat==NULL){
        free(super);
        free(result);
        errno=ENOMEM;
        return NULL;
    }
    if(disk_read(pdisk,fat_start_1,result->fat,super->sectors_per_fat)!=0){
        free(super);
        free(result->fat);
        free(result);
        errno=EINVAL;
        return NULL;
    }
    void* fat2=malloc(super->sectors_per_fat*super->bytes_per_sector);
    if(fat2==NULL){
        free(super);
        free(result->fat);
        free(result);
        errno=ENOMEM;
        return NULL;
    }
    if(disk_read(pdisk,fat_start_2,fat2,super->sectors_per_fat)!=0){
        free(super);
        free(result->fat);
        free(result);
        free(fat2);
        errno=EINVAL;
        return NULL;
    }
    if(memcmp(result->fat,fat2,super->sectors_per_fat*super->bytes_per_sector)!=0){
        free(super);
        free(result->fat);
        free(result);
        free(fat2);
        errno=EINVAL;
        return NULL;
    }
    free(fat2);
    int sectors_per_root_dir=(int)(super->root_dir_capacity* sizeof(struct dir_entry_read_t))/super->bytes_per_sector;
    int root_dir_start=fat_start_2+super->sectors_per_fat;
    result->root_dir=malloc(super->root_dir_capacity* sizeof(struct dir_entry_read_t));
    if(result->root_dir==NULL){
        free(super);
        free(result->fat);
        free(result);
        errno=ENOMEM;
        return NULL;
    }
    if(disk_read(pdisk,root_dir_start,result->root_dir,sectors_per_root_dir)!=0){
        free(super);
        free(result->fat);
        free(result->root_dir);
        free(result);
        errno=EINVAL;
        return NULL;
    }
    result->first_data_sector=root_dir_start+sectors_per_root_dir;
    result->usable_cluster_count=super->logical_sectors16==0?super->logical_sectors32-result->first_data_sector:super->logical_sectors16-result->first_data_sector;

    return result;
}
int fat_close(struct volume_t* pvolume){
    if(pvolume==NULL) {
        errno=EFAULT;
        return -1;
    }
    free(pvolume->fat);
    free(pvolume->root_dir);
    free(pvolume->super);
    free(pvolume);
    return 0;
}



struct file_t* file_open(struct volume_t* pvolume, const char* file_name){
    if(pvolume==NULL||pvolume->fat==NULL||pvolume->root_dir==NULL||pvolume->super==NULL||file_name==NULL) {
        errno=EFAULT;
        return NULL;
    }
    struct file_t* result=malloc(sizeof(struct file_t));
    if(result==NULL) {
        errno=ENOMEM;
        return NULL;
    }
    struct dir_entry_read_t* dirEntry=pvolume->root_dir;
    struct dir_entry_t* dirEntry_temp;
    for(int i=0; i<pvolume->super->root_dir_capacity; i++){
        dirEntry_temp=read_directory_entry(dirEntry+i);
        if(dirEntry_temp==NULL) {
            free(result);
            errno=ENOENT;
            return NULL;
        }
        if(strcmp(dirEntry_temp->name,file_name)==0){
            if(dirEntry_temp->is_directory==1){
                errno = EISDIR;
                free(result);
                free(dirEntry_temp);
                return NULL;
            }
            result->file_info=*(dirEntry+i);
            int first_cluster=(dirEntry+i)->younger_two_bytes_first_cluster_number;
            result->volume=pvolume;
            result->fat_chain=get_chain_fat12(pvolume->fat,pvolume->usable_cluster_count,first_cluster);
            if(result->fat_chain==NULL){
                free(result);
                free(dirEntry_temp);
                errno=ENOMEM;
                return NULL;
            }
            result->file_positon=0;
            free(dirEntry_temp);
            return result;
        }
        free(dirEntry_temp);
    }
    free(result);
    errno=ENOENT;
    return NULL;
}
int file_close(struct file_t* stream){
    if(stream==NULL) {
        errno=EFAULT;
        return -1;
    }
    free(stream->fat_chain->clusters);
    free(stream->fat_chain);
    free(stream);
    return 0;
}
size_t file_read(void *ptr, size_t size, size_t nmemb, struct file_t *stream){
    if(ptr==NULL||size<1||nmemb<1||stream==NULL||stream->fat_chain==NULL||stream->fat_chain->clusters==NULL) {
        errno=EFAULT;
        return -1;
    }
    int curr_file_cluster;
    int curr_file_offset;
    size_t blocks_read=0;
    char* buffer=malloc(BYTES_PER_BLOCK*stream->volume->super->sectors_per_cluster*2);
    for(int i=0; i<(int)nmemb; i++) {
        if (stream->file_positon + (int)size > (int32_t)stream->file_info.size) {
            if(stream->file_positon==(int32_t)stream->file_info.size) {
                break;
            }
            file_read((char*)ptr+blocks_read*size, (int32_t)stream->file_info.size%(int)size, 1, stream);
            break;
        }
        curr_file_cluster = (int32_t)stream->file_positon / (512 * stream->volume->super->sectors_per_cluster);
        curr_file_offset = (int32_t)stream->file_positon % (512 * stream->volume->super->sectors_per_cluster);
        int cluster12bit = stream->fat_chain->clusters[curr_file_cluster];
        if(disk_read(stream->volume->pdisk, (int32_t )stream->volume->first_data_sector + (cluster12bit-2)*stream->volume->super->sectors_per_cluster, buffer, stream->volume->super->sectors_per_cluster) != 0){
            free(buffer);
            errno=ERANGE;
            return -1;
        }
        if(curr_file_cluster<=(int)(stream->fat_chain->size-2)&&disk_read(stream->volume->pdisk, (int32_t )stream->volume->first_data_sector + (stream->fat_chain->clusters[curr_file_cluster+1]-2)*stream->volume->super->sectors_per_cluster, (char*)buffer+BYTES_PER_BLOCK*stream->volume->super->sectors_per_cluster, stream->volume->super->sectors_per_cluster) != 0){
            free(buffer);
            errno=ERANGE;
            return -1;
        }
        memcpy((char*)ptr + i * size, buffer + curr_file_offset, size);
        stream->file_positon += (int32_t)size;
        blocks_read++;
    }
    free(buffer);
    return blocks_read;
}
int32_t file_seek(struct file_t* stream, int32_t offset, int whence){
    if(stream==NULL||stream->fat_chain==NULL||stream->fat_chain->clusters==NULL) {
        errno=EFAULT;
        return -1;
    }
    if(whence==SEEK_SET){
        if(offset<0||offset>(int)stream->file_info.size) {
            errno=ERANGE;
            return -1;
        }
        stream->file_positon=offset;
        return 0;
    }
    if(whence==SEEK_CUR){
        if(stream->file_positon+offset<0||stream->file_positon+offset>(int)stream->file_info.size) {
            errno=ERANGE;
            return -1;
        }
        stream->file_positon+=offset;
        return 0;
    }
    if(whence==SEEK_END){
        if(offset>0||offset+(int)stream->file_info.size<0) {
            errno=ERANGE;
            return -1;
        }
        stream->file_positon=stream->file_info.size+offset;
        return 0;
    }
    errno=EINVAL;
    return -1;
}





struct clusters_chain_t *get_chain_fat12(const void * const buffer, size_t size, uint16_t first_cluster){
    if(buffer==NULL||size<1) return NULL;
    struct clusters_chain_t* result=malloc(sizeof(struct clusters_chain_t));
    if(result==NULL) return NULL;
    int numberOfClusters=0;
    uint16_t *temp=realloc(NULL, sizeof(uint16_t)*++numberOfClusters);
    if(temp==NULL){
        free(result);
        return NULL;
    }
    result->clusters= temp;
    result->clusters[numberOfClusters-1]=first_cluster;
    uint16_t cluster12bit;
    if(result->clusters[numberOfClusters-1]%2==0){
        cluster12bit=*((uint8_t*)buffer+result->clusters[numberOfClusters-1]/2*3+1)&15u;
        cluster12bit<<=8;
        cluster12bit+=*((uint8_t*)buffer+result->clusters[numberOfClusters-1]/2*3);
    } else{
        cluster12bit=*((uint8_t*)buffer+result->clusters[numberOfClusters-1]/2*3+2);
        cluster12bit<<=4;
        cluster12bit+=*((uint8_t*)buffer+result->clusters[numberOfClusters-1]/2*3+1)>>4;
    }
    while(cluster12bit<4088){
        temp=realloc(result->clusters,sizeof(uint16_t)*++numberOfClusters);
        if(temp==NULL){
            free(result->clusters);
            free(result);
            return NULL;
        }
        result->clusters= temp;
        result->clusters[numberOfClusters-1]=cluster12bit;
        if(result->clusters[numberOfClusters-1]%2==0){
            cluster12bit=*((uint8_t*)buffer+result->clusters[numberOfClusters-1]/2*3+1)&15u;
            cluster12bit<<=8;
            cluster12bit+=*((uint8_t*)buffer+result->clusters[numberOfClusters-1]/2*3);
        } else{
            cluster12bit=*((uint8_t*)buffer+result->clusters[numberOfClusters-1]/2*3+2);
            cluster12bit<<=4;
            cluster12bit+=*((uint8_t*)buffer+result->clusters[numberOfClusters-1]/2*3+1)>>4;
        }
    }
    result->size=numberOfClusters;
    return result;
}


struct dir_entry_t *read_directory_entry(struct dir_entry_read_t *readToStruct){
    struct dir_entry_t* result= calloc(1,sizeof(struct dir_entry_t));
    if(result==NULL) return NULL;
    int length;
    for(length=0; length < 8; length++){
        if(*(readToStruct->name+length) == 32){
            break;
        }
    }
    strncat(result->name, readToStruct->name, length);
    int extension_len;
    for(extension_len=0;extension_len<3;extension_len++){
        if(*(readToStruct->extension+extension_len)==32){
            break;
        }
    }
    if(extension_len!=0){
        strcat(result->name,".");
        strncat(result->name,readToStruct->extension,extension_len);
    }
    result->is_archived=(readToStruct->attribute&FAT_ATTRIB_ARCHIVE)>>5;
    result->is_directory=(readToStruct->attribute&FAT_DIRECTORY)>>4;
    result->is_system=(readToStruct->attribute&FAT_ATTRIB_SYSTEM)>>2;
    result->is_hidden=(readToStruct->attribute&FAT_ATTRIB_HIDDEN)>>1;
    result->is_readonly=readToStruct->attribute&FAT_ATTRIB_READONLY;
    result->size=readToStruct->size;
    union little_endian_t temp;
    temp.bytes[0]=readToStruct->creation_date[0];
    temp.bytes[1]=readToStruct->creation_date[1];
    result->creation_date.year=(temp.whole>>9)+1980u;
    result->creation_date.month=(temp.whole>>5)&15u;
    result->creation_date.day=temp.whole&31u;
    temp.bytes[0]=readToStruct->creation_time[0];
    temp.bytes[1]=readToStruct->creation_time[1];
    result->creation_time.hour=temp.whole>>11;
    result->creation_time.minutes=(temp.whole>>5)&63u;
    result->creation_time.seconds=(temp.whole&31u)*2u;

    return result;
}

struct dir_t* dir_open(struct volume_t* pvolume, const char* dir_path){
    if (pvolume==NULL||pvolume->fat==NULL||pvolume->root_dir==NULL||pvolume->super==NULL||dir_path==NULL) {
        errno=EFAULT;
        return NULL;
    }
    struct dir_t* result=malloc(sizeof(struct dir_t));
    if(result==NULL) {
        errno=ENOMEM;
        return NULL;
    }
    if(strcmp(dir_path,"\\")!=0){
        free(result);
        errno=ENOENT;
        return 0;
    }
    result->dir_position=0;
    result->dir_size=pvolume->super->root_dir_capacity;
    result->dir_data=pvolume->root_dir;
    return result;
}
int dir_read(struct dir_t* pdir, struct dir_entry_t* pentry){
    if(pdir==NULL||pentry==NULL) {
        errno=EFAULT;
        return -1;
    }
    if(pdir->dir_position>=pdir->dir_size) {
        return 1;
    }
    struct dir_entry_t* dirEntry_temp=read_directory_entry((struct dir_entry_read_t*)pdir->dir_data+pdir->dir_position);
    if(dirEntry_temp==NULL) {
        errno=EIO;
        return -1;
    }
    pdir->dir_position++;
    if(((struct dir_entry_read_t*)pdir->dir_data+pdir->dir_position-1)->attribute&FAT_ATTRIB_VOLUME){
        free(dirEntry_temp);
        return dir_read(pdir,pentry);
    }
    if(((struct dir_entry_read_t*)pdir->dir_data+pdir->dir_position-1)->name[0]=='\0'){
        free(dirEntry_temp);
        return dir_read(pdir,pentry);
    }
    if(((struct dir_entry_read_t*)pdir->dir_data+pdir->dir_position-1)->name[0]==((char) 0xe5)){
        free(dirEntry_temp);
        return dir_read(pdir,pentry);
    }
    *pentry=*dirEntry_temp;
    free(dirEntry_temp);
    return 0;
}
int dir_close(struct dir_t* pdir){
    if(pdir==NULL) {
        errno=EFAULT;
        return -1;
    }
    free(pdir);
    return 0;
}




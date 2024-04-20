# FAT12
Simple fat12 reading system written in c

The aim of the project is to build a parser for file containers saved in the FAT12 format. In all three designs, these operations are limited to input only.

Opening, reading and closing a block device (in file form).
Opening and closing a FAT12 volume.
Opening, searching, reading and closing files in the FAT system.
Opening, reading and closing directories.
In this version of the project, operations are limited only to the main directory - operations on subdirectories are not implemented.

Files written by me are file_reader.c and file_reader.h, other files are provided by Politechnika Łódzka for testing and grading.

/*
 * Unit Test Bootstrap
 * Autor: Tomasz Jaworski, 2018-2020
 *
 * Test dla zadania Projekt: czytnik dysku, woluminu, katalogu głównego i plików (3,0)
 * Autor testowanej odpowiedzi: Piotr Ledwoch
 * Test wygenerowano automatycznie o 2024-01-29 20:49:44.973195
 *
 * Debug: 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <signal.h>
#include <setjmp.h>
#include <assert.h>

#if !defined(__clang__) && !defined(__GNUC__)
// Zakomentuj poniższy błąd, jeżeli chcesz przetestować testy na swoim kompilatorze C.
#error System testow jednostkowych jest przeznaczony dla kompilatorów GCC/Clang.
#endif

#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
// Zakomentuj poniższy błąd, jeżeli chcesz przetestować testy na platformie Windows.
#error System testow jednostkowych NIE jest przeznaczony dla testów uruchamianych na platformach Windows.
#endif

#define _RLDEBUG_API_
#include "unit_helper_v2.h"
#include "rdebug.h"

#include "tested_declarations.h"
#include "rdebug.h"

//
// Elementy globalne dla całego testu
//




//
//  Test 1: Sprawdzanie poprawności działania funkcji disk_open_from_file
//
void UTEST1(void)
{
    // informacje o teście
    test_start(1, "Sprawdzanie poprawności działania funkcji disk_open_from_file", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    


            struct disk_t* disk = disk_open_from_file("LOUD");
            test_error(disk == NULL, "Funkcja disk_open_from_file() powinna zwrócić NULL przy próbie otwarcia nieistniejącego pliku");

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 2: Sprawdzanie poprawności działania funkcji disk_open_from_file
//
void UTEST2(void)
{
    // informacje o teście
    test_start(2, "Sprawdzanie poprawności działania funkcji disk_open_from_file", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    


            struct disk_t* disk = disk_open_from_file(NULL);
            test_error(disk == NULL, "Funkcja disk_open_from_file() powinna zwrócić NULL przy próbie otwarcia nieistniejącego pliku");

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 3: Sprawdzanie poprawności działania funkcji disk_close
//
void UTEST3(void)
{
    // informacje o teście
    test_start(3, "Sprawdzanie poprawności działania funkcji disk_close", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    


            disk_close(NULL);
      
            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 4: Sprawdzanie poprawności działania funkcji fat_open
//
void UTEST4(void)
{
    // informacje o teście
    test_start(4, "Sprawdzanie poprawności działania funkcji fat_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    


            struct disk_t* disk = disk_open_from_file("while.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume == NULL, "Funkcja fat_open() powinna zwrócić NULL w przypadku przekazania błędnego obrazu dysku");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 5: Sprawdzanie poprawności działania funkcji disk_open_from_file
//
void UTEST5(void)
{
    // informacje o teście
    test_start(5, "Sprawdzanie poprawności działania funkcji disk_open_from_file", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct volume_t* volume = fat_open(NULL, 0);
            test_error(volume == NULL, "Funkcja fat_open() powinna zwrócić NULL w przypadku przekazania błędnego obrazu dysku");

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 6: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST6(void)
{
    // informacje o teście
    test_start(6, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(2046, 1);
                char expected_filecontent[2047] = "";
        
                strcat(expected_filecontent, "orthwith replied:\n\"If I have power to show one truth, soon that\nShall face thee, which thy questioning declares\nBehind thee now conceal\'d.  The Good, that guides\nAnd blessed makes this realm, which thou dost mount,\nOrdains its providence to be the virtue\nIn these great bodies: nor th\' all perfect Mind\nUpholds their nature merely, but in them\nTheir energy to save: for nought, that lies\nWithin the range of that unerring bow,\nBut is as level with the destin\'d aim,\nAs ever mark to arrow\'s point oppos\'d.\nWere it not thus, these heavens, thou dost visit,\nWould their effect so work, it would not be\nArt, but destruction; and this may not chance,\nIf th\' intellectual powers, that move these stars,\nFail not, or who, first faulty made them fail.\nWilt thou this truth more clearly evidenc\'d?\"\n     To whom I thus:  \"It is enough: no fear,\nI see, lest nature in her part should tire.\"\n     He straight rejoin\'d:  \"Say, were it worse for man,\nIf he liv\'d not in fellowship on earth?\"\n     \"Yea,\" answer\'d I;  \"nor here a reason needs.\"\n     \"And may that be, if different estates\nGrow not of different duties in your life?\nConsult your teacher, and he tells you \'no.\"\'\n     Thus did he come, deducing to this point,\nAnd then concluded:  \"For this cause behooves,\nThe roots, from whence your operations come,\nMust differ.  Therefore one is Solon born;\nAnother, Xerxes; and Melchisidec\nA third; and he a fourth, whose airy voyage\nCost him his son.  In her circuitous course,\nNature, that is the seal to mortal wax,\nDoth well her art, but no distinctions owns\n\'Twixt one or other household.  Hence befalls\nThat Esau is so wide of Jacob:  hence\nQuirinus of so base a father springs,\nHe dates from Mars his lineage.  Were it not\nThat providence celestial overrul\'d,\nNature, in generation, must the path\nTrac\'d by the generator, still pursue\nUnswervingly.  Thus place I in thy sight\nThat, which was late behind thee.  But, in sign\nOf more affection for thee, \'t is my will\nThou wear this corollary.  Nature ever\nFinding discordant fortune, like all seed\nOut");
                
        
                struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "MONEY.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 2046, file);
                test_error(size == 2046, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2046 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 2046);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 2046);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 7: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST7(void)
{
    // informacje o teście
    test_start(7, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(2572, 1);
                char expected_filecontent[2573] = "";
        
                strcat(expected_filecontent, "her form had scarce\nBeen known within a furnace of clear flame:\nThe next did look, as if the flesh and bones\nWere emerald: snow new-fallen seem\'d the third.\nNow seem\'d the white to lead, the ruddy now;\nAnd from her song who led, the others took\nTheir treasure, swift or slow.  At th\' other wheel,\nA band quaternion, each in purple clad,\nAdvanc\'d with festal step, as of them one\nThe rest conducted, one, upon whose front\nThree eyes were seen.  In rear of all this group,\nTwo old men I beheld, dissimilar\nIn raiment, but in port and gesture like,\nSolid and mainly grave; of whom the one\nDid show himself some favour\'d counsellor\nOf the great Coan, him, whom nature made\nTo serve the costliest creature of her tribe.\nHis fellow mark\'d an opposite intent,\nBearing a sword, whose glitterance and keen edge,\nE\'en as I view\'d it with the flood between,\nAppall\'d me.  Next four others I beheld,\nOf humble seeming: and, behind them all,\nOne single old man, sleeping, as he came,\nWith a shrewd visage.  And these seven, each\nLike the first troop were habited, hut wore\nNo braid of lilies on their temples wreath\'d.\nRather with roses and each vermeil flower,\nA sight, but little distant, might have sworn,\nThat they were all on fire above their brow.\n     Whenas the car was o\'er against me, straight.\nWas heard a thund\'ring, at whose voice it seem\'d\nThe chosen multitude were stay\'d; for there,\nWith the first ensigns, made they solemn halt.\n\n\n\nCANTO XXX\n\nSoon as the polar light, which never knows\nSetting nor rising, nor the shadowy veil\nOf other cloud than sin, fair ornament\nOf the first heav\'n, to duty each one there\nSafely convoying, as that lower doth\nThe steersman to his port, stood firmly fix\'d;\nForthwith the saintly tribe, who in the van\nBetween the Gryphon and its radiance came,\nDid turn them to the car, as to their rest:\nAnd one, as if commission\'d from above,\nIn holy chant thrice shorted forth aloud:\n\"Come, spouse, from Libanus!\" and all the rest\nTook up the song--At the last audit so\nThe blest shall rise, from forth his cavern each\nUplifting lightly his new-vested flesh,\nAs, on the sacred litter, at the voice\nAuthoritative of that elder, sprang\nA hundred ministers and messengers\nOf life eternal.  \"Blessed thou!  who com\'st!\"\nAnd, \"O,\" they cried, \"from full hands scatter ye\nUnwith\'ring lilies;\" and, so saying, cast\nFlowers over head and round them on all sides.\n     I have beheld, ere now, at break of day,\nThe eastern clime all roseate, and the sky\nOppos\'d, one deep and beautiful serene,\nAnd the sun\'s face so shaded, and with mists\nAttemper\'d at li");
                
        
                struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "SYSTEM.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 2572, file);
                test_error(size == 2572, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2572 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 2572);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 2572);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 8: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST8(void)
{
    // informacje o teście
    test_start(8, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(447, 1);
                char expected_filecontent[448] = "";
        
                strcat(expected_filecontent, "ights mov\'d a voice,\nThat made me seem like needle to the star,\nIn turning to its whereabout, and thus\nBegan:  \"The love, that makes me beautiful,\nPrompts me to tell of th\' other guide, for whom\nSuch good of mine is spoken.  Where one is,\nThe other worthily should also be;\nThat as their warfare was alike, alike\nShould be their glory.  Slow, and full of doubt,\nAnd with thin ranks, after its banner mov\'d\nThe army of Christ (which it so clearly c");
                
        
                struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "VERB.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 447, file);
                test_error(size == 447, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 447 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 447);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 447);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 9: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST9(void)
{
    // informacje o teście
    test_start(9, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(2120, 1);
                char expected_filecontent[2121] = "";
        
                strcat(expected_filecontent, "a in gazophylacium\ndomini mittere,\"\nv. 105.  The fifth light.]  Solomon.\n\nv. 112.  That taper\'s radiance.]  St. Dionysius the Areopagite.\n\"The famous Grecian fanatic, who gave himself out for Dionysius\nthe Areopagite, disciple of St. Paul, and who, under the\nprotection of this venerable name, gave laws and instructions to\nthose that were desirous of raising their souls above all human\nthings in order to unite them to their great source by sublime\ncontemplation, lived most probably in this century (the fourth),\nthough some place him before, others after, the present period.\"\nMaclaine\'s Mosheim, v. i. cent.  iv. p. 2. c. 3.  12.\n\nv. 116.  That pleader.]  1n the fifth century, Paulus Orosius,\n\"acquired a considerable degree of reputation by the History he\nwrote to refute the cavils of the Pagans against Christianity,\nand by his books against the Pelagians and Priscillianists.\"\nIbid.  v. ii. cent. v. p. 2.  c. 2. 11.  A similar train of\nargument was pursued by  Augustine, in his book De Civitate Dei.\nOrosius is classed by Dante, in his treatise De Vulg. Eloq.  I ii\nc. 6. as one of his favourite authors, among those \"qui usi sunt\naltissimas prosas,\"--\" who have written prose with the greatest\nloftiness of style.\"\n\nv. 119.  The eighth.]  Boetius, whose book De Consolatione\nPhilosophiae excited so much attention during the middle ages,\nwas born, as  Tiraboschi conjectures, about 470.  \"In 524 he was\ncruelly put to death by command of Theodoric, either on real or\npretended suspicion of his being engaged in a conspiracy.\" Della\nLett.  Ital. t. iii. 1. i. c. 4.\n\nv. 124.  Cieldauro.]  Boetius was buried at Pavia, in the\nmonastery of St. Pietro in Ciel d\'oro.\n\nv. 126.  Isidore.]  He was Archbishop of Seville during forty\nyears, and died in 635.  See Mariana, Hist. 1.  vi. c. 7.\nMosheim, whose critical opinions in general must be taken with\nsome allowance, observes that \"his grammatical theological, and\nhistorical productions, discover more learning and pedantry, than\njudgment and taste.\"\n\nv. 127.  Bede.]  Bede, whose virtues obtained him the appellation\nof the Venerable, was born in 672 at Wearm");
                
        
                struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "FAMOUS.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 2120, file);
                test_error(size == 2120, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2120 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 2120);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 2120);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 10: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST10(void)
{
    // informacje o teście
    test_start(10, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(3964, 1);
                char expected_filecontent[3965] = "";
        
                strcat(expected_filecontent, "     etext or this \"small print!\" statement.  You may however,\n     if you wish, distribute this etext in machine readable\n     binary, compressed, mark-up, or proprietary form,\n     including any form resulting from conversion by word pro-\n     cessing or hypertext software, but only so long as\n     *EITHER*:\n\n     [*]  The etext, when displayed, is clearly readable, and\n          does *not* contain characters other than those\n          intended by the author of the work, although tilde\n          (~), asterisk (*) and underline (_) characters may\n          be used to convey punctuation intended by the\n          author, and additional characters may be used to\n          indicate hypertext links; OR\n\n     [*]  The etext may be readily converted by the reader at\n          no expense into plain ASCII, EBCDIC or equivalent\n          form by the program that displays the etext (as is\n          the case, for instance, with most word processors);\n          OR\n\n     [*]  You provide, or agree to also provide on request at\n          no additional cost, fee or expense, a copy of the\n          etext in its original plain ASCII form (or in EBCDIC\n          or other equivalent proprietary form).\n\n[2]  Honor the etext refund and replacement provisions of this\n     \"Small Print!\" statement.\n\n[3]  Pay a trademark license fee to the Project of 20% of the\n     net profits you derive calculated using the method you\n     already use to calculate your applicable taxes.  If you\n     don\'t derive profits, no royalty is due.  Royalties are\n     payable to \"Project Gutenberg Association/Carnegie-Mellon\n     University\" within the 60 days following each\n     date you prepare (or were legally required to prepare)\n     your annual (or equivalent periodic) tax return.\n\nWHAT IF YOU *WANT* TO SEND MONEY EVEN IF YOU DON\'T HAVE TO?\nThe Project gratefully accepts contributions in money, time,\nscanning machines, OCR software, public domain etexts, royalty\nfree copyright licenses, and every other sort of contribution\nyou can think of.  Money should be paid to \"Project Gutenberg\nAssociation / Carnegie-Mellon University\".\n\n*END*THE SMALL PRINT! FOR PUBLIC DOMAIN ETEXTS*Ver.04.29.93*END*\n\n\n\n\n\nThis text was prepared for Project Gutenberg by Judith Smith and\nNatalie Salter.  We would also like to thank Montell Corporation\nInc., Sarnia plant, for the use of scanning equipment to\nfacilitate the preparation of this electronic text.\n\nJudith Smith\nheyjude@ebtech.net\n\n\n\n\n\nTHE VISION\nOR,\nHELL, PURGATORY, AND PARADISE\nOF\nDANTE ALIGHIERI\n\nTRANSLATED BY\nTHE REV. H. F. CARY, A.M.\n\n\n\n\n\nHELL\n\nCANTO I\n\nIN the midway of this our mortal life,\nI found me in a gloomy wood, astray\nGone from the path direct:  and e\'en to tell\nIt were no easy task, how savage wild\nThat forest, how robust and rough its growth,\nWhich to remember only, my dismay\nRenews, in bitterness not far from death.\nYet to discourse of what there good befell,\nAll else will I relate discover\'d there.\nHow first I enter\'d it I scarce can say,\nSuch sleepy dullness in that instant weigh\'d\nMy senses down, when the true path I left,\nBut when a mountain\'s foot I reach\'d, where clos\'d\nThe valley, that had pierc\'d my heart with dread,\nI look\'d aloft, and saw his shoulders broad\nAlready vested with that planet\'s beam,\nWho leads all wanderers safe through every way.\n     Then was a little respite to the fear,\nThat in my heart\'s recesses deep had lain,\nAll of that night, so pitifully pass\'d:\nAnd as a man, with difficult short breath,\nForespent with toiling, \'scap\'d from sea to shore,\nTurns to the perilous wide waste, and stands\nAt gaze; e\'en so my spirit, that yet fail\'d\nStruggling with terror, turn\'d to view the straits,\nThat none hath pass\'d and liv\'d.  My weary frame\nAfter short pause recomforted, again\nI journey\'d on over that lonely steep,\nThe hinder foot still firmer.  Scarce the ascent\nBegan, when, lo!  a panther, nimble, light,\nAnd cover\'d with a speckled skin, appear\'d,\nNor, when it saw m");
                
        
                struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "HUNT.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 3964, file);
                test_error(size == 3964, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3964 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 3964);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 3964);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 11: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST11(void)
{
    // informacje o teście
    test_start(11, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(3584, 1);
                char expected_filecontent[3585] = "";
        
                strcat(expected_filecontent, "s,\nI, as she bade, directed.  Never fire,\nWith so swift motion, forth a stormy cloud\nLeap\'d downward from the welkin\'s farthest bound,\nAs I beheld the bird of Jove descending\nPounce on the tree, and, as he rush\'d, the rind,\nDisparting crush beneath him, buds much more\nAnd leaflets.  On the car with all his might\nHe struck, whence, staggering like a ship, it reel\'d,\nAt random driv\'n, to starboard now, o\'ercome,\nAnd now to larboard, by the vaulting waves.\n     Next springing up into the chariot\'s womb\nA fox I saw, with hunger seeming pin\'d\nOf all good food.  But, for his ugly sins\nThe saintly maid rebuking him, away\nScamp\'ring he turn\'d, fast as his hide-bound corpse\nWould bear him.  Next, from whence before he came,\nI saw the eagle dart into the hull\nO\' th\' car, and leave it with his feathers lin\'d;\nAnd then a voice, like that which issues forth\nFrom heart with sorrow riv\'d, did issue forth\nFrom heav\'n, and, \"O poor bark of mine!\" it cried,\n\"How badly art thou freighted!\"  Then, it seem\'d,\nThat the earth open\'d between either wheel,\nAnd I beheld a dragon issue thence,\nThat through the chariot fix\'d his forked train;\nAnd like a wasp that draggeth back the sting,\nSo drawing forth his baleful train, he dragg\'d\nPart of the bottom forth, and went his way\nExulting.  What remain\'d, as lively turf\nWith green herb, so did clothe itself with plumes,\nWhich haply had with purpose chaste and kind\nBeen offer\'d; and therewith were cloth\'d the wheels,\nBoth one and other, and the beam, so quickly\nA sigh were not breath\'d sooner.  Thus transform\'d,\nThe holy structure, through its several parts,\nDid put forth heads, three on the beam, and one\nOn every side; the first like oxen horn\'d,\nBut with a single horn upon their front\nThe four.  Like monster sight hath never seen.\nO\'er it methought there sat, secure as rock\nOn mountain\'s lofty top, a shameless whore,\nWhose ken rov\'d loosely round her.  At her side,\nAs \'t were that none might bear her off, I saw\nA giant stand; and ever, and anon\nThey mingled kisses.  But, her lustful eyes\nChancing on me to wander, that fell minion\nScourg\'d her from head to foot all o\'er; then full\nOf jealousy, and fierce with rage, unloos\'d\nThe monster, and dragg\'d on, so far across\nThe forest, that from me its shades alone\nShielded the harlot and the new-form\'d brute.\n\n\n\nCANTO XXXIII\n\n\"The heathen, Lord!  are come!\" responsive thus,\nThe trinal now, and now the virgin band\nQuaternion, their sweet psalmody began,\nWeeping; and Beatrice listen\'d, sad\nAnd sighing, to the song\', in such a mood,\nThat Mary, as she stood beside the cross,\nWas scarce more chang\'d.  But when they gave her place\nTo speak, then, risen upright on her feet,\nShe, with a colour glowing bright as fire,\nDid answer: \"Yet a little while, and ye\nShall see me not; and, my beloved sisters,\nAgain a little while, and ye shall see me.\"\n     Before her then she marshall\'d all the seven,\nAnd, beck\'ning only motion\'d me, the dame,\nAnd that remaining sage, to follow her.\n     So on she pass\'d; and had not set, I ween,\nHer tenth step to the ground, when with mine eyes\nHer eyes encounter\'d; and, with visage mild,\n\"So mend thy pace,\" she cried, \"that if my words\nAddress thee, thou mayst still be aptly plac\'d\nTo hear them.\"  Soon as duly to her side\nI now had hasten\'d:  \"Brother!\" she began,\n\"Why mak\'st thou no attempt at questioning,\nAs thus we walk together?\"  Like to those\nWho, speaking with too reverent an awe\nBefore their betters, draw not forth the voice\nAlive unto their lips, befell me shell\nThat I in sounds imperfect thus began:\n\"Lady!  what I have need of, t");
                
        
                struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "PREPARE.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 3584, file);
                test_error(size == 3584, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3584 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 3584);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 3584);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 12: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST12(void)
{
    // informacje o teście
    test_start(12, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(3670, 1);
                char expected_filecontent[3671] = "";
        
                strcat(expected_filecontent, " unmerited calamity and disgrace,\nhe put an end to his life by dashing out his brains against the\nwalls of a church, in the year 1245.  Both Frederick and Pietro\ndelle Vigne composed verses in the Sicilian dialect which are yet\nextant.\n\nv. 67.  The harlot.]  Envy.  Chaucer alludes to this in the\nPrologue to the Legende of Good women.\n        Envie is lavender to the court alway,\n        For she ne parteth neither night ne day\n        Out of the house of Cesar; thus saith Dant.\n\nv. 119.  Each fan o\' th\' wood.]  Hence perhaps Milton:\n        Leaves and fuming rills, Aurora\'s fan.\n               P. L. b. v. 6.\n\nv. 122.  Lano.]  Lano, a Siennese, who, being reduced by\nprodigality to a state of extreme want, found his existence no\nlonger supportable; and, having been sent by his countrymen on a\nmilitary expedition, to assist the Florentine against the\nAretini, took that opportunity of exposing himself to certain\ndeath, in the engagement which took place at Toppo near Arezzo.\nSee G. Villani, Hist. l. 7. c. cxix.\n\nv. 133.               O Giocomo\n        Of Sant\' Andrea!]\nJacopo da Sant\' Andrea, a Paduan, who, having wasted his property\nin the most wanton acts of profusion, killed himself in despair.\nv. 144.  In that City.]  \"I was an inhabitant of Florence, that\ncity which changed her first patron Mars for St. John the\nBaptist, for which reason the vengeance of the deity thus\nslighted will never be appeased:  and, if some remains of his\nstatus were not still visible on the bridge over the Arno, she\nwould have been already leveled to the ground; and thus the\ncitizens, who raised her again from the ashes to which Attila had\nreduced her, would have laboured in vain.\"  See Paradise, Canto\nXVI. 44.\nThe relic of antiquity to which the superstition of Florence\nattached so high an importance, was carried away by a flood, that\ndestroyed the bridge on which it stood, in the year 1337, but\nwithout the ill effects that were apprehended from the loss of\ntheir fancied Palladium.\n\nv. 152.  I slung the fatal noose.]  We are not informed who this\nsuicide was.\n\n\nCANTO XIV\n\nv. 15.  By Cato\'s foot.]  See Lucan, Phars, l. 9.\n\nv. 26. Dilated flakes of fire.]  Compare Tasso.  G. L. c. x. st.\n61.\n\nv. 28.  As, in the torrid Indian clime.]  Landino refers to\nAlbertus Magnus for the circumstance here alluded to.\n\nv. 53.  In Mongibello.]\n        More hot than Aetn\' or flaming Mongibell.\n               Spenser, F. Q. b. ii. c. ix. st. 29.\nSee Virg. Aen. 1. viii. 416. and Berni. Orl. Inn 1. i. c. xvi.\nst. 21.  It would be endless to refer to parallel passages in the\nGreek writers.\n\nv. 64.  This of the seven kings was one.]  Compare Aesch.  Seven\nChiefs, 425.  Euripides, Phoen. 1179 and Statius. Theb. l. x.\n821.\n\nv. 76.  Bulicame.]  A warm medicinal spring near Viterbo, the\nwaters of which, as Landino and Vellutelli affirm, passed by a\nplace of ill fame.  Venturi, with less probability, conjectures\nthat Dante would imply, that it was the scene of much licentious\nmerriment among those who frequented its baths.\n\nv. 91.  Under whose monarch.]\n        Credo pudicitiam Saturno rege moratam\n        In terris.\n               Juv. Satir. vi.\n\nv. 102.  His head.]  Daniel, ch. ii. 32, 33.\n\nv. 133.  Whither.] On the other side of Purgatory.\n\nCANTO XV\n\n v. 10.  Chiarentana.]  A part of the Alps where the Brenta\nrises, which river is much swoln as soon as the snow begins to\ndissolve on the mountains.\n\nv. 28.  Brunetto.]  \"Ser Brunetto, a Florentine, the secretary or\nchancellor of the city, and Dante\'s preceptor, hath left us a\nwork so little read, that both the subject of it and the language\nof it have been mistaken.  It is in the French spoken in the\nr");
                
        
                struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "COMPLETE.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 3670, file);
                test_error(size == 3670, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3670 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 3670);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 3670);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 13: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST13(void)
{
    // informacje o teście
    test_start(13, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(2046, 1);
                char expected_filecontent[2047] = "";

                strcat(expected_filecontent, "orthwith replied:\n\"If I have power to show one truth, soon that\nShall face thee, which thy questioning declares\nBehind thee now conceal\'d.  The Good, that guides\nAnd blessed makes this realm, which thou dost mount,\nOrdains its providence to be the virtue\nIn these great bodies: nor th\' all perfect Mind\nUpholds their nature merely, but in them\nTheir energy to save: for nought, that lies\nWithin the range of that unerring bow,\nBut is as level with the destin\'d aim,\nAs ever mark to arrow\'s point oppos\'d.\nWere it not thus, these heavens, thou dost visit,\nWould their effect so work, it would not be\nArt, but destruction; and this may not chance,\nIf th\' intellectual powers, that move these stars,\nFail not, or who, first faulty made them fail.\nWilt thou this truth more clearly evidenc\'d?\"\n     To whom I thus:  \"It is enough: no fear,\nI see, lest nature in her part should tire.\"\n     He straight rejoin\'d:  \"Say, were it worse for man,\nIf he liv\'d not in fellowship on earth?\"\n     \"Yea,\" answer\'d I;  \"nor here a reason needs.\"\n     \"And may that be, if different estates\nGrow not of different duties in your life?\nConsult your teacher, and he tells you \'no.\"\'\n     Thus did he come, deducing to this point,\nAnd then concluded:  \"For this cause behooves,\nThe roots, from whence your operations come,\nMust differ.  Therefore one is Solon born;\nAnother, Xerxes; and Melchisidec\nA third; and he a fourth, whose airy voyage\nCost him his son.  In her circuitous course,\nNature, that is the seal to mortal wax,\nDoth well her art, but no distinctions owns\n\'Twixt one or other household.  Hence befalls\nThat Esau is so wide of Jacob:  hence\nQuirinus of so base a father springs,\nHe dates from Mars his lineage.  Were it not\nThat providence celestial overrul\'d,\nNature, in generation, must the path\nTrac\'d by the generator, still pursue\nUnswervingly.  Thus place I in thy sight\nThat, which was late behind thee.  But, in sign\nOf more affection for thee, \'t is my will\nThou wear this corollary.  Nature ever\nFinding discordant fortune, like all seed\nOut");

                struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "MONEY.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 2346, file);
                test_error(size == 2046, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2046 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 2046);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 2046);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 14: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST14(void)
{
    // informacje o teście
    test_start(14, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(2572, 1);
                char expected_filecontent[2573] = "";

                strcat(expected_filecontent, "her form had scarce\nBeen known within a furnace of clear flame:\nThe next did look, as if the flesh and bones\nWere emerald: snow new-fallen seem\'d the third.\nNow seem\'d the white to lead, the ruddy now;\nAnd from her song who led, the others took\nTheir treasure, swift or slow.  At th\' other wheel,\nA band quaternion, each in purple clad,\nAdvanc\'d with festal step, as of them one\nThe rest conducted, one, upon whose front\nThree eyes were seen.  In rear of all this group,\nTwo old men I beheld, dissimilar\nIn raiment, but in port and gesture like,\nSolid and mainly grave; of whom the one\nDid show himself some favour\'d counsellor\nOf the great Coan, him, whom nature made\nTo serve the costliest creature of her tribe.\nHis fellow mark\'d an opposite intent,\nBearing a sword, whose glitterance and keen edge,\nE\'en as I view\'d it with the flood between,\nAppall\'d me.  Next four others I beheld,\nOf humble seeming: and, behind them all,\nOne single old man, sleeping, as he came,\nWith a shrewd visage.  And these seven, each\nLike the first troop were habited, hut wore\nNo braid of lilies on their temples wreath\'d.\nRather with roses and each vermeil flower,\nA sight, but little distant, might have sworn,\nThat they were all on fire above their brow.\n     Whenas the car was o\'er against me, straight.\nWas heard a thund\'ring, at whose voice it seem\'d\nThe chosen multitude were stay\'d; for there,\nWith the first ensigns, made they solemn halt.\n\n\n\nCANTO XXX\n\nSoon as the polar light, which never knows\nSetting nor rising, nor the shadowy veil\nOf other cloud than sin, fair ornament\nOf the first heav\'n, to duty each one there\nSafely convoying, as that lower doth\nThe steersman to his port, stood firmly fix\'d;\nForthwith the saintly tribe, who in the van\nBetween the Gryphon and its radiance came,\nDid turn them to the car, as to their rest:\nAnd one, as if commission\'d from above,\nIn holy chant thrice shorted forth aloud:\n\"Come, spouse, from Libanus!\" and all the rest\nTook up the song--At the last audit so\nThe blest shall rise, from forth his cavern each\nUplifting lightly his new-vested flesh,\nAs, on the sacred litter, at the voice\nAuthoritative of that elder, sprang\nA hundred ministers and messengers\nOf life eternal.  \"Blessed thou!  who com\'st!\"\nAnd, \"O,\" they cried, \"from full hands scatter ye\nUnwith\'ring lilies;\" and, so saying, cast\nFlowers over head and round them on all sides.\n     I have beheld, ere now, at break of day,\nThe eastern clime all roseate, and the sky\nOppos\'d, one deep and beautiful serene,\nAnd the sun\'s face so shaded, and with mists\nAttemper\'d at li");

                struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "SYSTEM.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 3030, file);
                test_error(size == 2572, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2572 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 2572);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 2572);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 15: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST15(void)
{
    // informacje o teście
    test_start(15, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(447, 1);
                char expected_filecontent[448] = "";

                strcat(expected_filecontent, "ights mov\'d a voice,\nThat made me seem like needle to the star,\nIn turning to its whereabout, and thus\nBegan:  \"The love, that makes me beautiful,\nPrompts me to tell of th\' other guide, for whom\nSuch good of mine is spoken.  Where one is,\nThe other worthily should also be;\nThat as their warfare was alike, alike\nShould be their glory.  Slow, and full of doubt,\nAnd with thin ranks, after its banner mov\'d\nThe army of Christ (which it so clearly c");

                struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "VERB.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 886, file);
                test_error(size == 447, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 447 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 447);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 447);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 16: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST16(void)
{
    // informacje o teście
    test_start(16, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(2120, 1);
                char expected_filecontent[2121] = "";

                strcat(expected_filecontent, "a in gazophylacium\ndomini mittere,\"\nv. 105.  The fifth light.]  Solomon.\n\nv. 112.  That taper\'s radiance.]  St. Dionysius the Areopagite.\n\"The famous Grecian fanatic, who gave himself out for Dionysius\nthe Areopagite, disciple of St. Paul, and who, under the\nprotection of this venerable name, gave laws and instructions to\nthose that were desirous of raising their souls above all human\nthings in order to unite them to their great source by sublime\ncontemplation, lived most probably in this century (the fourth),\nthough some place him before, others after, the present period.\"\nMaclaine\'s Mosheim, v. i. cent.  iv. p. 2. c. 3.  12.\n\nv. 116.  That pleader.]  1n the fifth century, Paulus Orosius,\n\"acquired a considerable degree of reputation by the History he\nwrote to refute the cavils of the Pagans against Christianity,\nand by his books against the Pelagians and Priscillianists.\"\nIbid.  v. ii. cent. v. p. 2.  c. 2. 11.  A similar train of\nargument was pursued by  Augustine, in his book De Civitate Dei.\nOrosius is classed by Dante, in his treatise De Vulg. Eloq.  I ii\nc. 6. as one of his favourite authors, among those \"qui usi sunt\naltissimas prosas,\"--\" who have written prose with the greatest\nloftiness of style.\"\n\nv. 119.  The eighth.]  Boetius, whose book De Consolatione\nPhilosophiae excited so much attention during the middle ages,\nwas born, as  Tiraboschi conjectures, about 470.  \"In 524 he was\ncruelly put to death by command of Theodoric, either on real or\npretended suspicion of his being engaged in a conspiracy.\" Della\nLett.  Ital. t. iii. 1. i. c. 4.\n\nv. 124.  Cieldauro.]  Boetius was buried at Pavia, in the\nmonastery of St. Pietro in Ciel d\'oro.\n\nv. 126.  Isidore.]  He was Archbishop of Seville during forty\nyears, and died in 635.  See Mariana, Hist. 1.  vi. c. 7.\nMosheim, whose critical opinions in general must be taken with\nsome allowance, observes that \"his grammatical theological, and\nhistorical productions, discover more learning and pedantry, than\njudgment and taste.\"\n\nv. 127.  Bede.]  Bede, whose virtues obtained him the appellation\nof the Venerable, was born in 672 at Wearm");

                struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "FAMOUS.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 2454, file);
                test_error(size == 2120, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2120 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 2120);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 2120);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 17: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST17(void)
{
    // informacje o teście
    test_start(17, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(3964, 1);
                char expected_filecontent[3965] = "";

                strcat(expected_filecontent, "     etext or this \"small print!\" statement.  You may however,\n     if you wish, distribute this etext in machine readable\n     binary, compressed, mark-up, or proprietary form,\n     including any form resulting from conversion by word pro-\n     cessing or hypertext software, but only so long as\n     *EITHER*:\n\n     [*]  The etext, when displayed, is clearly readable, and\n          does *not* contain characters other than those\n          intended by the author of the work, although tilde\n          (~), asterisk (*) and underline (_) characters may\n          be used to convey punctuation intended by the\n          author, and additional characters may be used to\n          indicate hypertext links; OR\n\n     [*]  The etext may be readily converted by the reader at\n          no expense into plain ASCII, EBCDIC or equivalent\n          form by the program that displays the etext (as is\n          the case, for instance, with most word processors);\n          OR\n\n     [*]  You provide, or agree to also provide on request at\n          no additional cost, fee or expense, a copy of the\n          etext in its original plain ASCII form (or in EBCDIC\n          or other equivalent proprietary form).\n\n[2]  Honor the etext refund and replacement provisions of this\n     \"Small Print!\" statement.\n\n[3]  Pay a trademark license fee to the Project of 20% of the\n     net profits you derive calculated using the method you\n     already use to calculate your applicable taxes.  If you\n     don\'t derive profits, no royalty is due.  Royalties are\n     payable to \"Project Gutenberg Association/Carnegie-Mellon\n     University\" within the 60 days following each\n     date you prepare (or were legally required to prepare)\n     your annual (or equivalent periodic) tax return.\n\nWHAT IF YOU *WANT* TO SEND MONEY EVEN IF YOU DON\'T HAVE TO?\nThe Project gratefully accepts contributions in money, time,\nscanning machines, OCR software, public domain etexts, royalty\nfree copyright licenses, and every other sort of contribution\nyou can think of.  Money should be paid to \"Project Gutenberg\nAssociation / Carnegie-Mellon University\".\n\n*END*THE SMALL PRINT! FOR PUBLIC DOMAIN ETEXTS*Ver.04.29.93*END*\n\n\n\n\n\nThis text was prepared for Project Gutenberg by Judith Smith and\nNatalie Salter.  We would also like to thank Montell Corporation\nInc., Sarnia plant, for the use of scanning equipment to\nfacilitate the preparation of this electronic text.\n\nJudith Smith\nheyjude@ebtech.net\n\n\n\n\n\nTHE VISION\nOR,\nHELL, PURGATORY, AND PARADISE\nOF\nDANTE ALIGHIERI\n\nTRANSLATED BY\nTHE REV. H. F. CARY, A.M.\n\n\n\n\n\nHELL\n\nCANTO I\n\nIN the midway of this our mortal life,\nI found me in a gloomy wood, astray\nGone from the path direct:  and e\'en to tell\nIt were no easy task, how savage wild\nThat forest, how robust and rough its growth,\nWhich to remember only, my dismay\nRenews, in bitterness not far from death.\nYet to discourse of what there good befell,\nAll else will I relate discover\'d there.\nHow first I enter\'d it I scarce can say,\nSuch sleepy dullness in that instant weigh\'d\nMy senses down, when the true path I left,\nBut when a mountain\'s foot I reach\'d, where clos\'d\nThe valley, that had pierc\'d my heart with dread,\nI look\'d aloft, and saw his shoulders broad\nAlready vested with that planet\'s beam,\nWho leads all wanderers safe through every way.\n     Then was a little respite to the fear,\nThat in my heart\'s recesses deep had lain,\nAll of that night, so pitifully pass\'d:\nAnd as a man, with difficult short breath,\nForespent with toiling, \'scap\'d from sea to shore,\nTurns to the perilous wide waste, and stands\nAt gaze; e\'en so my spirit, that yet fail\'d\nStruggling with terror, turn\'d to view the straits,\nThat none hath pass\'d and liv\'d.  My weary frame\nAfter short pause recomforted, again\nI journey\'d on over that lonely steep,\nThe hinder foot still firmer.  Scarce the ascent\nBegan, when, lo!  a panther, nimble, light,\nAnd cover\'d with a speckled skin, appear\'d,\nNor, when it saw m");

                struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "HUNT.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 4237, file);
                test_error(size == 3964, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3964 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 3964);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 3964);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 18: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST18(void)
{
    // informacje o teście
    test_start(18, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(3584, 1);
                char expected_filecontent[3585] = "";

                strcat(expected_filecontent, "s,\nI, as she bade, directed.  Never fire,\nWith so swift motion, forth a stormy cloud\nLeap\'d downward from the welkin\'s farthest bound,\nAs I beheld the bird of Jove descending\nPounce on the tree, and, as he rush\'d, the rind,\nDisparting crush beneath him, buds much more\nAnd leaflets.  On the car with all his might\nHe struck, whence, staggering like a ship, it reel\'d,\nAt random driv\'n, to starboard now, o\'ercome,\nAnd now to larboard, by the vaulting waves.\n     Next springing up into the chariot\'s womb\nA fox I saw, with hunger seeming pin\'d\nOf all good food.  But, for his ugly sins\nThe saintly maid rebuking him, away\nScamp\'ring he turn\'d, fast as his hide-bound corpse\nWould bear him.  Next, from whence before he came,\nI saw the eagle dart into the hull\nO\' th\' car, and leave it with his feathers lin\'d;\nAnd then a voice, like that which issues forth\nFrom heart with sorrow riv\'d, did issue forth\nFrom heav\'n, and, \"O poor bark of mine!\" it cried,\n\"How badly art thou freighted!\"  Then, it seem\'d,\nThat the earth open\'d between either wheel,\nAnd I beheld a dragon issue thence,\nThat through the chariot fix\'d his forked train;\nAnd like a wasp that draggeth back the sting,\nSo drawing forth his baleful train, he dragg\'d\nPart of the bottom forth, and went his way\nExulting.  What remain\'d, as lively turf\nWith green herb, so did clothe itself with plumes,\nWhich haply had with purpose chaste and kind\nBeen offer\'d; and therewith were cloth\'d the wheels,\nBoth one and other, and the beam, so quickly\nA sigh were not breath\'d sooner.  Thus transform\'d,\nThe holy structure, through its several parts,\nDid put forth heads, three on the beam, and one\nOn every side; the first like oxen horn\'d,\nBut with a single horn upon their front\nThe four.  Like monster sight hath never seen.\nO\'er it methought there sat, secure as rock\nOn mountain\'s lofty top, a shameless whore,\nWhose ken rov\'d loosely round her.  At her side,\nAs \'t were that none might bear her off, I saw\nA giant stand; and ever, and anon\nThey mingled kisses.  But, her lustful eyes\nChancing on me to wander, that fell minion\nScourg\'d her from head to foot all o\'er; then full\nOf jealousy, and fierce with rage, unloos\'d\nThe monster, and dragg\'d on, so far across\nThe forest, that from me its shades alone\nShielded the harlot and the new-form\'d brute.\n\n\n\nCANTO XXXIII\n\n\"The heathen, Lord!  are come!\" responsive thus,\nThe trinal now, and now the virgin band\nQuaternion, their sweet psalmody began,\nWeeping; and Beatrice listen\'d, sad\nAnd sighing, to the song\', in such a mood,\nThat Mary, as she stood beside the cross,\nWas scarce more chang\'d.  But when they gave her place\nTo speak, then, risen upright on her feet,\nShe, with a colour glowing bright as fire,\nDid answer: \"Yet a little while, and ye\nShall see me not; and, my beloved sisters,\nAgain a little while, and ye shall see me.\"\n     Before her then she marshall\'d all the seven,\nAnd, beck\'ning only motion\'d me, the dame,\nAnd that remaining sage, to follow her.\n     So on she pass\'d; and had not set, I ween,\nHer tenth step to the ground, when with mine eyes\nHer eyes encounter\'d; and, with visage mild,\n\"So mend thy pace,\" she cried, \"that if my words\nAddress thee, thou mayst still be aptly plac\'d\nTo hear them.\"  Soon as duly to her side\nI now had hasten\'d:  \"Brother!\" she began,\n\"Why mak\'st thou no attempt at questioning,\nAs thus we walk together?\"  Like to those\nWho, speaking with too reverent an awe\nBefore their betters, draw not forth the voice\nAlive unto their lips, befell me shell\nThat I in sounds imperfect thus began:\n\"Lady!  what I have need of, t");

                struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "PREPARE.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 3802, file);
                test_error(size == 3584, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3584 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 3584);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 3584);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 19: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST19(void)
{
    // informacje o teście
    test_start(19, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(3670, 1);
                char expected_filecontent[3671] = "";

                strcat(expected_filecontent, " unmerited calamity and disgrace,\nhe put an end to his life by dashing out his brains against the\nwalls of a church, in the year 1245.  Both Frederick and Pietro\ndelle Vigne composed verses in the Sicilian dialect which are yet\nextant.\n\nv. 67.  The harlot.]  Envy.  Chaucer alludes to this in the\nPrologue to the Legende of Good women.\n        Envie is lavender to the court alway,\n        For she ne parteth neither night ne day\n        Out of the house of Cesar; thus saith Dant.\n\nv. 119.  Each fan o\' th\' wood.]  Hence perhaps Milton:\n        Leaves and fuming rills, Aurora\'s fan.\n               P. L. b. v. 6.\n\nv. 122.  Lano.]  Lano, a Siennese, who, being reduced by\nprodigality to a state of extreme want, found his existence no\nlonger supportable; and, having been sent by his countrymen on a\nmilitary expedition, to assist the Florentine against the\nAretini, took that opportunity of exposing himself to certain\ndeath, in the engagement which took place at Toppo near Arezzo.\nSee G. Villani, Hist. l. 7. c. cxix.\n\nv. 133.               O Giocomo\n        Of Sant\' Andrea!]\nJacopo da Sant\' Andrea, a Paduan, who, having wasted his property\nin the most wanton acts of profusion, killed himself in despair.\nv. 144.  In that City.]  \"I was an inhabitant of Florence, that\ncity which changed her first patron Mars for St. John the\nBaptist, for which reason the vengeance of the deity thus\nslighted will never be appeased:  and, if some remains of his\nstatus were not still visible on the bridge over the Arno, she\nwould have been already leveled to the ground; and thus the\ncitizens, who raised her again from the ashes to which Attila had\nreduced her, would have laboured in vain.\"  See Paradise, Canto\nXVI. 44.\nThe relic of antiquity to which the superstition of Florence\nattached so high an importance, was carried away by a flood, that\ndestroyed the bridge on which it stood, in the year 1337, but\nwithout the ill effects that were apprehended from the loss of\ntheir fancied Palladium.\n\nv. 152.  I slung the fatal noose.]  We are not informed who this\nsuicide was.\n\n\nCANTO XIV\n\nv. 15.  By Cato\'s foot.]  See Lucan, Phars, l. 9.\n\nv. 26. Dilated flakes of fire.]  Compare Tasso.  G. L. c. x. st.\n61.\n\nv. 28.  As, in the torrid Indian clime.]  Landino refers to\nAlbertus Magnus for the circumstance here alluded to.\n\nv. 53.  In Mongibello.]\n        More hot than Aetn\' or flaming Mongibell.\n               Spenser, F. Q. b. ii. c. ix. st. 29.\nSee Virg. Aen. 1. viii. 416. and Berni. Orl. Inn 1. i. c. xvi.\nst. 21.  It would be endless to refer to parallel passages in the\nGreek writers.\n\nv. 64.  This of the seven kings was one.]  Compare Aesch.  Seven\nChiefs, 425.  Euripides, Phoen. 1179 and Statius. Theb. l. x.\n821.\n\nv. 76.  Bulicame.]  A warm medicinal spring near Viterbo, the\nwaters of which, as Landino and Vellutelli affirm, passed by a\nplace of ill fame.  Venturi, with less probability, conjectures\nthat Dante would imply, that it was the scene of much licentious\nmerriment among those who frequented its baths.\n\nv. 91.  Under whose monarch.]\n        Credo pudicitiam Saturno rege moratam\n        In terris.\n               Juv. Satir. vi.\n\nv. 102.  His head.]  Daniel, ch. ii. 32, 33.\n\nv. 133.  Whither.] On the other side of Purgatory.\n\nCANTO XV\n\n v. 10.  Chiarentana.]  A part of the Alps where the Brenta\nrises, which river is much swoln as soon as the snow begins to\ndissolve on the mountains.\n\nv. 28.  Brunetto.]  \"Ser Brunetto, a Florentine, the secretary or\nchancellor of the city, and Dante\'s preceptor, hath left us a\nwork so little read, that both the subject of it and the language\nof it have been mistaken.  It is in the French spoken in the\nr");

                struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "COMPLETE.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 4055, file);
                test_error(size == 3670, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3670 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 3670);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 3670);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 20: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST20(void)
{
    // informacje o teście
    test_start(20, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[2047] = "";

                strcat(expected_filecontent, "orthwith replied:\n\"If I have power to show one truth, soon that\nShall face thee, which thy questioning declares\nBehind thee now conceal\'d.  The Good, that guides\nAnd blessed makes this realm, which thou dost mount,\nOrdains its providence to be the virtue\nIn these great bodies: nor th\' all perfect Mind\nUpholds their nature merely, but in them\nTheir energy to save: for nought, that lies\nWithin the range of that unerring bow,\nBut is as level with the destin\'d aim,\nAs ever mark to arrow\'s point oppos\'d.\nWere it not thus, these heavens, thou dost visit,\nWould their effect so work, it would not be\nArt, but destruction; and this may not chance,\nIf th\' intellectual powers, that move these stars,\nFail not, or who, first faulty made them fail.\nWilt thou this truth more clearly evidenc\'d?\"\n     To whom I thus:  \"It is enough: no fear,\nI see, lest nature in her part should tire.\"\n     He straight rejoin\'d:  \"Say, were it worse for man,\nIf he liv\'d not in fellowship on earth?\"\n     \"Yea,\" answer\'d I;  \"nor here a reason needs.\"\n     \"And may that be, if different estates\nGrow not of different duties in your life?\nConsult your teacher, and he tells you \'no.\"\'\n     Thus did he come, deducing to this point,\nAnd then concluded:  \"For this cause behooves,\nThe roots, from whence your operations come,\nMust differ.  Therefore one is Solon born;\nAnother, Xerxes; and Melchisidec\nA third; and he a fourth, whose airy voyage\nCost him his son.  In her circuitous course,\nNature, that is the seal to mortal wax,\nDoth well her art, but no distinctions owns\n\'Twixt one or other household.  Hence befalls\nThat Esau is so wide of Jacob:  hence\nQuirinus of so base a father springs,\nHe dates from Mars his lineage.  Were it not\nThat providence celestial overrul\'d,\nNature, in generation, must the path\nTrac\'d by the generator, still pursue\nUnswervingly.  Thus place I in thy sight\nThat, which was late behind thee.  But, in sign\nOf more affection for thee, \'t is my will\nThou wear this corollary.  Nature ever\nFinding discordant fortune, like all seed\nOut");

                struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "MONEY.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 2046; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 21: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST21(void)
{
    // informacje o teście
    test_start(21, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[2573] = "";

                strcat(expected_filecontent, "her form had scarce\nBeen known within a furnace of clear flame:\nThe next did look, as if the flesh and bones\nWere emerald: snow new-fallen seem\'d the third.\nNow seem\'d the white to lead, the ruddy now;\nAnd from her song who led, the others took\nTheir treasure, swift or slow.  At th\' other wheel,\nA band quaternion, each in purple clad,\nAdvanc\'d with festal step, as of them one\nThe rest conducted, one, upon whose front\nThree eyes were seen.  In rear of all this group,\nTwo old men I beheld, dissimilar\nIn raiment, but in port and gesture like,\nSolid and mainly grave; of whom the one\nDid show himself some favour\'d counsellor\nOf the great Coan, him, whom nature made\nTo serve the costliest creature of her tribe.\nHis fellow mark\'d an opposite intent,\nBearing a sword, whose glitterance and keen edge,\nE\'en as I view\'d it with the flood between,\nAppall\'d me.  Next four others I beheld,\nOf humble seeming: and, behind them all,\nOne single old man, sleeping, as he came,\nWith a shrewd visage.  And these seven, each\nLike the first troop were habited, hut wore\nNo braid of lilies on their temples wreath\'d.\nRather with roses and each vermeil flower,\nA sight, but little distant, might have sworn,\nThat they were all on fire above their brow.\n     Whenas the car was o\'er against me, straight.\nWas heard a thund\'ring, at whose voice it seem\'d\nThe chosen multitude were stay\'d; for there,\nWith the first ensigns, made they solemn halt.\n\n\n\nCANTO XXX\n\nSoon as the polar light, which never knows\nSetting nor rising, nor the shadowy veil\nOf other cloud than sin, fair ornament\nOf the first heav\'n, to duty each one there\nSafely convoying, as that lower doth\nThe steersman to his port, stood firmly fix\'d;\nForthwith the saintly tribe, who in the van\nBetween the Gryphon and its radiance came,\nDid turn them to the car, as to their rest:\nAnd one, as if commission\'d from above,\nIn holy chant thrice shorted forth aloud:\n\"Come, spouse, from Libanus!\" and all the rest\nTook up the song--At the last audit so\nThe blest shall rise, from forth his cavern each\nUplifting lightly his new-vested flesh,\nAs, on the sacred litter, at the voice\nAuthoritative of that elder, sprang\nA hundred ministers and messengers\nOf life eternal.  \"Blessed thou!  who com\'st!\"\nAnd, \"O,\" they cried, \"from full hands scatter ye\nUnwith\'ring lilies;\" and, so saying, cast\nFlowers over head and round them on all sides.\n     I have beheld, ere now, at break of day,\nThe eastern clime all roseate, and the sky\nOppos\'d, one deep and beautiful serene,\nAnd the sun\'s face so shaded, and with mists\nAttemper\'d at li");

                struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "SYSTEM.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 2572; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 22: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST22(void)
{
    // informacje o teście
    test_start(22, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[448] = "";

                strcat(expected_filecontent, "ights mov\'d a voice,\nThat made me seem like needle to the star,\nIn turning to its whereabout, and thus\nBegan:  \"The love, that makes me beautiful,\nPrompts me to tell of th\' other guide, for whom\nSuch good of mine is spoken.  Where one is,\nThe other worthily should also be;\nThat as their warfare was alike, alike\nShould be their glory.  Slow, and full of doubt,\nAnd with thin ranks, after its banner mov\'d\nThe army of Christ (which it so clearly c");

                struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "VERB.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 447; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 23: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST23(void)
{
    // informacje o teście
    test_start(23, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[2121] = "";

                strcat(expected_filecontent, "a in gazophylacium\ndomini mittere,\"\nv. 105.  The fifth light.]  Solomon.\n\nv. 112.  That taper\'s radiance.]  St. Dionysius the Areopagite.\n\"The famous Grecian fanatic, who gave himself out for Dionysius\nthe Areopagite, disciple of St. Paul, and who, under the\nprotection of this venerable name, gave laws and instructions to\nthose that were desirous of raising their souls above all human\nthings in order to unite them to their great source by sublime\ncontemplation, lived most probably in this century (the fourth),\nthough some place him before, others after, the present period.\"\nMaclaine\'s Mosheim, v. i. cent.  iv. p. 2. c. 3.  12.\n\nv. 116.  That pleader.]  1n the fifth century, Paulus Orosius,\n\"acquired a considerable degree of reputation by the History he\nwrote to refute the cavils of the Pagans against Christianity,\nand by his books against the Pelagians and Priscillianists.\"\nIbid.  v. ii. cent. v. p. 2.  c. 2. 11.  A similar train of\nargument was pursued by  Augustine, in his book De Civitate Dei.\nOrosius is classed by Dante, in his treatise De Vulg. Eloq.  I ii\nc. 6. as one of his favourite authors, among those \"qui usi sunt\naltissimas prosas,\"--\" who have written prose with the greatest\nloftiness of style.\"\n\nv. 119.  The eighth.]  Boetius, whose book De Consolatione\nPhilosophiae excited so much attention during the middle ages,\nwas born, as  Tiraboschi conjectures, about 470.  \"In 524 he was\ncruelly put to death by command of Theodoric, either on real or\npretended suspicion of his being engaged in a conspiracy.\" Della\nLett.  Ital. t. iii. 1. i. c. 4.\n\nv. 124.  Cieldauro.]  Boetius was buried at Pavia, in the\nmonastery of St. Pietro in Ciel d\'oro.\n\nv. 126.  Isidore.]  He was Archbishop of Seville during forty\nyears, and died in 635.  See Mariana, Hist. 1.  vi. c. 7.\nMosheim, whose critical opinions in general must be taken with\nsome allowance, observes that \"his grammatical theological, and\nhistorical productions, discover more learning and pedantry, than\njudgment and taste.\"\n\nv. 127.  Bede.]  Bede, whose virtues obtained him the appellation\nof the Venerable, was born in 672 at Wearm");

                struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "FAMOUS.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 2120; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 24: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST24(void)
{
    // informacje o teście
    test_start(24, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[3965] = "";

                strcat(expected_filecontent, "     etext or this \"small print!\" statement.  You may however,\n     if you wish, distribute this etext in machine readable\n     binary, compressed, mark-up, or proprietary form,\n     including any form resulting from conversion by word pro-\n     cessing or hypertext software, but only so long as\n     *EITHER*:\n\n     [*]  The etext, when displayed, is clearly readable, and\n          does *not* contain characters other than those\n          intended by the author of the work, although tilde\n          (~), asterisk (*) and underline (_) characters may\n          be used to convey punctuation intended by the\n          author, and additional characters may be used to\n          indicate hypertext links; OR\n\n     [*]  The etext may be readily converted by the reader at\n          no expense into plain ASCII, EBCDIC or equivalent\n          form by the program that displays the etext (as is\n          the case, for instance, with most word processors);\n          OR\n\n     [*]  You provide, or agree to also provide on request at\n          no additional cost, fee or expense, a copy of the\n          etext in its original plain ASCII form (or in EBCDIC\n          or other equivalent proprietary form).\n\n[2]  Honor the etext refund and replacement provisions of this\n     \"Small Print!\" statement.\n\n[3]  Pay a trademark license fee to the Project of 20% of the\n     net profits you derive calculated using the method you\n     already use to calculate your applicable taxes.  If you\n     don\'t derive profits, no royalty is due.  Royalties are\n     payable to \"Project Gutenberg Association/Carnegie-Mellon\n     University\" within the 60 days following each\n     date you prepare (or were legally required to prepare)\n     your annual (or equivalent periodic) tax return.\n\nWHAT IF YOU *WANT* TO SEND MONEY EVEN IF YOU DON\'T HAVE TO?\nThe Project gratefully accepts contributions in money, time,\nscanning machines, OCR software, public domain etexts, royalty\nfree copyright licenses, and every other sort of contribution\nyou can think of.  Money should be paid to \"Project Gutenberg\nAssociation / Carnegie-Mellon University\".\n\n*END*THE SMALL PRINT! FOR PUBLIC DOMAIN ETEXTS*Ver.04.29.93*END*\n\n\n\n\n\nThis text was prepared for Project Gutenberg by Judith Smith and\nNatalie Salter.  We would also like to thank Montell Corporation\nInc., Sarnia plant, for the use of scanning equipment to\nfacilitate the preparation of this electronic text.\n\nJudith Smith\nheyjude@ebtech.net\n\n\n\n\n\nTHE VISION\nOR,\nHELL, PURGATORY, AND PARADISE\nOF\nDANTE ALIGHIERI\n\nTRANSLATED BY\nTHE REV. H. F. CARY, A.M.\n\n\n\n\n\nHELL\n\nCANTO I\n\nIN the midway of this our mortal life,\nI found me in a gloomy wood, astray\nGone from the path direct:  and e\'en to tell\nIt were no easy task, how savage wild\nThat forest, how robust and rough its growth,\nWhich to remember only, my dismay\nRenews, in bitterness not far from death.\nYet to discourse of what there good befell,\nAll else will I relate discover\'d there.\nHow first I enter\'d it I scarce can say,\nSuch sleepy dullness in that instant weigh\'d\nMy senses down, when the true path I left,\nBut when a mountain\'s foot I reach\'d, where clos\'d\nThe valley, that had pierc\'d my heart with dread,\nI look\'d aloft, and saw his shoulders broad\nAlready vested with that planet\'s beam,\nWho leads all wanderers safe through every way.\n     Then was a little respite to the fear,\nThat in my heart\'s recesses deep had lain,\nAll of that night, so pitifully pass\'d:\nAnd as a man, with difficult short breath,\nForespent with toiling, \'scap\'d from sea to shore,\nTurns to the perilous wide waste, and stands\nAt gaze; e\'en so my spirit, that yet fail\'d\nStruggling with terror, turn\'d to view the straits,\nThat none hath pass\'d and liv\'d.  My weary frame\nAfter short pause recomforted, again\nI journey\'d on over that lonely steep,\nThe hinder foot still firmer.  Scarce the ascent\nBegan, when, lo!  a panther, nimble, light,\nAnd cover\'d with a speckled skin, appear\'d,\nNor, when it saw m");

                struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "HUNT.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 3964; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 25: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST25(void)
{
    // informacje o teście
    test_start(25, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[3585] = "";

                strcat(expected_filecontent, "s,\nI, as she bade, directed.  Never fire,\nWith so swift motion, forth a stormy cloud\nLeap\'d downward from the welkin\'s farthest bound,\nAs I beheld the bird of Jove descending\nPounce on the tree, and, as he rush\'d, the rind,\nDisparting crush beneath him, buds much more\nAnd leaflets.  On the car with all his might\nHe struck, whence, staggering like a ship, it reel\'d,\nAt random driv\'n, to starboard now, o\'ercome,\nAnd now to larboard, by the vaulting waves.\n     Next springing up into the chariot\'s womb\nA fox I saw, with hunger seeming pin\'d\nOf all good food.  But, for his ugly sins\nThe saintly maid rebuking him, away\nScamp\'ring he turn\'d, fast as his hide-bound corpse\nWould bear him.  Next, from whence before he came,\nI saw the eagle dart into the hull\nO\' th\' car, and leave it with his feathers lin\'d;\nAnd then a voice, like that which issues forth\nFrom heart with sorrow riv\'d, did issue forth\nFrom heav\'n, and, \"O poor bark of mine!\" it cried,\n\"How badly art thou freighted!\"  Then, it seem\'d,\nThat the earth open\'d between either wheel,\nAnd I beheld a dragon issue thence,\nThat through the chariot fix\'d his forked train;\nAnd like a wasp that draggeth back the sting,\nSo drawing forth his baleful train, he dragg\'d\nPart of the bottom forth, and went his way\nExulting.  What remain\'d, as lively turf\nWith green herb, so did clothe itself with plumes,\nWhich haply had with purpose chaste and kind\nBeen offer\'d; and therewith were cloth\'d the wheels,\nBoth one and other, and the beam, so quickly\nA sigh were not breath\'d sooner.  Thus transform\'d,\nThe holy structure, through its several parts,\nDid put forth heads, three on the beam, and one\nOn every side; the first like oxen horn\'d,\nBut with a single horn upon their front\nThe four.  Like monster sight hath never seen.\nO\'er it methought there sat, secure as rock\nOn mountain\'s lofty top, a shameless whore,\nWhose ken rov\'d loosely round her.  At her side,\nAs \'t were that none might bear her off, I saw\nA giant stand; and ever, and anon\nThey mingled kisses.  But, her lustful eyes\nChancing on me to wander, that fell minion\nScourg\'d her from head to foot all o\'er; then full\nOf jealousy, and fierce with rage, unloos\'d\nThe monster, and dragg\'d on, so far across\nThe forest, that from me its shades alone\nShielded the harlot and the new-form\'d brute.\n\n\n\nCANTO XXXIII\n\n\"The heathen, Lord!  are come!\" responsive thus,\nThe trinal now, and now the virgin band\nQuaternion, their sweet psalmody began,\nWeeping; and Beatrice listen\'d, sad\nAnd sighing, to the song\', in such a mood,\nThat Mary, as she stood beside the cross,\nWas scarce more chang\'d.  But when they gave her place\nTo speak, then, risen upright on her feet,\nShe, with a colour glowing bright as fire,\nDid answer: \"Yet a little while, and ye\nShall see me not; and, my beloved sisters,\nAgain a little while, and ye shall see me.\"\n     Before her then she marshall\'d all the seven,\nAnd, beck\'ning only motion\'d me, the dame,\nAnd that remaining sage, to follow her.\n     So on she pass\'d; and had not set, I ween,\nHer tenth step to the ground, when with mine eyes\nHer eyes encounter\'d; and, with visage mild,\n\"So mend thy pace,\" she cried, \"that if my words\nAddress thee, thou mayst still be aptly plac\'d\nTo hear them.\"  Soon as duly to her side\nI now had hasten\'d:  \"Brother!\" she began,\n\"Why mak\'st thou no attempt at questioning,\nAs thus we walk together?\"  Like to those\nWho, speaking with too reverent an awe\nBefore their betters, draw not forth the voice\nAlive unto their lips, befell me shell\nThat I in sounds imperfect thus began:\n\"Lady!  what I have need of, t");

                struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "PREPARE.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 3584; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 26: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST26(void)
{
    // informacje o teście
    test_start(26, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[3671] = "";

                strcat(expected_filecontent, " unmerited calamity and disgrace,\nhe put an end to his life by dashing out his brains against the\nwalls of a church, in the year 1245.  Both Frederick and Pietro\ndelle Vigne composed verses in the Sicilian dialect which are yet\nextant.\n\nv. 67.  The harlot.]  Envy.  Chaucer alludes to this in the\nPrologue to the Legende of Good women.\n        Envie is lavender to the court alway,\n        For she ne parteth neither night ne day\n        Out of the house of Cesar; thus saith Dant.\n\nv. 119.  Each fan o\' th\' wood.]  Hence perhaps Milton:\n        Leaves and fuming rills, Aurora\'s fan.\n               P. L. b. v. 6.\n\nv. 122.  Lano.]  Lano, a Siennese, who, being reduced by\nprodigality to a state of extreme want, found his existence no\nlonger supportable; and, having been sent by his countrymen on a\nmilitary expedition, to assist the Florentine against the\nAretini, took that opportunity of exposing himself to certain\ndeath, in the engagement which took place at Toppo near Arezzo.\nSee G. Villani, Hist. l. 7. c. cxix.\n\nv. 133.               O Giocomo\n        Of Sant\' Andrea!]\nJacopo da Sant\' Andrea, a Paduan, who, having wasted his property\nin the most wanton acts of profusion, killed himself in despair.\nv. 144.  In that City.]  \"I was an inhabitant of Florence, that\ncity which changed her first patron Mars for St. John the\nBaptist, for which reason the vengeance of the deity thus\nslighted will never be appeased:  and, if some remains of his\nstatus were not still visible on the bridge over the Arno, she\nwould have been already leveled to the ground; and thus the\ncitizens, who raised her again from the ashes to which Attila had\nreduced her, would have laboured in vain.\"  See Paradise, Canto\nXVI. 44.\nThe relic of antiquity to which the superstition of Florence\nattached so high an importance, was carried away by a flood, that\ndestroyed the bridge on which it stood, in the year 1337, but\nwithout the ill effects that were apprehended from the loss of\ntheir fancied Palladium.\n\nv. 152.  I slung the fatal noose.]  We are not informed who this\nsuicide was.\n\n\nCANTO XIV\n\nv. 15.  By Cato\'s foot.]  See Lucan, Phars, l. 9.\n\nv. 26. Dilated flakes of fire.]  Compare Tasso.  G. L. c. x. st.\n61.\n\nv. 28.  As, in the torrid Indian clime.]  Landino refers to\nAlbertus Magnus for the circumstance here alluded to.\n\nv. 53.  In Mongibello.]\n        More hot than Aetn\' or flaming Mongibell.\n               Spenser, F. Q. b. ii. c. ix. st. 29.\nSee Virg. Aen. 1. viii. 416. and Berni. Orl. Inn 1. i. c. xvi.\nst. 21.  It would be endless to refer to parallel passages in the\nGreek writers.\n\nv. 64.  This of the seven kings was one.]  Compare Aesch.  Seven\nChiefs, 425.  Euripides, Phoen. 1179 and Statius. Theb. l. x.\n821.\n\nv. 76.  Bulicame.]  A warm medicinal spring near Viterbo, the\nwaters of which, as Landino and Vellutelli affirm, passed by a\nplace of ill fame.  Venturi, with less probability, conjectures\nthat Dante would imply, that it was the scene of much licentious\nmerriment among those who frequented its baths.\n\nv. 91.  Under whose monarch.]\n        Credo pudicitiam Saturno rege moratam\n        In terris.\n               Juv. Satir. vi.\n\nv. 102.  His head.]  Daniel, ch. ii. 32, 33.\n\nv. 133.  Whither.] On the other side of Purgatory.\n\nCANTO XV\n\n v. 10.  Chiarentana.]  A part of the Alps where the Brenta\nrises, which river is much swoln as soon as the snow begins to\ndissolve on the mountains.\n\nv. 28.  Brunetto.]  \"Ser Brunetto, a Florentine, the secretary or\nchancellor of the city, and Dante\'s preceptor, hath left us a\nwork so little read, that both the subject of it and the language\nof it have been mistaken.  It is in the French spoken in the\nr");

                struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "COMPLETE.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 3670; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 27: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST27(void)
{
    // informacje o teście
    test_start(27, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(2572, 1);
            char expected_filecontent[2573] = "";

            strcat(expected_filecontent, "her form had scarce\nBeen known within a furnace of clear flame:\nThe next did look, as if the flesh and bones\nWere emerald: snow new-fallen seem\'d the third.\nNow seem\'d the white to lead, the ruddy now;\nAnd from her song who led, the others took\nTheir treasure, swift or slow.  At th\' other wheel,\nA band quaternion, each in purple clad,\nAdvanc\'d with festal step, as of them one\nThe rest conducted, one, upon whose front\nThree eyes were seen.  In rear of all this group,\nTwo old men I beheld, dissimilar\nIn raiment, but in port and gesture like,\nSolid and mainly grave; of whom the one\nDid show himself some favour\'d counsellor\nOf the great Coan, him, whom nature made\nTo serve the costliest creature of her tribe.\nHis fellow mark\'d an opposite intent,\nBearing a sword, whose glitterance and keen edge,\nE\'en as I view\'d it with the flood between,\nAppall\'d me.  Next four others I beheld,\nOf humble seeming: and, behind them all,\nOne single old man, sleeping, as he came,\nWith a shrewd visage.  And these seven, each\nLike the first troop were habited, hut wore\nNo braid of lilies on their temples wreath\'d.\nRather with roses and each vermeil flower,\nA sight, but little distant, might have sworn,\nThat they were all on fire above their brow.\n     Whenas the car was o\'er against me, straight.\nWas heard a thund\'ring, at whose voice it seem\'d\nThe chosen multitude were stay\'d; for there,\nWith the first ensigns, made they solemn halt.\n\n\n\nCANTO XXX\n\nSoon as the polar light, which never knows\nSetting nor rising, nor the shadowy veil\nOf other cloud than sin, fair ornament\nOf the first heav\'n, to duty each one there\nSafely convoying, as that lower doth\nThe steersman to his port, stood firmly fix\'d;\nForthwith the saintly tribe, who in the van\nBetween the Gryphon and its radiance came,\nDid turn them to the car, as to their rest:\nAnd one, as if commission\'d from above,\nIn holy chant thrice shorted forth aloud:\n\"Come, spouse, from Libanus!\" and all the rest\nTook up the song--At the last audit so\nThe blest shall rise, from forth his cavern each\nUplifting lightly his new-vested flesh,\nAs, on the sacred litter, at the voice\nAuthoritative of that elder, sprang\nA hundred ministers and messengers\nOf life eternal.  \"Blessed thou!  who com\'st!\"\nAnd, \"O,\" they cried, \"from full hands scatter ye\nUnwith\'ring lilies;\" and, so saying, cast\nFlowers over head and round them on all sides.\n     I have beheld, ere now, at break of day,\nThe eastern clime all roseate, and the sky\nOppos\'d, one deep and beautiful serene,\nAnd the sun\'s face so shaded, and with mists\nAttemper\'d at li");

            struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "SYSTEM.BIN");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            int i;
            for (i = 0; i < 321; ++i)
            {
                int res = file_read(filecontent + 8 * i, 8, 1, file);
                test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            }

            int res = file_read(filecontent + 8 * i, 8, 1, file);
            test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 2572);

            // jeśli jest, to raportuj błąd
            test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

            onerror_compare_memory(expected_filecontent, filecontent, 2572);

            free(filecontent);
            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 28: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST28(void)
{
    // informacje o teście
    test_start(28, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            char *filecontent0 = (char *)calloc(2046, 1);
    char *filecontent1 = (char *)calloc(2572, 1);
    char *filecontent2 = (char *)calloc(447, 1);
    char *filecontent3 = (char *)calloc(2120, 1);
    char *filecontent4 = (char *)calloc(3964, 1);
    char *filecontent5 = (char *)calloc(3584, 1);
    char *filecontent6 = (char *)calloc(3670, 1);

            char expected_filecontent0[2047] = "";
    char expected_filecontent1[2573] = "";
    char expected_filecontent2[448] = "";
    char expected_filecontent3[2121] = "";
    char expected_filecontent4[3965] = "";
    char expected_filecontent5[3585] = "";
    char expected_filecontent6[3671] = "";

            strcat(expected_filecontent0, "orthwith replied:\n\"If I have power to show one truth, soon that\nShall face thee, which thy questioning declares\nBehind thee now conceal\'d.  The Good, that guides\nAnd blessed makes this realm, which thou dost mount,\nOrdains its providence to be the virtue\nIn these great bodies: nor th\' all perfect Mind\nUpholds their nature merely, but in them\nTheir energy to save: for nought, that lies\nWithin the range of that unerring bow,\nBut is as level with the destin\'d aim,\nAs ever mark to arrow\'s point oppos\'d.\nWere it not thus, these heavens, thou dost visit,\nWould their effect so work, it would not be\nArt, but destruction; and this may not chance,\nIf th\' intellectual powers, that move these stars,\nFail not, or who, first faulty made them fail.\nWilt thou this truth more clearly evidenc\'d?\"\n     To whom I thus:  \"It is enough: no fear,\nI see, lest nature in her part should tire.\"\n     He straight rejoin\'d:  \"Say, were it worse for man,\nIf he liv\'d not in fellowship on earth?\"\n     \"Yea,\" answer\'d I;  \"nor here a reason needs.\"\n     \"And may that be, if different estates\nGrow not of different duties in your life?\nConsult your teacher, and he tells you \'no.\"\'\n     Thus did he come, deducing to this point,\nAnd then concluded:  \"For this cause behooves,\nThe roots, from whence your operations come,\nMust differ.  Therefore one is Solon born;\nAnother, Xerxes; and Melchisidec\nA third; and he a fourth, whose airy voyage\nCost him his son.  In her circuitous course,\nNature, that is the seal to mortal wax,\nDoth well her art, but no distinctions owns\n\'Twixt one or other household.  Hence befalls\nThat Esau is so wide of Jacob:  hence\nQuirinus of so base a father springs,\nHe dates from Mars his lineage.  Were it not\nThat providence celestial overrul\'d,\nNature, in generation, must the path\nTrac\'d by the generator, still pursue\nUnswervingly.  Thus place I in thy sight\nThat, which was late behind thee.  But, in sign\nOf more affection for thee, \'t is my will\nThou wear this corollary.  Nature ever\nFinding discordant fortune, like all seed\nOut");strcat(expected_filecontent1, "her form had scarce\nBeen known within a furnace of clear flame:\nThe next did look, as if the flesh and bones\nWere emerald: snow new-fallen seem\'d the third.\nNow seem\'d the white to lead, the ruddy now;\nAnd from her song who led, the others took\nTheir treasure, swift or slow.  At th\' other wheel,\nA band quaternion, each in purple clad,\nAdvanc\'d with festal step, as of them one\nThe rest conducted, one, upon whose front\nThree eyes were seen.  In rear of all this group,\nTwo old men I beheld, dissimilar\nIn raiment, but in port and gesture like,\nSolid and mainly grave; of whom the one\nDid show himself some favour\'d counsellor\nOf the great Coan, him, whom nature made\nTo serve the costliest creature of her tribe.\nHis fellow mark\'d an opposite intent,\nBearing a sword, whose glitterance and keen edge,\nE\'en as I view\'d it with the flood between,\nAppall\'d me.  Next four others I beheld,\nOf humble seeming: and, behind them all,\nOne single old man, sleeping, as he came,\nWith a shrewd visage.  And these seven, each\nLike the first troop were habited, hut wore\nNo braid of lilies on their temples wreath\'d.\nRather with roses and each vermeil flower,\nA sight, but little distant, might have sworn,\nThat they were all on fire above their brow.\n     Whenas the car was o\'er against me, straight.\nWas heard a thund\'ring, at whose voice it seem\'d\nThe chosen multitude were stay\'d; for there,\nWith the first ensigns, made they solemn halt.\n\n\n\nCANTO XXX\n\nSoon as the polar light, which never knows\nSetting nor rising, nor the shadowy veil\nOf other cloud than sin, fair ornament\nOf the first heav\'n, to duty each one there\nSafely convoying, as that lower doth\nThe steersman to his port, stood firmly fix\'d;\nForthwith the saintly tribe, who in the van\nBetween the Gryphon and its radiance came,\nDid turn them to the car, as to their rest:\nAnd one, as if commission\'d from above,\nIn holy chant thrice shorted forth aloud:\n\"Come, spouse, from Libanus!\" and all the rest\nTook up the song--At the last audit so\nThe blest shall rise, from forth his cavern each\nUplifting lightly his new-vested flesh,\nAs, on the sacred litter, at the voice\nAuthoritative of that elder, sprang\nA hundred ministers and messengers\nOf life eternal.  \"Blessed thou!  who com\'st!\"\nAnd, \"O,\" they cried, \"from full hands scatter ye\nUnwith\'ring lilies;\" and, so saying, cast\nFlowers over head and round them on all sides.\n     I have beheld, ere now, at break of day,\nThe eastern clime all roseate, and the sky\nOppos\'d, one deep and beautiful serene,\nAnd the sun\'s face so shaded, and with mists\nAttemper\'d at li");strcat(expected_filecontent2, "ights mov\'d a voice,\nThat made me seem like needle to the star,\nIn turning to its whereabout, and thus\nBegan:  \"The love, that makes me beautiful,\nPrompts me to tell of th\' other guide, for whom\nSuch good of mine is spoken.  Where one is,\nThe other worthily should also be;\nThat as their warfare was alike, alike\nShould be their glory.  Slow, and full of doubt,\nAnd with thin ranks, after its banner mov\'d\nThe army of Christ (which it so clearly c");strcat(expected_filecontent3, "a in gazophylacium\ndomini mittere,\"\nv. 105.  The fifth light.]  Solomon.\n\nv. 112.  That taper\'s radiance.]  St. Dionysius the Areopagite.\n\"The famous Grecian fanatic, who gave himself out for Dionysius\nthe Areopagite, disciple of St. Paul, and who, under the\nprotection of this venerable name, gave laws and instructions to\nthose that were desirous of raising their souls above all human\nthings in order to unite them to their great source by sublime\ncontemplation, lived most probably in this century (the fourth),\nthough some place him before, others after, the present period.\"\nMaclaine\'s Mosheim, v. i. cent.  iv. p. 2. c. 3.  12.\n\nv. 116.  That pleader.]  1n the fifth century, Paulus Orosius,\n\"acquired a considerable degree of reputation by the History he\nwrote to refute the cavils of the Pagans against Christianity,\nand by his books against the Pelagians and Priscillianists.\"\nIbid.  v. ii. cent. v. p. 2.  c. 2. 11.  A similar train of\nargument was pursued by  Augustine, in his book De Civitate Dei.\nOrosius is classed by Dante, in his treatise De Vulg. Eloq.  I ii\nc. 6. as one of his favourite authors, among those \"qui usi sunt\naltissimas prosas,\"--\" who have written prose with the greatest\nloftiness of style.\"\n\nv. 119.  The eighth.]  Boetius, whose book De Consolatione\nPhilosophiae excited so much attention during the middle ages,\nwas born, as  Tiraboschi conjectures, about 470.  \"In 524 he was\ncruelly put to death by command of Theodoric, either on real or\npretended suspicion of his being engaged in a conspiracy.\" Della\nLett.  Ital. t. iii. 1. i. c. 4.\n\nv. 124.  Cieldauro.]  Boetius was buried at Pavia, in the\nmonastery of St. Pietro in Ciel d\'oro.\n\nv. 126.  Isidore.]  He was Archbishop of Seville during forty\nyears, and died in 635.  See Mariana, Hist. 1.  vi. c. 7.\nMosheim, whose critical opinions in general must be taken with\nsome allowance, observes that \"his grammatical theological, and\nhistorical productions, discover more learning and pedantry, than\njudgment and taste.\"\n\nv. 127.  Bede.]  Bede, whose virtues obtained him the appellation\nof the Venerable, was born in 672 at Wearm");strcat(expected_filecontent4, "     etext or this \"small print!\" statement.  You may however,\n     if you wish, distribute this etext in machine readable\n     binary, compressed, mark-up, or proprietary form,\n     including any form resulting from conversion by word pro-\n     cessing or hypertext software, but only so long as\n     *EITHER*:\n\n     [*]  The etext, when displayed, is clearly readable, and\n          does *not* contain characters other than those\n          intended by the author of the work, although tilde\n          (~), asterisk (*) and underline (_) characters may\n          be used to convey punctuation intended by the\n          author, and additional characters may be used to\n          indicate hypertext links; OR\n\n     [*]  The etext may be readily converted by the reader at\n          no expense into plain ASCII, EBCDIC or equivalent\n          form by the program that displays the etext (as is\n          the case, for instance, with most word processors);\n          OR\n\n     [*]  You provide, or agree to also provide on request at\n          no additional cost, fee or expense, a copy of the\n          etext in its original plain ASCII form (or in EBCDIC\n          or other equivalent proprietary form).\n\n[2]  Honor the etext refund and replacement provisions of this\n     \"Small Print!\" statement.\n\n[3]  Pay a trademark license fee to the Project of 20% of the\n     net profits you derive calculated using the method you\n     already use to calculate your applicable taxes.  If you\n     don\'t derive profits, no royalty is due.  Royalties are\n     payable to \"Project Gutenberg Association/Carnegie-Mellon\n     University\" within the 60 days following each\n     date you prepare (or were legally required to prepare)\n     your annual (or equivalent periodic) tax return.\n\nWHAT IF YOU *WANT* TO SEND MONEY EVEN IF YOU DON\'T HAVE TO?\nThe Project gratefully accepts contributions in money, time,\nscanning machines, OCR software, public domain etexts, royalty\nfree copyright licenses, and every other sort of contribution\nyou can think of.  Money should be paid to \"Project Gutenberg\nAssociation / Carnegie-Mellon University\".\n\n*END*THE SMALL PRINT! FOR PUBLIC DOMAIN ETEXTS*Ver.04.29.93*END*\n\n\n\n\n\nThis text was prepared for Project Gutenberg by Judith Smith and\nNatalie Salter.  We would also like to thank Montell Corporation\nInc., Sarnia plant, for the use of scanning equipment to\nfacilitate the preparation of this electronic text.\n\nJudith Smith\nheyjude@ebtech.net\n\n\n\n\n\nTHE VISION\nOR,\nHELL, PURGATORY, AND PARADISE\nOF\nDANTE ALIGHIERI\n\nTRANSLATED BY\nTHE REV. H. F. CARY, A.M.\n\n\n\n\n\nHELL\n\nCANTO I\n\nIN the midway of this our mortal life,\nI found me in a gloomy wood, astray\nGone from the path direct:  and e\'en to tell\nIt were no easy task, how savage wild\nThat forest, how robust and rough its growth,\nWhich to remember only, my dismay\nRenews, in bitterness not far from death.\nYet to discourse of what there good befell,\nAll else will I relate discover\'d there.\nHow first I enter\'d it I scarce can say,\nSuch sleepy dullness in that instant weigh\'d\nMy senses down, when the true path I left,\nBut when a mountain\'s foot I reach\'d, where clos\'d\nThe valley, that had pierc\'d my heart with dread,\nI look\'d aloft, and saw his shoulders broad\nAlready vested with that planet\'s beam,\nWho leads all wanderers safe through every way.\n     Then was a little respite to the fear,\nThat in my heart\'s recesses deep had lain,\nAll of that night, so pitifully pass\'d:\nAnd as a man, with difficult short breath,\nForespent with toiling, \'scap\'d from sea to shore,\nTurns to the perilous wide waste, and stands\nAt gaze; e\'en so my spirit, that yet fail\'d\nStruggling with terror, turn\'d to view the straits,\nThat none hath pass\'d and liv\'d.  My weary frame\nAfter short pause recomforted, again\nI journey\'d on over that lonely steep,\nThe hinder foot still firmer.  Scarce the ascent\nBegan, when, lo!  a panther, nimble, light,\nAnd cover\'d with a speckled skin, appear\'d,\nNor, when it saw m");strcat(expected_filecontent5, "s,\nI, as she bade, directed.  Never fire,\nWith so swift motion, forth a stormy cloud\nLeap\'d downward from the welkin\'s farthest bound,\nAs I beheld the bird of Jove descending\nPounce on the tree, and, as he rush\'d, the rind,\nDisparting crush beneath him, buds much more\nAnd leaflets.  On the car with all his might\nHe struck, whence, staggering like a ship, it reel\'d,\nAt random driv\'n, to starboard now, o\'ercome,\nAnd now to larboard, by the vaulting waves.\n     Next springing up into the chariot\'s womb\nA fox I saw, with hunger seeming pin\'d\nOf all good food.  But, for his ugly sins\nThe saintly maid rebuking him, away\nScamp\'ring he turn\'d, fast as his hide-bound corpse\nWould bear him.  Next, from whence before he came,\nI saw the eagle dart into the hull\nO\' th\' car, and leave it with his feathers lin\'d;\nAnd then a voice, like that which issues forth\nFrom heart with sorrow riv\'d, did issue forth\nFrom heav\'n, and, \"O poor bark of mine!\" it cried,\n\"How badly art thou freighted!\"  Then, it seem\'d,\nThat the earth open\'d between either wheel,\nAnd I beheld a dragon issue thence,\nThat through the chariot fix\'d his forked train;\nAnd like a wasp that draggeth back the sting,\nSo drawing forth his baleful train, he dragg\'d\nPart of the bottom forth, and went his way\nExulting.  What remain\'d, as lively turf\nWith green herb, so did clothe itself with plumes,\nWhich haply had with purpose chaste and kind\nBeen offer\'d; and therewith were cloth\'d the wheels,\nBoth one and other, and the beam, so quickly\nA sigh were not breath\'d sooner.  Thus transform\'d,\nThe holy structure, through its several parts,\nDid put forth heads, three on the beam, and one\nOn every side; the first like oxen horn\'d,\nBut with a single horn upon their front\nThe four.  Like monster sight hath never seen.\nO\'er it methought there sat, secure as rock\nOn mountain\'s lofty top, a shameless whore,\nWhose ken rov\'d loosely round her.  At her side,\nAs \'t were that none might bear her off, I saw\nA giant stand; and ever, and anon\nThey mingled kisses.  But, her lustful eyes\nChancing on me to wander, that fell minion\nScourg\'d her from head to foot all o\'er; then full\nOf jealousy, and fierce with rage, unloos\'d\nThe monster, and dragg\'d on, so far across\nThe forest, that from me its shades alone\nShielded the harlot and the new-form\'d brute.\n\n\n\nCANTO XXXIII\n\n\"The heathen, Lord!  are come!\" responsive thus,\nThe trinal now, and now the virgin band\nQuaternion, their sweet psalmody began,\nWeeping; and Beatrice listen\'d, sad\nAnd sighing, to the song\', in such a mood,\nThat Mary, as she stood beside the cross,\nWas scarce more chang\'d.  But when they gave her place\nTo speak, then, risen upright on her feet,\nShe, with a colour glowing bright as fire,\nDid answer: \"Yet a little while, and ye\nShall see me not; and, my beloved sisters,\nAgain a little while, and ye shall see me.\"\n     Before her then she marshall\'d all the seven,\nAnd, beck\'ning only motion\'d me, the dame,\nAnd that remaining sage, to follow her.\n     So on she pass\'d; and had not set, I ween,\nHer tenth step to the ground, when with mine eyes\nHer eyes encounter\'d; and, with visage mild,\n\"So mend thy pace,\" she cried, \"that if my words\nAddress thee, thou mayst still be aptly plac\'d\nTo hear them.\"  Soon as duly to her side\nI now had hasten\'d:  \"Brother!\" she began,\n\"Why mak\'st thou no attempt at questioning,\nAs thus we walk together?\"  Like to those\nWho, speaking with too reverent an awe\nBefore their betters, draw not forth the voice\nAlive unto their lips, befell me shell\nThat I in sounds imperfect thus began:\n\"Lady!  what I have need of, t");strcat(expected_filecontent6, " unmerited calamity and disgrace,\nhe put an end to his life by dashing out his brains against the\nwalls of a church, in the year 1245.  Both Frederick and Pietro\ndelle Vigne composed verses in the Sicilian dialect which are yet\nextant.\n\nv. 67.  The harlot.]  Envy.  Chaucer alludes to this in the\nPrologue to the Legende of Good women.\n        Envie is lavender to the court alway,\n        For she ne parteth neither night ne day\n        Out of the house of Cesar; thus saith Dant.\n\nv. 119.  Each fan o\' th\' wood.]  Hence perhaps Milton:\n        Leaves and fuming rills, Aurora\'s fan.\n               P. L. b. v. 6.\n\nv. 122.  Lano.]  Lano, a Siennese, who, being reduced by\nprodigality to a state of extreme want, found his existence no\nlonger supportable; and, having been sent by his countrymen on a\nmilitary expedition, to assist the Florentine against the\nAretini, took that opportunity of exposing himself to certain\ndeath, in the engagement which took place at Toppo near Arezzo.\nSee G. Villani, Hist. l. 7. c. cxix.\n\nv. 133.               O Giocomo\n        Of Sant\' Andrea!]\nJacopo da Sant\' Andrea, a Paduan, who, having wasted his property\nin the most wanton acts of profusion, killed himself in despair.\nv. 144.  In that City.]  \"I was an inhabitant of Florence, that\ncity which changed her first patron Mars for St. John the\nBaptist, for which reason the vengeance of the deity thus\nslighted will never be appeased:  and, if some remains of his\nstatus were not still visible on the bridge over the Arno, she\nwould have been already leveled to the ground; and thus the\ncitizens, who raised her again from the ashes to which Attila had\nreduced her, would have laboured in vain.\"  See Paradise, Canto\nXVI. 44.\nThe relic of antiquity to which the superstition of Florence\nattached so high an importance, was carried away by a flood, that\ndestroyed the bridge on which it stood, in the year 1337, but\nwithout the ill effects that were apprehended from the loss of\ntheir fancied Palladium.\n\nv. 152.  I slung the fatal noose.]  We are not informed who this\nsuicide was.\n\n\nCANTO XIV\n\nv. 15.  By Cato\'s foot.]  See Lucan, Phars, l. 9.\n\nv. 26. Dilated flakes of fire.]  Compare Tasso.  G. L. c. x. st.\n61.\n\nv. 28.  As, in the torrid Indian clime.]  Landino refers to\nAlbertus Magnus for the circumstance here alluded to.\n\nv. 53.  In Mongibello.]\n        More hot than Aetn\' or flaming Mongibell.\n               Spenser, F. Q. b. ii. c. ix. st. 29.\nSee Virg. Aen. 1. viii. 416. and Berni. Orl. Inn 1. i. c. xvi.\nst. 21.  It would be endless to refer to parallel passages in the\nGreek writers.\n\nv. 64.  This of the seven kings was one.]  Compare Aesch.  Seven\nChiefs, 425.  Euripides, Phoen. 1179 and Statius. Theb. l. x.\n821.\n\nv. 76.  Bulicame.]  A warm medicinal spring near Viterbo, the\nwaters of which, as Landino and Vellutelli affirm, passed by a\nplace of ill fame.  Venturi, with less probability, conjectures\nthat Dante would imply, that it was the scene of much licentious\nmerriment among those who frequented its baths.\n\nv. 91.  Under whose monarch.]\n        Credo pudicitiam Saturno rege moratam\n        In terris.\n               Juv. Satir. vi.\n\nv. 102.  His head.]  Daniel, ch. ii. 32, 33.\n\nv. 133.  Whither.] On the other side of Purgatory.\n\nCANTO XV\n\n v. 10.  Chiarentana.]  A part of the Alps where the Brenta\nrises, which river is much swoln as soon as the snow begins to\ndissolve on the mountains.\n\nv. 28.  Brunetto.]  \"Ser Brunetto, a Florentine, the secretary or\nchancellor of the city, and Dante\'s preceptor, hath left us a\nwork so little read, that both the subject of it and the language\nof it have been mistaken.  It is in the French spoken in the\nr");


            struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            
                    struct file_t* file0 = file_open(volume, "MONEY.TX");
                    test_error(file0 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file1 = file_open(volume, "SYSTEM.BIN");
                    test_error(file1 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file2 = file_open(volume, "VERB.TX");
                    test_error(file2 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file3 = file_open(volume, "FAMOUS.TXT");
                    test_error(file3 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file4 = file_open(volume, "HUNT.TXT");
                    test_error(file4 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file5 = file_open(volume, "PREPARE.BIN");
                    test_error(file5 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file6 = file_open(volume, "COMPLETE.TXT");
                    test_error(file6 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
            
                size_t size0 = file_read(filecontent0, 1, 2046, file0);
                test_error(size0 == 2046, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2046 bajtów, a wczytała %lu", size0);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos0 = mem_find_first_difference(filecontent0, expected_filecontent0, 2046);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos0 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos0, mem_get_byte(filecontent0, diff_pos0), mem_get_byte(expected_filecontent0, diff_pos0));
        
                onerror_compare_memory(expected_filecontent0, filecontent0, 2046);
            
                size_t size1 = file_read(filecontent1, 1, 2572, file1);
                test_error(size1 == 2572, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2572 bajtów, a wczytała %lu", size1);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos1 = mem_find_first_difference(filecontent1, expected_filecontent1, 2572);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos1 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos1, mem_get_byte(filecontent1, diff_pos1), mem_get_byte(expected_filecontent1, diff_pos1));
        
                onerror_compare_memory(expected_filecontent1, filecontent1, 2572);
            
                size_t size2 = file_read(filecontent2, 1, 447, file2);
                test_error(size2 == 447, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 447 bajtów, a wczytała %lu", size2);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos2 = mem_find_first_difference(filecontent2, expected_filecontent2, 447);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos2 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos2, mem_get_byte(filecontent2, diff_pos2), mem_get_byte(expected_filecontent2, diff_pos2));
        
                onerror_compare_memory(expected_filecontent2, filecontent2, 447);
            
                size_t size3 = file_read(filecontent3, 1, 2120, file3);
                test_error(size3 == 2120, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2120 bajtów, a wczytała %lu", size3);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos3 = mem_find_first_difference(filecontent3, expected_filecontent3, 2120);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos3 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos3, mem_get_byte(filecontent3, diff_pos3), mem_get_byte(expected_filecontent3, diff_pos3));
        
                onerror_compare_memory(expected_filecontent3, filecontent3, 2120);
            
                size_t size4 = file_read(filecontent4, 1, 3964, file4);
                test_error(size4 == 3964, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3964 bajtów, a wczytała %lu", size4);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos4 = mem_find_first_difference(filecontent4, expected_filecontent4, 3964);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos4 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos4, mem_get_byte(filecontent4, diff_pos4), mem_get_byte(expected_filecontent4, diff_pos4));
        
                onerror_compare_memory(expected_filecontent4, filecontent4, 3964);
            
                size_t size5 = file_read(filecontent5, 1, 3584, file5);
                test_error(size5 == 3584, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3584 bajtów, a wczytała %lu", size5);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos5 = mem_find_first_difference(filecontent5, expected_filecontent5, 3584);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos5 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos5, mem_get_byte(filecontent5, diff_pos5), mem_get_byte(expected_filecontent5, diff_pos5));
        
                onerror_compare_memory(expected_filecontent5, filecontent5, 3584);
            
                size_t size6 = file_read(filecontent6, 1, 3670, file6);
                test_error(size6 == 3670, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3670 bajtów, a wczytała %lu", size6);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos6 = mem_find_first_difference(filecontent6, expected_filecontent6, 3670);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos6 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos6, mem_get_byte(filecontent6, diff_pos6), mem_get_byte(expected_filecontent6, diff_pos6));
        
                onerror_compare_memory(expected_filecontent6, filecontent6, 3670);
            

            free(filecontent0);
    free(filecontent1);
    free(filecontent2);
    free(filecontent3);
    free(filecontent4);
    free(filecontent5);
    free(filecontent6);

            file_close(file0);
    file_close(file1);
    file_close(file2);
    file_close(file3);
    file_close(file4);
    file_close(file5);
    file_close(file6);


            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 29: Sprawdzanie poprawności działania funkcji file_seek
//
void UTEST29(void)
{
    // informacje o teście
    test_start(29, "Sprawdzanie poprawności działania funkcji file_seek", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(2120, 1);
            char expected_filecontent[2121] = "";

            strcat(expected_filecontent, "a in gazophylacium\ndomini mittere,\"\nv. 105.  The fifth light.]  Solomon.\n\nv. 112.  That taper\'s radiance.]  St. Dionysius the Areopagite.\n\"The famous Grecian fanatic, who gave himself out for Dionysius\nthe Areopagite, disciple of St. Paul, and who, under the\nprotection of this venerable name, gave laws and instructions to\nthose that were desirous of raising their souls above all human\nthings in order to unite them to their great source by sublime\ncontemplation, lived most probably in this century (the fourth),\nthough some place him before, others after, the present period.\"\nMaclaine\'s Mosheim, v. i. cent.  iv. p. 2. c. 3.  12.\n\nv. 116.  That pleader.]  1n the fifth century, Paulus Orosius,\n\"acquired a considerable degree of reputation by the History he\nwrote to refute the cavils of the Pagans against Christianity,\nand by his books against the Pelagians and Priscillianists.\"\nIbid.  v. ii. cent. v. p. 2.  c. 2. 11.  A similar train of\nargument was pursued by  Augustine, in his book De Civitate Dei.\nOrosius is classed by Dante, in his treatise De Vulg. Eloq.  I ii\nc. 6. as one of his favourite authors, among those \"qui usi sunt\naltissimas prosas,\"--\" who have written prose with the greatest\nloftiness of style.\"\n\nv. 119.  The eighth.]  Boetius, whose book De Consolatione\nPhilosophiae excited so much attention during the middle ages,\nwas born, as  Tiraboschi conjectures, about 470.  \"In 524 he was\ncruelly put to death by command of Theodoric, either on real or\npretended suspicion of his being engaged in a conspiracy.\" Della\nLett.  Ital. t. iii. 1. i. c. 4.\n\nv. 124.  Cieldauro.]  Boetius was buried at Pavia, in the\nmonastery of St. Pietro in Ciel d\'oro.\n\nv. 126.  Isidore.]  He was Archbishop of Seville during forty\nyears, and died in 635.  See Mariana, Hist. 1.  vi. c. 7.\nMosheim, whose critical opinions in general must be taken with\nsome allowance, observes that \"his grammatical theological, and\nhistorical productions, discover more learning and pedantry, than\njudgment and taste.\"\n\nv. 127.  Bede.]  Bede, whose virtues obtained him the appellation\nof the Venerable, was born in 672 at Wearm");

            struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "FAMOUS.TXT");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, 1795, SEEK_SET);
        
            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[1795] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[1795], c);

            free(filecontent);
            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 30: Sprawdzanie poprawności działania funkcji file_seek
//
void UTEST30(void)
{
    // informacje o teście
    test_start(30, "Sprawdzanie poprawności działania funkcji file_seek", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(3584, 1);
            char expected_filecontent[3585] = "";

            strcat(expected_filecontent, "s,\nI, as she bade, directed.  Never fire,\nWith so swift motion, forth a stormy cloud\nLeap\'d downward from the welkin\'s farthest bound,\nAs I beheld the bird of Jove descending\nPounce on the tree, and, as he rush\'d, the rind,\nDisparting crush beneath him, buds much more\nAnd leaflets.  On the car with all his might\nHe struck, whence, staggering like a ship, it reel\'d,\nAt random driv\'n, to starboard now, o\'ercome,\nAnd now to larboard, by the vaulting waves.\n     Next springing up into the chariot\'s womb\nA fox I saw, with hunger seeming pin\'d\nOf all good food.  But, for his ugly sins\nThe saintly maid rebuking him, away\nScamp\'ring he turn\'d, fast as his hide-bound corpse\nWould bear him.  Next, from whence before he came,\nI saw the eagle dart into the hull\nO\' th\' car, and leave it with his feathers lin\'d;\nAnd then a voice, like that which issues forth\nFrom heart with sorrow riv\'d, did issue forth\nFrom heav\'n, and, \"O poor bark of mine!\" it cried,\n\"How badly art thou freighted!\"  Then, it seem\'d,\nThat the earth open\'d between either wheel,\nAnd I beheld a dragon issue thence,\nThat through the chariot fix\'d his forked train;\nAnd like a wasp that draggeth back the sting,\nSo drawing forth his baleful train, he dragg\'d\nPart of the bottom forth, and went his way\nExulting.  What remain\'d, as lively turf\nWith green herb, so did clothe itself with plumes,\nWhich haply had with purpose chaste and kind\nBeen offer\'d; and therewith were cloth\'d the wheels,\nBoth one and other, and the beam, so quickly\nA sigh were not breath\'d sooner.  Thus transform\'d,\nThe holy structure, through its several parts,\nDid put forth heads, three on the beam, and one\nOn every side; the first like oxen horn\'d,\nBut with a single horn upon their front\nThe four.  Like monster sight hath never seen.\nO\'er it methought there sat, secure as rock\nOn mountain\'s lofty top, a shameless whore,\nWhose ken rov\'d loosely round her.  At her side,\nAs \'t were that none might bear her off, I saw\nA giant stand; and ever, and anon\nThey mingled kisses.  But, her lustful eyes\nChancing on me to wander, that fell minion\nScourg\'d her from head to foot all o\'er; then full\nOf jealousy, and fierce with rage, unloos\'d\nThe monster, and dragg\'d on, so far across\nThe forest, that from me its shades alone\nShielded the harlot and the new-form\'d brute.\n\n\n\nCANTO XXXIII\n\n\"The heathen, Lord!  are come!\" responsive thus,\nThe trinal now, and now the virgin band\nQuaternion, their sweet psalmody began,\nWeeping; and Beatrice listen\'d, sad\nAnd sighing, to the song\', in such a mood,\nThat Mary, as she stood beside the cross,\nWas scarce more chang\'d.  But when they gave her place\nTo speak, then, risen upright on her feet,\nShe, with a colour glowing bright as fire,\nDid answer: \"Yet a little while, and ye\nShall see me not; and, my beloved sisters,\nAgain a little while, and ye shall see me.\"\n     Before her then she marshall\'d all the seven,\nAnd, beck\'ning only motion\'d me, the dame,\nAnd that remaining sage, to follow her.\n     So on she pass\'d; and had not set, I ween,\nHer tenth step to the ground, when with mine eyes\nHer eyes encounter\'d; and, with visage mild,\n\"So mend thy pace,\" she cried, \"that if my words\nAddress thee, thou mayst still be aptly plac\'d\nTo hear them.\"  Soon as duly to her side\nI now had hasten\'d:  \"Brother!\" she began,\n\"Why mak\'st thou no attempt at questioning,\nAs thus we walk together?\"  Like to those\nWho, speaking with too reverent an awe\nBefore their betters, draw not forth the voice\nAlive unto their lips, befell me shell\nThat I in sounds imperfect thus began:\n\"Lady!  what I have need of, t");

            struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "PREPARE.BIN");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, -1280, SEEK_END);

            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[2304] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[2304], c);

            free(filecontent);
            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 31: Sprawdzanie poprawności działania funkcji file_seek
//
void UTEST31(void)
{
    // informacje o teście
    test_start(31, "Sprawdzanie poprawności działania funkcji file_seek", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(447, 1);
            char expected_filecontent[448] = "";

            strcat(expected_filecontent, "ights mov\'d a voice,\nThat made me seem like needle to the star,\nIn turning to its whereabout, and thus\nBegan:  \"The love, that makes me beautiful,\nPrompts me to tell of th\' other guide, for whom\nSuch good of mine is spoken.  Where one is,\nThe other worthily should also be;\nThat as their warfare was alike, alike\nShould be their glory.  Slow, and full of doubt,\nAnd with thin ranks, after its banner mov\'d\nThe army of Christ (which it so clearly c");

            struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "VERB.TX");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, 41, SEEK_SET);
            file_seek(file, 28, SEEK_CUR);

            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[69] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[69], c);

            free(filecontent);
            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 32: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST32(void)
{
    // informacje o teście
    test_start(32, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "FEW");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (FEW) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 33: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST33(void)
{
    // informacje o teście
    test_start(33, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "LEVEL");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (LEVEL) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 34: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST34(void)
{
    // informacje o teście
    test_start(34, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "ENOUGH");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (ENOUGH) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 35: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST35(void)
{
    // informacje o teście
    test_start(35, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "BETTER");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (BETTER) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 36: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST36(void)
{
    // informacje o teście
    test_start(36, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "CARRY");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (CARRY) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 37: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST37(void)
{
    // informacje o teście
    test_start(37, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "MIDDLE");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (MIDDLE) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 38: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST38(void)
{
    // informacje o teście
    test_start(38, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "SHEKNOWM");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (SHEKNOWM) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 39: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST39(void)
{
    // informacje o teście
    test_start(39, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "LOUD");
            test_error(file == NULL, "Funkcja file_open() nie powinna otworzyć pliku o nazwie LOUD, ponieważ nie istnieje on w katalogu głównym");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 40: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST40(void)
{
    // informacje o teście
    test_start(40, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(NULL, "LOUD");
            test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL w przypadku podania błędnych danych");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 41: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST41(void)
{
    // informacje o teście
    test_start(41, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, NULL);
            test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL w przypadku podania błędnych danych");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 42: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST42(void)
{
    // informacje o teście
    test_start(42, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(NULL, NULL);
            test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL w przypadku podania błędnych danych");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 43: Sprawdzanie poprawności działania funkcji file_close
//
void UTEST43(void)
{
    // informacje o teście
    test_start(43, "Sprawdzanie poprawności działania funkcji file_close", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            file_close(NULL);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 44: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST44(void)
{
    // informacje o teście
    test_start(44, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "MONEY.TX");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            int res = file_read(NULL, 1, 1, file);
            test_error(res == -1, "Funkcja file_read() powinna zwrócić wartość -1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 45: Sprawdzanie poprawności działania funkcji dir_read
//
void UTEST45(void)
{
    // informacje o teście
    test_start(45, "Sprawdzanie poprawności działania funkcji dir_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            char* expected_names[14] = { "MONEY.TX", "SYSTEM.BIN", "VERB.TX", "FAMOUS.TXT", "HUNT.TXT", "PREPARE.BIN", "COMPLETE.TXT", "FEW", "LEVEL", "ENOUGH", "BETTER", "CARRY", "MIDDLE", "SHEKNOWM" };
            int found_names[14] = { 0 };

            struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct dir_t* pdir = dir_open(volume, "\\");
            test_error(pdir != NULL, "Funkcja dir_open() niepoprawnie otworzyła katalog");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            for (int i = 0; i < 14; ++i)
            {
                struct dir_entry_t entry;
                int res = dir_read(pdir, &entry);
                test_error(res == 0, "Funkcja dir_read() niepoprawnie odczytała wpis z katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int name_found = 0;

                for (int j = 0; j < 14; ++j)
                {
                    if (strcmp(entry.name, expected_names[j]) == 0)
                    {
                        test_error(found_names[j] == 0, "Funkcja dir_read() ponownie zwróciła informację o wpisie %s", expected_names[j]);
                        found_names[j] = 1;
                        name_found = 1;
                        break;
                    }
                }

                test_error(name_found == 1, "Funkcja dir_read() zwróciła informację o wpisie %s, który nie znajduje się w katalogu", entry.name);
            }

            struct dir_entry_t entry;
            int res = dir_read(pdir, &entry);
            test_error(res == 1, "Funkcja dir_read() zwróciła niepoprawną wartość, po odczytaniu wszystkich wpisów z katalogu powinna zwrócić %d, a zwróciła %d", 1, res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            dir_close(pdir);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 46: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST46(void)
{
    // informacje o teście
    test_start(46, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "MONEY.TX");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 47: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST47(void)
{
    // informacje o teście
    test_start(47, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "SYSTEM.BIN");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 48: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST48(void)
{
    // informacje o teście
    test_start(48, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "VERB.TX");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 49: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST49(void)
{
    // informacje o teście
    test_start(49, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "FAMOUS.TXT");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 50: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST50(void)
{
    // informacje o teście
    test_start(50, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "HUNT.TXT");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 51: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST51(void)
{
    // informacje o teście
    test_start(51, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "PREPARE.BIN");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 52: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST52(void)
{
    // informacje o teście
    test_start(52, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "COMPLETE.TXT");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 53: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST53(void)
{
    // informacje o teście
    test_start(53, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("edge_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct dir_t*  dir = dir_open(volume, "sail");
            test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}




enum run_mode_t { rm_normal_with_rld = 0, rm_unit_test = 1, rm_main_test = 2 };

int __wrap_main(volatile int _argc, char** _argv, char** _envp)
{
    int volatile vargc = _argc;
    char ** volatile vargv = _argv, ** volatile venvp = _envp;
	volatile enum run_mode_t run_mode = rm_unit_test; // -1
	volatile int selected_test = -1;

    if (vargc > 1)
	{
	    char* smode = strtok(vargv[1], ",");
	    char* stest = strtok(NULL, "");
		char *errptr = NULL;
		run_mode = (enum run_mode_t)strtol(smode, &errptr, 10);
		if (*errptr == '\x0')
		{
			memmove(vargv + 1, vargv + 2, sizeof(char*) * (vargc - 1));
			vargc--;

			if (stest != NULL)
			{
			    int val = (int)strtol(stest, &errptr, 10);
			    if (*errptr == '\x0')
			        selected_test = val;
			}
		}
	}

    // printf("runmode=%d; selected_test=%d\n", run_mode, selected_test);

    // inicjuj testy jednostkowe
    unit_test_init(run_mode, "unit_test_v2.c");
    test_limit_init();
    rldebug_set_reported_severity_level(MSL_FAILURE);

    if (run_mode == rm_normal_with_rld)
    {
        // konfiguracja ograniczników
        rldebug_reset_limits();
        

        // uruchom funkcję main Studenta a potem wyświetl podsumowanie sterty i zasobów
        volatile int ret_code = rdebug_call_main(tested_main, vargc, vargv, venvp);

        rldebug_reset_limits();
        

        int leaks_detected = rldebug_show_leaked_resources(0);
        if (leaks_detected)
            raise(SIGHEAP);

        return ret_code;
    }

    
    if (run_mode == rm_unit_test)
    {
        test_title("Testy jednostkowe");

        void (*pfcn[])(void) =
        { 
            UTEST1, // Sprawdzanie poprawności działania funkcji disk_open_from_file
            UTEST2, // Sprawdzanie poprawności działania funkcji disk_open_from_file
            UTEST3, // Sprawdzanie poprawności działania funkcji disk_close
            UTEST4, // Sprawdzanie poprawności działania funkcji fat_open
            UTEST5, // Sprawdzanie poprawności działania funkcji disk_open_from_file
            UTEST6, // Sprawdzanie poprawności działania funkcji file_read
            UTEST7, // Sprawdzanie poprawności działania funkcji file_read
            UTEST8, // Sprawdzanie poprawności działania funkcji file_read
            UTEST9, // Sprawdzanie poprawności działania funkcji file_read
            UTEST10, // Sprawdzanie poprawności działania funkcji file_read
            UTEST11, // Sprawdzanie poprawności działania funkcji file_read
            UTEST12, // Sprawdzanie poprawności działania funkcji file_read
            UTEST13, // Sprawdzanie poprawności działania funkcji file_read
            UTEST14, // Sprawdzanie poprawności działania funkcji file_read
            UTEST15, // Sprawdzanie poprawności działania funkcji file_read
            UTEST16, // Sprawdzanie poprawności działania funkcji file_read
            UTEST17, // Sprawdzanie poprawności działania funkcji file_read
            UTEST18, // Sprawdzanie poprawności działania funkcji file_read
            UTEST19, // Sprawdzanie poprawności działania funkcji file_read
            UTEST20, // Sprawdzanie poprawności działania funkcji file_read
            UTEST21, // Sprawdzanie poprawności działania funkcji file_read
            UTEST22, // Sprawdzanie poprawności działania funkcji file_read
            UTEST23, // Sprawdzanie poprawności działania funkcji file_read
            UTEST24, // Sprawdzanie poprawności działania funkcji file_read
            UTEST25, // Sprawdzanie poprawności działania funkcji file_read
            UTEST26, // Sprawdzanie poprawności działania funkcji file_read
            UTEST27, // Sprawdzanie poprawności działania funkcji file_read
            UTEST28, // Sprawdzanie poprawności działania funkcji file_read
            UTEST29, // Sprawdzanie poprawności działania funkcji file_seek
            UTEST30, // Sprawdzanie poprawności działania funkcji file_seek
            UTEST31, // Sprawdzanie poprawności działania funkcji file_seek
            UTEST32, // Sprawdzanie poprawności działania funkcji file_open
            UTEST33, // Sprawdzanie poprawności działania funkcji file_open
            UTEST34, // Sprawdzanie poprawności działania funkcji file_open
            UTEST35, // Sprawdzanie poprawności działania funkcji file_open
            UTEST36, // Sprawdzanie poprawności działania funkcji file_open
            UTEST37, // Sprawdzanie poprawności działania funkcji file_open
            UTEST38, // Sprawdzanie poprawności działania funkcji file_open
            UTEST39, // Sprawdzanie poprawności działania funkcji file_open
            UTEST40, // Sprawdzanie poprawności działania funkcji file_read
            UTEST41, // Sprawdzanie poprawności działania funkcji file_read
            UTEST42, // Sprawdzanie poprawności działania funkcji file_read
            UTEST43, // Sprawdzanie poprawności działania funkcji file_close
            UTEST44, // Sprawdzanie poprawności działania funkcji file_read
            UTEST45, // Sprawdzanie poprawności działania funkcji dir_read
            UTEST46, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST47, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST48, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST49, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST50, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST51, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST52, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST53, // Sprawdzanie poprawności działania funkcji dir_open
            NULL
        };

        for (int idx = 0; pfcn[idx] != NULL && !test_get_session_termination_flag(); idx++)
        {
            if (selected_test == -1 || selected_test == idx + 1)
                pfcn[idx]();

            // limit niezaliczonych testów, po jakim testy jednostkowe zostaną przerwane
            if (test_session_get_fail_count() >= 1000)
                test_terminate_session();
        }


        test_title("RLDebug :: Analiza wycieku zasobów");
        // sprawdź wycieki pamięci
        int leaks_detected = rldebug_show_leaked_resources(1);
        test_set_session_leaks(leaks_detected);

        // poinformuj serwer Mrówka o wyniku testu - podsumowanie
        test_title("Podsumowanie");
        if (selected_test == -1)
            test_summary(53); // wszystkie testy muszą zakończyć się sukcesem
        else
            test_summary(1); // tylko jeden (selected_test) test musi zakończyć się  sukcesem
        return EXIT_SUCCESS;
    }
    

    if (run_mode == rm_main_test)
    {
        test_title("Testy funkcji main()");

        void (*pfcn[])(int, char**, char**) =
        { 
            NULL
        };

        for (volatile int idx = 0; pfcn[idx] != NULL && !test_get_session_termination_flag(); idx++)
        {
            if (selected_test == -1 || selected_test == idx + 1)
                pfcn[idx](vargc, vargv, venvp);

            // limit niezaliczonych testów, po jakim testy jednostkowe zostaną przerwane
            if (test_session_get_fail_count() >= 1000)
                test_terminate_session();
        }


        test_title("RLDebug :: Analiza wycieku zasobów");
        // sprawdź wycieki pamięci
        int leaks_detected = rldebug_show_leaked_resources(1);
        test_set_session_leaks(leaks_detected);

        // poinformuj serwer Mrówka o wyniku testu - podsumowanie
        test_title("Podsumowanie");
        if (selected_test == -1)
            test_summary(0); // wszystkie testy muszą zakończyć się sukcesem
        else
            test_summary(1); // tylko jeden (selected_test) test musi zakończyć się  sukcesem

        return EXIT_SUCCESS;
    }

    printf("*** Nieznana wartość RunMode: %d", (int)run_mode);
    abort();
}
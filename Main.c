/*
 ============================================================================
 Name        : Main.c
 Author      : Jesse Bannon
 Class       : TCSS 372 - Computer Architecture
 School      : University of Washington Tacoma
 Copyright   : Use only for educational purposes and do not modify file.
 Description : Reads in a .csv of address traces and simulates a
               five-level cache hierarchy and two CPUs.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "CacheSimulator.h"

int main(void) {
    threadInfo t1 = { 0 };
    threadInfo t2 = { 1 };
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, (void*)&readAddressTraces, (void*)&t1);
    pthread_create(&thread2, NULL, (void*)&readAddressTraces, (void*)&t2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printCacheMetrics();
    return 0;
}

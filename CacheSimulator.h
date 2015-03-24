/*
 ============================================================================
 Name        : CacheSimulator.h
 Author      : Jesse Bannon
 Class       : TCSS 372 - Computer Architecture
 School      : University of Washington Tacoma
 Copyright   : Use only for educational purposes and do not modify file.
 Description : Reads in a .csv of address traces and simulates a
               five-level cache hierarchy and two CPUs.
 ============================================================================
 */

#ifndef CACHESIMULATOR_H_
#define CACHESIMULATOR_H_

/* Cache line size in bytes (log base two). */
#define CL_SIZE 16

/* Sizes in entries (log base two). */
#define L1_SIZE 16
#define L2_SIZE 32
#define L3_SIZE 512
#define M1_SIZE 16384
#define M2_SIZE 1048576

/* Latencies in nanoseconds. */
#define L1_LATENCY 1
#define L2_LATENCY 10
#define L3_LATENCY 35
#define M1_LATENCY 100
#define M2_READ_LATENCY 250
#define M2_WRITE_LATENCY 400

/* Cache Associativity for n-way (log base two). */
#define CACHE_ASSOCIATIVITY 1

/* .csv file of address traces */
static char* FILE_NAME = "trace-5k.csv";


/* Struct to pass to pthread */
typedef struct thread_node {
    int cpu;
} threadInfo;

void readAddressTraces(void *info);
/*  Takes in a pointer to a threadInfo struct and reads the addresses
    from the .csv file fileName and assigns it to a cpu (int cpu).    
*/

void printCacheMetrics();
/* Prints all metrics recorded from readAddressTraces. 
*/

#endif

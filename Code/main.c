/**
 * @file main.c
 */
/**
 * @author Emily Bodenhamer
 *  CWU ID 41119306
 *  CS 495
 *  Date 9/15/2019
 *
 *  This project implements the Dragonfly meta-heuristic optimization algorithm.
 *
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "mt19937ar.h"
//#include "src/pcg_variants.h"
#include "Util.h"
#include "ArrayMem.h"
#include "DA.h"
//#include "src/entropy.h"
//#include <math.h>

int main() {
    // declare variables
    init_genrand(time(0));
//    uint64_t seeds[2];
//    entropy_getbytes((void*)seeds, sizeof(seeds));
//    pcg32_srandom(seeds[0], seeds[1]);
//    double d = ldexp(pcg32_random(), -32);
//        double hmm = pcg32_boundedrand(10);
//        printf("%lf\n",d);

    int NS = 0; //!< number of solutions
    int DIM = 0; //!< number of dimensions
    int iterations = 0; //!< number of iterations
    int fitnessCallCounter = 0; //!< function call counter

    // open our file
    FILE *DAFile;
    DAFile = fopen("DAFile.txt", "r");
    // check if our file exists
    if (DAFile == NULL) {
        printf("Error opening DAFile.txt file, "
               "make sure the file is in the cmake-build-debug folder\n");
        exit(-1);
    }

    // get the data from the files
    while (!feof(DAFile)) {
        // read values and save them to the DA struct
        fscanf(DAFile, "%d %d %d",
               &iterations, &NS,
               &DIM);
    }
    // close the file
    fclose(DAFile);

    // create structure object
    initData *myData;
    myData = (initData *) calloc(1, sizeof(initData));

    // starting DA
    readInput(myData, NS, DIM, iterations, fitnessCallCounter);

    return 0;
}

//gcc -fopenmp main.c ArrayMem.c DA.c Functions.c mt19937ar.c SelectFunctions.c Util.c -o main
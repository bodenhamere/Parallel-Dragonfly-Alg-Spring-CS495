/**
 * @file Util.c
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

#include <float.h>
#include <stdio.h>
#include <omp.h>
#include <time.h>
#include "Util.h"

/**
 * find the minimal value in a vector
 * \param a an array
 * \param NS the number of solutions/size of a vector
 * \return a array with array b's elements implemented
 */
void findBest(double* bestArr, const double *a, int NS){
    double best = DBL_MAX;
    int index = -1;
    for (int i = 0; i < NS; ++i) {
        if (a[i] <= best) {
            best = a[i];
            index = i;
        }
    }
    bestArr[0] = best;
    bestArr[1] = index;
}

/**
 * find the worst value in a vector
 * \param a an array
 * \param NS the number of solutions/size of a vector
 * \return a array with array b's elements implemented
 */
void findWorst(double* worstArr, const double *a, int NS){
    double worst = -DBL_MAX;
    int index = -1;

    for (int i = 0; i < NS; ++i) {
        if (a[i] >= worst) {
            worst = a[i];
            index = i;
        }
    }

    worstArr[0] = worst;
    worstArr[1] = index;
}


/**
 * print out a vector to a file
 * \param file a file to print to
 * \param a an array
 * \param DIM the number of dimensions/size of a vector
 */
void printSingle(FILE *file, double *a, int DIM){
    for (int i = 0; i < DIM; ++i) {
        fprintf(file, "%lf, ", a[i]);
    }
    fprintf(file, "\n");
}

void checkBounds(initData *myData, double array){
    if (array > myData->max)
        array = myData->max;
    if (array < myData->min)
        array = myData->min;
}
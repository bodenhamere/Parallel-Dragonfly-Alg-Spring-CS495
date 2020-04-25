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
#include "Util.h"

/**
 * sort the population in ascending order
 * @param myData the data structure
 * @param NS the number of solutions/size of a vector
 * @param DIM the size of the dimensions/size of a vector
 * @param b temporary vector to hold elements
 */
void sortAscendingOrder(initData *myData, const int NS, const int DIM, double *b) {
    double a;
    for (int i = 0; i < NS; ++i) {
        for (int j = i + 1; j < NS; ++j) {
            if (myData->fitness[i] > myData->fitness[j]) {
                a = myData->fitness[i];
                b = replaceArray(b, myData->population[i], DIM);
                myData->fitness[i] = myData->fitness[j];
                myData->population[i] = myData->population[j];
                myData->fitness[j] = a;
                myData->population[j] = replaceArray(myData->population[j], b, DIM);
            }
        }
    }
}

/**
 * replace the elements of one array into another
 * \param a an array
 * \param b an array
 * \param NS the number of solutions/size of a vector
 * \return a array with array b's elements implemented
 */
double *replaceArray(double *a, const double *b, const int NS) {
    for (int i = 0; i < NS; ++i) {
        a[i] = b[i];
    }
    return a;
}

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
 * copy a arrays contents to another
 * \param a a double array
 * \param b a double array
 * \param DIM the number of dimensions/size of a vector
 * \param NS the number of solutions/size of a vector
 * \return a double array with double array b's contents placed into
 */
double ** copyDbl(double **a, double **b, int NS, int DIM){
    for (int i = 0; i < NS; ++i) {
        for (int j = 0; j < DIM; ++j) {
            a[i][j] = b[i][j];
        }

    }
    return a;
}

/**
 * copy a arrays contents to another
 * \param a an array
 * \param b an array
 * \param DIM the number of dimensions/size of a vector
 * \return a array with array b's contents placed into
 */
double * copySingle(double *a, const double *b, int DIM){
    for (int j = 0; j < DIM; ++j) {
        a[j] = b[j];
    }
    return a;
}

/**
 * print out a matrix with dimensions
 * printed out horizontally to a file
 * \param file file to print to
 * \param a an array
 * \param DIM the number of dimensions/size of a vector
 * \param NS the number of solutions/size of a vector
 */
void printDblDim(FILE *file, double **a, int DIM, int NS){
    for (int i = 0; i < DIM; ++i) {
        for (int j = 0; j < NS; ++j) {
            fprintf(file, "%lf, ", a[j][i]);
        }
        fprintf(file, "\n");
    }
    fprintf(file, "\n");
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
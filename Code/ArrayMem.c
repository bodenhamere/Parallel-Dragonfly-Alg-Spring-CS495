/**
 * @file ArrayMem.c
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
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <time.h>
#include "ArrayMem.h"
#include "mt19937ar.h"

/**
 * Generates a double pointer array that has pointer to a single pointer array
 * The arrays are initialized to 0 by using calloc()
 * \param col the size of the columns of the array
 * \param row the size of the rows of the array
 * \return double pointer array
 */
double **createDblArray(int row, int col) {
    double **matrix = (double **) calloc(row, sizeof(double *));
    for (int i = 0; i < row; i++) {
        matrix[i] = singleArray(col);
    }
    return matrix;
}

/**
 * Generates a single pointer array
 * The array are initialized to 0 by using calloc()
 * \param n the size of the rows of the array
 * \return single pointer array
 */
double *singleArray(int n) {
    double *arr = (double *) calloc(n, sizeof(double));
    return arr;
}

/**
 * Fills in a double pointer array with the MersenneTwister random numbers from a specified range
 * \param arr double pointer array
 * \param row the size of the rows of the array
 * \param col the size of the columns of the array
 * \param min the minimum size of the random numbers
 * \param max the maximum size of the random numbers
 * \return double pointer array
 */
double **fillIn(double **arr, int row, int col, double min, double max) {
    // start the clock
    clock_t start;
    start = clock();
    int j;
    int i;
#pragma omp parallel for private(j) num_threads(1)
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            arr[i][j] = (max - (min)) * (genrand_real1()) + min;
        }
    }
    start = (((clock() - start)));
    //milisec
//    printf("\nPop Init took: %lf millisecs.\n", ((((double) start) / CLOCKS_PER_SEC) * 1000));
//    //microsec
//    printf("\nPop Init took: %lf microsecs.\n", ((((double) start) / CLOCKS_PER_SEC) * 1000000));

    return arr;
}

/**
 * Free the memory used for a double pointer array
 * \param matrix double pointer array
 * \param row the size of the rows of the array
 */
void freeMem(int row, double **matrix) {
    for (int i = 0; i < row; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

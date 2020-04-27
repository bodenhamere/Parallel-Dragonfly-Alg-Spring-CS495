    /**
 * @file SelectFunctions.c
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
#include <time.h>
#include <stdio.h>
#include <omp.h>
#include "Functions.h"

/**
 * Calls an f(x) function based on if the counter is at a certain number
 * The arr is passed to the function and saved into a single pointer array
 * \param results single pointer array
 * \param arr double pointer array
 * \param row the size of the rows of the array
 * \param col the size of the columns of the array
 * \param counter the case specified
 */
double *getFun(double *results, double **arr, int row, int col, int counter) {
    clock_t start;
    start = clock();
    switch (counter) {
        case 0:
            #pragma omp parallel for num_threads(4)
            for (int i = 0; i < row; i++) {
                results[i] = schwefel(arr[i], col);
            }
            break;
        case 1:
            #pragma omp parallel for num_threads(4)
            for (int i = 0; i < row; i++) {
                results[i] = deJong(arr[i], col);
            }
            break;
        case 2:
            #pragma omp parallel for num_threads(4)
            for (int i = 0; i < row; i++) {
                results[i] = rosenbrock(arr[i], col);
            }
            break;
        case 3:
            #pragma omp parallel for num_threads(4)
            for (int i = 0; i < row; i++) {
                results[i] = rastrigin(arr[i], col);
            }
            break;
        case 4:
            #pragma omp parallel for num_threads(4)
            for (int i = 0; i < row; i++) {
                results[i] = griewangk(arr[i], col);
            }
            break;
        case 5:
            #pragma omp parallel for num_threads(4)
            for (int i = 0; i < row; i++) {
                results[i] = sineEnvelope(arr[i], col);
            }
            break;
        case 6:
            #pragma omp parallel for num_threads(4)
            for (int i = 0; i < row; i++) {
                results[i] = sineStretched(arr[i], col);
            }
            break;
        case 7:
            #pragma omp parallel for num_threads(4)
            for (int i = 0; i < row; i++) {
                results[i] = ackley1(arr[i], col);
            }
            break;
        case 8:
#pragma omp parallel for num_threads(4)
            for (int i = 0; i < row; i++) {
                results[i] = ackley2(arr[i], col);
            }
            break;
        case 9:
            #pragma omp parallel for num_threads(4)
            for (int i = 0; i < row; i++) {
                results[i] = eggHolder(arr[i], col);
            }
            break;
        case 10:
            #pragma omp parallel for num_threads(4)
            for (int i = 0; i < row; i++) {
                results[i] = rana(arr[i], col);
            }
            break;
        case 11:
            #pragma omp parallel for num_threads(4)
            for (int i = 0; i < row; i++) {
                results[i] = pathological(arr[i], col);
            }
            break;
        case 12:
            #pragma omp parallel for num_threads(4)
            for (int i = 0; i < row; i++) {
                results[i] = michalewicz(arr[i], col);
            }
            break;
        case 13:
            #pragma omp parallel for num_threads(4)
            for (int i = 0; i < row; i++) {
                results[i] = masters(arr[i], col);
            }
            break;
        case 14:
            #pragma omp parallel for num_threads(4)
            for (int i = 0; i < row; i++) {
                results[i] = quartic(arr[i], col);
            }
            break;
        case 15:
            #pragma omp parallel for num_threads(4)
            for (int i = 0; i < row; i++) {
                results[i] = step(arr[i], col);
            }
            break;
        case 16:
            #pragma omp parallel for num_threads(4)
            for (int i = 0; i < row; i++) {
                results[i] = alpine(arr[i], col);
            }
            break;
        case 17:
            #pragma omp parallel for num_threads(4)
            for (int i = 0; i < row; i++) {
                results[i] = levy(arr[i], col);
            }
    }
        start = (((clock() - start)));
        //milisec
        printf("\nPop Init took: %lf millisecs.\n", ((((double) start) / CLOCKS_PER_SEC) * 1000));
        //microsec
        printf("\nPop Init took: %lf microsecs.\n", ((((double) start) / CLOCKS_PER_SEC) * 1000000));

        return results;
}

/**
 * Calls an f(x) function based on if the counter is at a certain number
 * The arr is passed to the function and saved into a single pointer array
 * \param results a double
 * \param arr single pointer array
 * \param row the size of the rows of the array
 * \param counter the case specified
 */
double getFunSingle(double results, double *arr, int row, int counter) {
    switch (counter) {
        case 0:
            results = schwefel(arr, row);
            break;
        case 1:
            results = deJong(arr, row);
            break;
        case 2:
            results = rosenbrock(arr, row);
            break;
        case 3:
            results = rastrigin(arr, row);
            break;
        case 4:
            results = griewangk(arr, row);
            break;
        case 5:
            results = sineEnvelope(arr, row);
            break;
        case 6:
            results = sineStretched(arr, row);
            break;
        case 7:
            results = ackley1(arr, row);
            break;
        case 8:
            results = ackley2(arr, row);
            break;
        case 9:
            results = eggHolder(arr, row);
            break;
        case 10:
            results = rana(arr, row);
            break;
        case 11:
            results = pathological(arr, row);
            break;
        case 12:
            results = michalewicz(arr, row);
            break;
        case 13:
            results = masters(arr, row);
            break;
        case 14:
            results = quartic(arr, row);
            break;
        case 15:
            results = step(arr, row);

            break;
        case 16:
            results = alpine(arr, row);
            break;
        case 17:
            results = levy(arr, row);
    }
    return results;
}
cmake_minimum_required(VERSION 3.13)
project(Parallel_DA C)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -fopenmp")
set(CMAKE_C_STANDARD 99)

add_executable(Parallel_DA main.c ArrayMem.c
        ArrayMem.h Functions.c Functions.h
        mt19937ar.h mt19937ar.c SelectFunctions.c
        SelectFunctions.h DA.c DA.h Util.c Util.h)
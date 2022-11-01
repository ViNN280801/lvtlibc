#pragma once

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "lvtlib.h"

#ifndef _PRINT_FUNCTIONS_
// Prints array on terminal
void print_int_arr(const int *__parr, const size_t __arr_size);
#endif

#ifndef _MEMORY_
#ifndef _CHECK_ALLOCATING_
// Returns "true" if memory for int
// array was allocated correctly
// Otherwise returns "false"
bool is_alloc_pint(const int *__p);

// Returns "true" if memory for float
// array was allocated correctly
// Otherwise returns "false"
bool is_alloc_pfloat(const float *__p);

// Returns "true" if memory for double
// array was allocated correctly
// Otherwise returns "false"
bool is_alloc_pdouble(const double *__p);

// Returns "true" if memory for char
// array was allocated correctly
// Otherwise returns "false"
bool is_alloc_pchar(const char *__p);
#endif

#ifndef _ALLOCATING_
// Allocates memory for int array with cheking on correctness
// Exiting with status '-1' if can't allocate memory
int *alloc_mem_pint(const size_t __arr_size);

// Allocates memory for float array with cheking on correctness
// Exiting with status '-1' if can't allocate memory
float *alloc_mem_pfloat(const size_t __arr_size);

// Allocates memory for double array with cheking on correctness
// Exiting with status '-1' if can't allocate memory
double *alloc_mem_pdouble(const size_t __arr_size);

// Allocates memory for char array with cheking on correctness
// Exiting with status '-1' if can't allocate memory
char *alloc_mem_pchar(const size_t __arr_size);
#endif

#ifndef _DEALLOCATING_
// Deallocating memory of int pointer
void dealloc_mem_pint(int *__p);

// Deallocating memory of float pointer
void dealloc_mem_pfloat(float *__p);

// Deallocating memory of double pointer
void dealloc_mem_pdouble(double *__p);

// Deallocating memory of char pointer
void dealloc_mem_pchar(char *__p);
#endif
#endif

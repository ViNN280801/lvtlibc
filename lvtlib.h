#pragma once

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#ifndef _PRINT_FUNCTIONS_
// Prints array on terminal (other types is similar)
void print_pint(const int *__parr, const size_t __arr_size);

// Prints matrix on terminal (other types is similar)
void print_ppint(int **__pp, const size_t __rows, const size_t __cols);
#endif

#ifndef _MEMORY_
#ifndef _CHECK_ALLOCATING_
// Returns "true" if memory for int
// array was allocated correctly
// Otherwise returns "false" (other types is similar)
bool is_alloc_pint(const int *__p);

// Return "true" if memory of matrix allocated correctly  (other types is similar)
bool is_alloc_ppint(const int **__pp, const size_t __rows);

// Returns "true" if memory for double
// array was allocated correctly
// Otherwise returns "false" (other types is similar)
bool is_alloc_pdouble(const double *__p);

// Return "true" if memory of matrix allocated correctly  (other types is similar)
bool is_alloc_ppdouble(const double **__pp, const size_t __rows);
#endif

#ifndef _ALLOCATING_
// Allocates memory for int array with cheking on correctness
// Exiting with status '-1' if can't allocate memory (other types is similar)
int *alloc_mem_pint(const size_t __arr_size);

// Allocates memory to matrix with checkings on correctness of allocating
// Returns pointer on a matrix of integer values (other types is similar)
int **alloc_mem_ppint(const size_t __rows, const size_t __cols);

// Allocates memory for 'double' array with cheking on correctness
// Exiting with status '-1' if can't allocate memory (other types is similar)
double *alloc_mem_pdouble(const size_t __arr_size);

// Allocates memory to matrix with checkings on correctness of allocating
// Returns pointer on a matrix of doubles values
double **alloc_mem_ppdouble(const size_t __rows, const size_t __cols);
#endif

#ifndef _DEALLOCATING_
// Deallocating memory of int pointer (other types is similar)
void dealloc_mem_pint(int *__p);

// Deallocating memory of '__pp' pointer (other types is similar)
void dealloc_mem_ppint(int **__pp, const size_t __rows);
#endif
#endif

#ifndef _INPUT_
// Handles an error when a user enters a character or string
// when asked to enter a number. Returns the number entered by the user
int input_int();

// Handles an error when a user enters a character or string
// when asked to enter a number. Returns the double number entered by the user
double input_double();

// Returns an integer array, which is filled with a manually entered values
int *input_manual_pint(const size_t __size);

// Returns an integer array, which is filled with a random numbers
// "rand % __num1" returns numbers from 0 to '__num1'
// adding '__num2' gives number between '__num2' and '__num1 + __num2'
int *input_random_pint(const size_t __size, const int __num1, const int __num2);

// Returns an integer matrix, which is filled with a manually entered values
int **input_manual_ppint(const size_t __rows, const size_t __cols);

// Returns an integer matrix, which is filled with a random numbers
int **input_random_ppint(const size_t __rows, const size_t __cols, const int __num1, const int __num2);

// Returns a 'double' array, which is filled with a random numbers
double *input_random_pdouble(const size_t __size, const double __min, const double __max);

// Returns a 'double' matrix, which is filled with a random numbers
double **input_random_ppdouble(const size_t __rows, const size_t __cols, const double __min, const double __max);
#endif

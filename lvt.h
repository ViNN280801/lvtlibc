#ifndef LVT_H
#define LVT_H

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define FOR_INT(n) for (int i = 0; i < n; i++)
#define FOR_SIZE_T(n) for (size_t i = 0UL; i < n; i++)
#define FOR_INT_FROM_TO(from, to) for (int i = from; i < to; i++)
#define FOR_SIZE_T_FROM_TO(from, to) for (size_t i = from; i < to; i++)
#define ARRSIZE(arr) sizeof arr / sizeof *(arr)
#define FOREACH_INT(item, array)    \
    for (int keep = 1,              \
             count = 0,             \
             size = ARRSIZE(array); \
         keep && count != size;     \
         keep = !keep, count++)     \
        for (item = (array) + count; keep; keep = !keep)
#define FOREACH_SIZE_T(item, array)    \
    for (size_t keep = 1UL,            \
                count = 0UL,           \
                size = ARRSIZE(array); \
         keep && count != size;        \
         keep = !keep, count++)        \
        for (item = (array) + count; keep; keep = !keep)
#define SWAP(x, y)                                                                \
    while (true)                                                                  \
    {                                                                             \
        unsigned char swap_temp[sizeof(x) == sizeof(y) ? (signed)sizeof(x) : -1]; \
        memcpy(swap_temp, &y, sizeof(x));                                         \
        memcpy(&y, &x, sizeof(x));                                                \
        memcpy(&x, swap_temp, sizeof(x));                                         \
    }

#ifndef _PRINT_FUNCTIONS_
// Prints array on terminal (other types is similar)
void print_pint(int *, size_t);

// Prints matrix on terminal (other types is similar)
void print_ppint(int **, size_t, size_t);
#endif // _PRINT_FUNCTIONS_

#ifndef _MEMORY_
#ifndef _CHECK_ALLOCATING_
// Returns "true" if memory for int
// array was allocated correctly
// Otherwise returns "false" (other types is similar)
bool is_alloc_pint(int *);

// Return "true" if memory of matrix allocated correctly  (other types is similar)
bool is_alloc_ppint(int **, size_t);

// Returns "true" if memory for char
// array was allocated correctly
// Otherwise returns "false" (other types is similar)
bool is_alloc_pchar(const char *__p);

// Returns "true" if memory for double
// array was allocated correctly
// Otherwise returns "false" (other types is similar)
bool is_alloc_pdouble(double *);

// Return "true" if memory of matrix allocated correctly  (other types is similar)
bool is_alloc_ppdouble(double **, size_t);
#endif // _CHECK_ALLOCATING_

#ifndef _ALLOCATING_
// Allocates memory for int array with cheking on correctness
// Exiting with status '-1' if can't allocate memory (other types is similar)
int *alloc_mem_pint(size_t);

// Allocates memory to matrix with checkings on correctness of allocating
// Returns pointer on a matrix of integer values (other types is similar)
int **alloc_mem_ppint(size_t, size_t);

// Allocates memory for 'double' array with cheking on correctness
// Exiting with status '-1' if can't allocate memory (other types is similar)
double *alloc_mem_pdouble(size_t);

// Allocates memory to matrix with checkings on correctness of allocating
// Returns pointer on a matrix of doubles values
double **alloc_mem_ppdouble(size_t, size_t);
#endif // _ALLOCATING_

#ifndef _DEALLOCATING_
// Deallocating memory of int pointer (other types is similar)
void dealloc_mem_pint(int *__p);

// Deallocating memory of pointer (other types is similar)
void dealloc_mem_ppint(int **, size_t);

// Deallocating memory of char pointer (other types is similar)
void dealloc_mem_pchar(char *);
#endif // _DEALLOCATING_
#endif // _MEMORY_

#ifndef _INPUT_
// Handles an error when a user enters a character or string
// when asked to enter a number. Returns the number entered by the user
int input_int();

// Handles an error when a user enters a character or string
// when asked to enter a number. Returns the double number entered by the user
double input_double();

// Returns an integer array, which is filled with a manually entered values
int *input_manual_pint(size_t);

// Returns an integer array, which is filled with a random numbers
// "rand % __num1" returns numbers from 0 to '__num1'
// adding '__num2' gives number between '__num2' and '__num1 + __num2'
int *input_random_pint(size_t, int, int);

// Returns an integer matrix, which is filled with a manually entered values
int **input_manual_ppint(size_t, size_t);

// Returns an integer matrix, which is filled with a random numbers
int **input_random_ppint(size_t, size_t, int, int);

// Returns a 'double' array, which is filled with a random numbers
double *input_random_pdouble(size_t, double, double);

// Allocates memory for char array with cheking on correctness
// Exiting with status '-1' if can't allocate memory (other types is similar)
char *alloc_mem_pchar(size_t);

// Returns a 'double' matrix, which is filled with a random numbers
double **input_random_ppdouble(size_t, size_t, double, double);
#endif // _INPUT_

#ifndef _ALGORITHMS_
// Return count of digits of specified number
int get_count_of_digits_in_number(int);

// Return count of digits of specified number (using math.h)
int get_count_of_digits_in_number_v2(int);

// Return array of digits of a number in descending order
int *split_number_on_digits(int);

// Reversing number
void reverse_pint(int *, int);

// Returns char array from integer value
char *int_to_pchar(int);

// Returns "true" if passed argument 'num' is a prime number
bool is_prime(int);

// Sorting 1d array by bubble sorting algorithm
void bubbleSortAscending(int[]);

// Sorting matrix with bubble sort algorithm
void bubbleSortMatrixAscending(int **, size_t, size_t);

// Sorting elems in array. Best case - O(n). Middle and worst cases - O(n^2)
void insertionSortAscending(int[]);

// Sorting elems in matrix. Best case - O(n). Middle and worst cases - O(n^2)
void insertionSortMatrixAscending(int**, size_t, size_t);

// Sorting array by selection algorithm (the lowest perfonamce algorithm)
void selectionSortAscending(int[]);

// Sorting matrix by selection algorithm
void selectionSortMatrixAscending(int **, size_t, size_t);

// Sorting array by Shell sorting algorithm
void ShellSortAscending(int[]);

// Sorting matrix by Shell sorting algorithm
void ShellSortMatrixAscending(int **, size_t, size_t);

// Auxiliary method for quick sort algortihm
void qSortAscending(int[], size_t, size_t);

// Sorting array by quick sorting (Hoare sort) algorithm
void quickSortAscending(int[]);

// Sorting matrix by quick sorting (Hoare sort) algorithm
void quickSortMatrixAscending(int **, size_t, size_t);

// Sorting elems in array. Best case - O(n). Middle and worst cases - O(n^2)
void insertionSortDescending(int[]);

// Sorting array by selection algorithm (the lowest perfonamce algorithm)
void selectionSortDescending(int[]);

// Sorting array by Shell sorting algorithm
void ShellSortDescending(int[]);

// Auxiliary method for quick sort algortihm
void qSortDescending(int[], size_t, size_t);

// Sorting array by quick sorting (Hoare sort) algorithm
void quickSortDescending(int[]);

// Converting int matrix to an array
void matrixToArr(int **, int *, size_t, size_t);

void arrayToMatrix(int *, int **, size_t, size_t);
#endif // _ALGORITHMS_

#endif // !LVT_H

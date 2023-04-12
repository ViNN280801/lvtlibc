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
#define FOREACH_INT(item, array)                    \
    for (int keep = 1,                              \
             count = 0,                             \
             size = sizeof array / sizeof *(array); \
         keep && count != size;                     \
         keep = !keep, count++)                     \
        for (item = (array) + count; keep; keep = !keep)
#define FOREACH_SIZE_T(item, array)                    \
    for (size_t keep = 1UL,                            \
                count = 0UL,                           \
                size = sizeof array / sizeof *(array); \
         keep && count != size;                        \
         keep = !keep, count++)                        \
        for (item = (array) + count; keep; keep = !keep)
        
#define ARRSIZE(arr) sizeof arr / sizeof arr[0]
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
void print_pint(const int *, const size_t);

// Prints matrix on terminal (other types is similar)
void print_ppint(int **, const size_t, const size_t);
#endif // _PRINT_FUNCTIONS_

#ifndef _MEMORY_
#ifndef _CHECK_ALLOCATING_
// Returns "true" if memory for int
// array was allocated correctly
// Otherwise returns "false" (other types is similar)
bool is_alloc_pint(const int *);

// Return "true" if memory of matrix allocated correctly  (other types is similar)
bool is_alloc_ppint(const int **, const size_t);

// Returns "true" if memory for char
// array was allocated correctly
// Otherwise returns "false" (other types is similar)
bool is_alloc_pchar(const char *__p);

// Returns "true" if memory for double
// array was allocated correctly
// Otherwise returns "false" (other types is similar)
bool is_alloc_pdouble(const double *);

// Return "true" if memory of matrix allocated correctly  (other types is similar)
bool is_alloc_ppdouble(const double **, const size_t);
#endif // _CHECK_ALLOCATING_

#ifndef _ALLOCATING_
// Allocates memory for int array with cheking on correctness
// Exiting with status '-1' if can't allocate memory (other types is similar)
int *alloc_mem_pint(const size_t);

// Allocates memory to matrix with checkings on correctness of allocating
// Returns pointer on a matrix of integer values (other types is similar)
int **alloc_mem_ppint(const size_t, const size_t);

// Allocates memory for 'double' array with cheking on correctness
// Exiting with status '-1' if can't allocate memory (other types is similar)
double *alloc_mem_pdouble(const size_t);

// Allocates memory to matrix with checkings on correctness of allocating
// Returns pointer on a matrix of doubles values
double **alloc_mem_ppdouble(const size_t, const size_t);
#endif // _ALLOCATING_

#ifndef _DEALLOCATING_
// Deallocating memory of int pointer (other types is similar)
void dealloc_mem_pint(int *__p);

// Deallocating memory of pointer (other types is similar)
void dealloc_mem_ppint(int **, const size_t);

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
int *input_manual_pint(const size_t);

// Returns an integer array, which is filled with a random numbers
// "rand % __num1" returns numbers from 0 to '__num1'
// adding '__num2' gives number between '__num2' and '__num1 + __num2'
int *input_random_pint(const size_t, const int, const int);

// Returns an integer matrix, which is filled with a manually entered values
int **input_manual_ppint(const size_t, const size_t);

// Returns an integer matrix, which is filled with a random numbers
int **input_random_ppint(const size_t, const size_t, const int, const int);

// Returns a 'double' array, which is filled with a random numbers
double *input_random_pdouble(const size_t, const double, const double);

// Allocates memory for char array with cheking on correctness
// Exiting with status '-1' if can't allocate memory (other types is similar)
char *alloc_mem_pchar(const size_t);

// Returns a 'double' matrix, which is filled with a random numbers
double **input_random_ppdouble(const size_t, const size_t, const double, const double);
#endif // _INPUT_

#ifndef _ALGORITHMS_
// Return count of digits of specified number
int get_count_of_digits_in_number(int);

// Return count of digits of specified number (using math.h)
int get_count_of_digits_in_number_v2(int);

// Return array of digits of a number in descending order
int *split_number_on_digits(int);

// Reversing number
void reverse_pint(int *, const int);

// Returns char array from integer value
char *int_to_pchar(int);

// Returns "true" if passed argument 'num' is a prime number
bool is_prime(const int num);
#endif // _ALGORITHMS_

#endif // !LVT_H

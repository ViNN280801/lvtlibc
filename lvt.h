#ifndef LVT_H
#define LVT_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

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
/// @brief Prints array on terminal (other types is similar)
void print_pint(int *, size_t);

/// @brief Prints matrix on terminal (other types is similar)
void print_ppint(int **, size_t, size_t);
#endif // _PRINT_FUNCTIONS_

#ifndef _MEMORY_
#ifndef _CHECK_ALLOCATING_
/// @return "true" if memory for int
/// array was allocated correctly
/// Otherwise returns "false" (other types is similar)
bool is_alloc_pint(int *);

/// @return "true" if memory of matrix allocated correctly  (other types is similar)
bool is_alloc_ppint(int **, size_t);

/// @return Returns "true" if memory for char
/// array was allocated correctly
/// Otherwise returns "false" (other types is similar)
bool is_alloc_pchar(const char *__p);

/// @return "true" if memory for double
/// of array was allocated correctly
/// Otherwise returns "false" (other types is similar)
bool is_alloc_pdouble(double *);

/// @brief Checker for correctly allocating of memory
/// @return "true" if memory of matrix allocated correctly  (other types is similar)
bool is_alloc_ppdouble(double **, size_t);
#endif // _CHECK_ALLOCATING_

#ifndef _ALLOCATING_
/// @brief Allocates memory for int array with cheking on correctness
/// Exiting with status '-1' if can't allocate memory (other types is similar)
int *alloc_mem_pint(size_t);

/// @brief Allocates memory to matrix with checkings on correctness of allocating
/// @return Pointer on a matrix of integer values (other types is similar)
int **alloc_mem_ppint(size_t, size_t);

/// @brief Allocates memory for 'double' array with cheking on correctness
/// Exiting with status '-1' if can't allocate memory (other types is similar)
double *alloc_mem_pdouble(size_t);

/// @brief Allocates memory to matrix with checkings on correctness of allocating
/// @return Pointer on a matrix of doubles values
double **alloc_mem_ppdouble(size_t, size_t);
#endif // _ALLOCATING_

#ifndef _DEALLOCATING_
/// @brief Deallocating memory of int pointer (other types is similar)
void dealloc_mem_pint(int *__p);

/// @brief Deallocating memory of pointer (other types is similar)
void dealloc_mem_ppint(int **, size_t);

/// @brief Deallocating memory of char pointer (other types is similar)
void dealloc_mem_pchar(char *);
#endif // _DEALLOCATING_
#endif // _MEMORY_

#ifndef _INPUT_
/// @brief Handles an error when a user enters a character or string
/// when asked to enter a number. Returns the number entered by the user
int input_int();

/// @brief Handles an error when a user enters a character or string
/// when asked to enter a number. Returns the double number entered by the user
double input_double();

/// @return an integer array, which is filled with a manually entered values
int *input_manual_pint(size_t);

/// @return an integer array, which is filled with a random numbers
/// "rand % __num1" returns numbers from 0 to '__num1'
/// adding '__num2' gives number between '__num2' and '__num1 + __num2'
int *input_random_pint(size_t, int, int);

/// @return an integer matrix, which is filled with a manually entered values
int **input_manual_ppint(size_t, size_t);

/// @return an integer matrix, which is filled with a random numbers
int **input_random_ppint(size_t, size_t, int, int);

/// @return a 'double' array, which is filled with a random numbers
double *input_random_pdouble(size_t, double, double);

/// @brief Allocates memory for char array with cheking on correctness
/// Exiting with status '-1' if can't allocate memory (other types is similar)
char *alloc_mem_pchar(size_t);

/// @return A 'double' matrix, which is filled with a random numbers
double **input_random_ppdouble(size_t, size_t, double, double);
#endif // _INPUT_

#ifndef _ALGORITHMS_
/// @return count of digits of specified number
int get_count_of_digits_in_number(int);

/// @return count of digits of specified number (using math.h)
int get_count_of_digits_in_number_v2(int);

/// @return array of digits of a number in descending order
int *split_number_on_digits(int);

/// @brief Reversing number
void reverse_pint(int *, int);

/// @return char array from integer value
char *int_to_pchar(int);

/// @return "true" if passed argument 'num' is a prime number
bool is_prime(int);

/// @brief Sorting 1d array by bubble sorting algorithm
void bubbleSortAscending(int[]);

/// @brief Sorting matrix with bubble sort algorithm
void bubbleSortMatrixAscending(int **, size_t, size_t);

/// @brief Sorting elems in array. Best case - O(n). Middle and worst cases - O(n^2)
void insertionSortAscending(int[]);

/// @brief Sorting elems in matrix. Best case - O(n). Middle and worst cases - O(n^2)
void insertionSortMatrixAscending(int **, size_t, size_t);

/// @brief Sorting array by selection algorithm (the lowest perfonamce algorithm)
void selectionSortAscending(int[]);

/// @brief Sorting matrix by selection algorithm
void selectionSortMatrixAscending(int **, size_t, size_t);

/// @brief Sorting array by Shell sorting algorithm
void ShellSortAscending(int[]);

/// @brief Sorting matrix by Shell sorting algorithm
void ShellSortMatrixAscending(int **, size_t, size_t);

/// @brief Auxiliary method for quick sort algortihm
void qSortAscending(int[], size_t, size_t);

/// @brief Sorting array by quick sorting (Hoare sort) algorithm
void quickSortAscending(int[]);

/// @brief Sorting matrix by quick sorting (Hoare sort) algorithm
void quickSortMatrixAscending(int **, size_t, size_t);

/// @brief Sorting elems in array. Best case - O(n). Middle and worst cases - O(n^2)
void insertionSortDescending(int[]);

/// @brief Sorting array by selection algorithm (the lowest perfonamce algorithm)
void selectionSortDescending(int[]);

/// @brief Sorting array by Shell sorting algorithm
void ShellSortDescending(int[]);

/// @brief Auxiliary method for quick sort algortihm
void qSortDescending(int[], size_t, size_t);

/// @brief Sorting array by quick sorting (Hoare sort) algorithm
void quickSortDescending(int[]);

/**
 * @brief Converting int matrix to an array (other types similar)
 * @param src matrix to convert
 * @param dest future array
 * @param rows count of rows
 * @param cols count of columns
 */
void matrixToArr(int **, int *, size_t, size_t);

/**
 * @brief Converting array to a matrix (other types similar)
 * @param src array to convert
 * @param dest future matrix
 * @param rows count of rows
 * @param cols count of columns
 */
void arrayToMatrix(int *, int **, size_t, size_t);

/**
 * @brief Converts string represented in hex to "unsigned long" type value
 * @param str string to convert
 * @return Converting of hex result
 */
unsigned long hex_to_ulong(const char *);

/**
 * @brief Converts all of string characters to uppercase
 *
 * Proper way to use:
 * char *str = "Ihasdjkas dajoasd EIHdfkmk 238909_@K D@sad";
 * char *upper = str_to_upper(str);
 * ... do some work ...
 * free(upper);
 * upper = NULL;
 * @param str string to modify
 * @return Pointer to new string (!!! Do not forget to deallocate memory !!!)
 */
char *str_to_upper(char *);

/**
 * @brief Converts all of string characters to lowercase.
 * @param str string to modify
 * @return Pointer to new string (!!! Do not forget to deallocate memory !!!)
 */
char *str_to_lower(char *);

/**
 * @brief Converts integer value to a hex string
 * @param value integer value to convert
 * @param maxlen Maximum number of bytes to be used in the buffer.
 * The generated string has a length of at most n-1, leaving space
 * for the additional terminating null character. [src: https://cplusplus.com/reference/cstdio/snprintf/]
 * @return Hex string represented as "char *" (!!! Don't forget to deallocate memory !!!)
 */
char *int_to_hex(int, size_t);

/**
 * @brief Converts hex string to an integer value
 * @param hex hex string
 * @param format format to display (0xFF; 0xff; FF -> 255)
 * @return Integer value converts from hex string
 */
int hex_to_int(const char *, const char *);
#endif // _ALGORITHMS_

#endif // LVT_H

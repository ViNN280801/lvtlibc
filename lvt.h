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
#define FOR_SIZE_T(n) for (size_t i = 0ul; i < n; i++)
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
    for (size_t keep = 1ul,            \
                count = 0ul,           \
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

#define VARNAME(var) #var

#if __STDC_VERSION__ >= 201112L
#define TYPEOF(var) _Generic((var),                   \
    _Bool: "_Bool",                                   \
    unsigned char: "unsigned char",                   \
    char: "char",                                     \
    signed char: "signed char",                       \
    short int: "short int",                           \
    unsigned short int: "unsigned short int",         \
    int: "int",                                       \
    unsigned int: "unsigned int",                     \
    long int: "long int",                             \
    unsigned long int: "unsigned long int",           \
    long long int: "long long int",                   \
    unsigned long long int: "unsigned long long int", \
    float: "float",                                   \
    double: "double",                                 \
    long double: "long double",                       \
    char *: "char *",                                 \
    void *: "void *",                                 \
    int *: "int *",                                   \
    default: "other")

#define PRINT_ARR(p, size) _Generic((p, size), \
    int *: print_pint,                         \
    char *: print_pchar,                       \
    default: print_pint)(p, size)

#define PRINT_MATRIX(pp, rows, cols) _Generic((pp, rows, cols), \
    int **: print_ppint,                                        \
    char **: print_ppchar,                                      \
    default: print_ppint)(pp, rows, cols)

#define IS_ALLOC_P(p) _Generic((p), \
    int *: is_alloc_pint,           \
    char *: is_alloc_pchar,         \
    double *: is_alloc_pdouble,     \
    default: is_alloc_pint)(p)

#define IS_ALLOC_PP(p, rows) _Generic((p, rows), \
    int **: is_alloc_ppint,                      \
    char **: is_alloc_ppchar,                    \
    double **: is_alloc_ppdouble,                \
    default: is_alloc_ppint)(p, rows)

#define ALLOC_MEM_P(p, size) _Generic((p, size), \
    int *: alloc_mem_pint,                       \
    char *: alloc_mem_pchar,                     \
    double *: alloc_mem_pdouble,                 \
    default: alloc_mem_pint)(p, size)

#define ALLOC_MEM_PP(p, rows, cols) _Generic((p, rows, cols), \
    int **: alloc_mem_ppint,                                  \
    char **: alloc_mem_ppchar,                                \
    double **: alloc_mem_ppdouble,                            \
    default: alloc_mem_ppint)(p, rows, cols)

#define DEALLOC_MEM_P(p) _Generic((p), \
    int *: dealloc_mem_pint,           \
    char *: dealloc_mem_pchar,         \
    double *: dealloc_mem_pdouble,     \
    default: dealloc_mem_pint)(p)

#define DEALLOC_MEM_PP(p, size) _Generic((p, size), \
    int **: dealloc_mem_ppint,                      \
    char **: dealloc_mem_ppchar,                    \
    double **: dealloc_mem_ppdouble,                \
    default: dealloc_mem_ppint)(p, size)
#endif // !__STDC_VERSION__

#ifndef _PRINT_FUNCTIONS_
/**
 * @brief Prints array on terminal(other types are similar)
 * @param __pint pointer on integer
 * @param __Size size of array (allocated memory for 'pint' pointer)
 */
void print_pint(int *pint, size_t size);

/**
 * @brief Prints array on terminal(other types are similar)
 * @param pchar pointer on char
 * @param size size of array (allocated memory for 'pchar' pointer)
 */
void print_pchar(char *pchar, size_t size);

/**
 * @brief Prints matrix on terminal(other types are similar)
 * @param ppint matrix
 * @param rows count of rows
 * @param col count of columns
 */
void print_ppint(int **ppint, size_t rows, size_t cols);

/**
 * @brief Prints matrix on terminal(other types are similar)
 * @param ppchar matrix
 * @param rows count of rows
 * @param col count of columns
 */
void print_ppchar(int **ppchar, size_t rows, size_t cols);
#endif // !_PRINT_FUNCTIONS_

#ifndef _MEMORY_
#ifndef _CHECK_ALLOCATING_
/**
 * @param pint pointer on integer
 * @return "true" if memory for int
 * array was allocated correctly
 * Otherwise returns "false"(other types are similar)
 */
bool is_alloc_pint(int *pint);

/**
 * @param ppint matrix
 * @param rows count of rows of matrix
 * @return "true" if memory of matrix allocated correctly (other types are similar)
 */
bool is_alloc_ppint(int **ppint, size_t rows);

/**
 * @param pchar pointer on "char"
 * @return "true" if memory for "char"
 * array was allocated correctly
 * Otherwise returns "false"
 */
bool is_alloc_pchar(char *pchar);

/**
 * @brief Checks if passed ptr on ptr (int **) is allocated
 * @param ppchar matrix
 * @param rows count of rows of matrix
 * @return "true" if memory of matrix allocated correctly (other types are similar)
 */
bool is_alloc_ppchar(int **ppchar, size_t rows);

/**
 * @brief Checks if passed ptr on ptr (double **) is allocated
 * @param pd pointer on "double"
 * @return "true" if memory for "double"
 * array was allocated correctly
 * Otherwise returns "false"
 */
bool is_alloc_pdouble(double *pd);

/**
 * @brief Checks if passed ptr on ptr (double **) is allocated
 * @param ppd matrix
 * @param rows count of rows of matrix
 * @return "true" if memory of matrix allocated correctly (other types are similar)
 */
bool is_alloc_ppdouble(double **ppd, size_t size);
#endif // !_CHECK_ALLOCATING_

#ifndef _ALLOCATING_
/**
 * @brief Allocates memory for int array with cheking on correctness
 * Exiting with status '-1' if can't allocate memory (other types are similar)
 * @param size size of the array to allocate
 * @return Pointer to allocated memory
 */
int *alloc_mem_pint(size_t size);

/**
 * @brief Allocates memory to matrix with checkings on correctness of allocating
 * @param rows count of rows
 * @param cols count of columns
 * @return Pointer on a matrix
 */
int **alloc_mem_ppint(size_t rows, size_t cols);

/**
 * @brief Allocates memory for int array with cheking on correctness
 * Exiting with status '-1' if can't allocate memory
 * @param size size of the array to allocate
 * @return Pointer to allocated memory
 */
char *alloc_mem_pchar(size_t size);

/**
 * @brief Allocates memory to matrix with checkings on correctness of allocating
 * @param rows count of rows
 * @param cols count of columns
 * @return Pointer on a matrix
 */
char **alloc_mem_ppchar(size_t rows, size_t cols);

/**
 * @brief Allocates memory for int array with cheking on correctness
 * Exiting with status '-1' if can't allocate memory
 * @param size size of the array to allocate
 * @return Pointer to allocated memory
 */
double *alloc_mem_pdouble(size_t size);

/**
 * @brief Allocates memory to matrix with checkings on correctness of allocating
 * @param rows count of rows
 * @param cols count of columns
 * @return Pointer on a matrix
 */
double **alloc_mem_ppdouble(size_t rows, size_t cols);
#endif // !_ALLOCATING_

#ifndef _DEALLOCATING_
/**
 * @brief Deallocates memory of matrix
 * @param pint pointer on array
 */
void dealloc_mem_pint(int *pint);

/**
 * @brief Deallocates memory of matrix
 * @param ppint pointer on matrix
 * @param rows count of rows in matrix
 */
void dealloc_mem_ppint(int **ppint, size_t rows);

/**
 * @brief Deallocates memory of matrix
 * @param pchar pointer on array
 */
void dealloc_mem_pchar(char *pchar);

/**
 * @brief Deallocates memory of matrix
 * @param ppchar pointer on matrix
 * @param rows count of rows in matrix
 */
void dealloc_mem_ppchar(char **ppchar, size_t rows);

/**
 * @brief Deallocates memory of matrix
 * @param pd pointer on array
 */
void dealloc_mem_pdouble(double *pd);

/**
 * @brief Deallocates memory of matrix
 * @param ppd pointer on matrix
 * @param rows count of rows in matrix
 */
void dealloc_mem_ppdouble(double **ppd, size_t rows);
#endif // !_DEALLOCATING_
#endif // !_MEMORY_

#ifndef _INPUT_
/**
 * @brief Handles an error when a user enters a character or string when asked to enter a number
 * @return Number entered by the user
 */
int input_int();

/**
 * @brief Handles an error when a user enters a character or string
 * when asked to enter a number
 * @return The double number entered by the user
 */
double input_double();

/**
 * @brief Inputting array manually
 * @return An integer array, which is filled with a manually entered values
 */
int *input_manual_pint(size_t size);

/**
 * @brief Inputting array random
 * "rand % low" returns numbers from 0 to 'low'
 * adding 'high' gives number between 'high' and 'low + high'
 * @param size count of element in array
 * @param low lowest value in range
 * @param high highest value in range
 * @return An integer array, which is filled with a random numbers
 */
int *input_random_pint(size_t size, int low, int high);

/**
 * @brief Inputting matrix manually
 * @param rows count of rows
 * @param cols count of columns
 * @return an integer matrix, which is filled with a manually entered values
 */
int **input_manual_ppint(size_t rows, size_t cols);

/**
 * @brief Inputting matrix by random values
 * @param rows count of rows
 * @param cols count of columns
 * @return An integer matrix, which is filled with a manually entered values
 */
int **input_random_ppint(size_t rows, size_t cols, int low, int high);

/**
 * @brief Filling double array randomly
 * @param size count of elements to spawn
 * @param low lowest value in range
 * @param high highest value in range
 * @return A 'double' array, which is filled with a random numbers
 */
double *input_random_pdouble(size_t size, double low, double high);

/**
 * @brief Filling double matrix randomly
 * @param rows count of rows
 * @param cols count of columns
 * @param low lowest value in range
 * @param high highest value in range
 * @return A 'double' matrix, which is filled with a random numbers
 */
double **input_random_ppdouble(size_t rows, size_t cols, double low, double high);
#endif // !_INPUT_

#ifndef _ALGORITHMS_
/**
 * @brief Counts number of digits in a number 'n'
 * @param n specified number to count it digits
 * @return Count of digits in number 'n'
 */
int get_count_of_digits_in_number(int n);

/**
 * @brief Counts number of digits in a number 'n' (uses "math.h")
 * @param n specified number to count it digits
 * @return Count of digits in number 'n'
 */
int get_count_of_digits_in_number_v2(int n);

/**
 * @brief Splits number on digits
 * @param n specified number
 * @return Array of digits of a number in descending order
 */
int *split_number_on_digits(int n);

/**
 * @brief Reversing number
 * @param pint array of integers to reverse them
 * @param size size of array 'pint'
 */
void reverse_pint(int *pint, int size);

/**
 * @brief Turns number to string representation
 * @param n specified number
 * @return Char array from integer value
 */
char *int_to_pchar(int n);

/**
 * @brief Checks if specified number is prime
 * @param n specified number
 * @return "true" if passed argument 'num' is a prime number
 */
bool is_prime(int n);

/**
 * @brief Sorting 1d array by bubble sorting algorithm
 * @param arr array
 * @param size size of specified array
 */
void bubbleSortAscending(int *arr, size_t size);

/**
 * @brief Sorting matrix with bubble sort algorithm
 * @param matrix matrix
 * @param rows count of rows in matrix
 * @param cols count of columns in matrix
 */
void bubbleSortMatrixAscending(int **matrix, size_t rows, size_t cols);

/**
 * @brief Sorting elems in array. Best case - O(n). Middle and worst cases - O(n^2)
 * @param arr array
 * @param size size of specified array
 */
void insertionSortAscending(int *arr, size_t size);

/**
 * @brief Sorting elems in matrix. Best case - O(n). Middle and worst cases - O(n^2)
 * @param matrix matrix
 * @param rows count of rows in matrix
 * @param cols count of columns in matrix
 */
void insertionSortMatrixAscending(int **matrix, size_t rows, size_t cols);

/**
 * @brief Sorting array by selection algorithm (the lowest perfonamce algorithm)
 * @param arr array
 * @param size size of specified array
 */
void selectionSortAscending(int *arr, size_t size);

/**
 * @brief Sorting matrix by selection algorithm
 * @param matrix matrix
 * @param rows count of rows in matrix
 * @param cols count of columns in matrix
 */
void selectionSortMatrixAscending(int **matrix, size_t rows, size_t cols);

/**
 * @brief Sorting array by Shell sorting algorithm
 * @param arr array
 * @param size size of specified array
 */
void ShellSortAscending(int *arr, size_t size);

/**
 * @brief Sorting matrix by Shell sorting algorithm
 * @param matrix matrix
 * @param rows count of rows in matrix
 * @param cols count of columns in matrix
 */
void ShellSortMatrixAscending(int **matrix, size_t rows, size_t cols);

/**
 * @brief Auxiliary method for quick sort algortihm
 * @param arr array
 * @param size size of specified array
 * @param low left border
 * @param high right border
 */
void qSortAscending(int *arr, size_t size, size_t low, size_t high);

/**
 * @brief Sorting array by quick sorting (Hoare sort) algorithm
 * @param arr array
 * @param size size of specified array
 */
void quickSortAscending(int *arr, size_t size);

/**
 * @brief Sorting matrix by quick sorting (Hoare sort) algorithm
 * @param matrix matrix
 * @param rows count of rows in matrix
 * @param cols count of columns in matrix
 */
void quickSortMatrixAscending(int **matrix, size_t rows, size_t cols);

/**
 * @brief Sorting 1d array by bubble sorting algorithm in descending order
 * @param arr array
 * @param size size of specified array
 */
void bubbleSortDescending(int *arr, size_t size);

/**
 * @brief Sorting matrix with bubble sort algorithm in descending order
 * @param matrix matrix
 * @param rows count of rows in matrix
 * @param cols count of columns in matrix
 */
void bubbleSortMatrixDescending(int **matrix, size_t rows, size_t cols);

/**
 * @brief Sorting elems in array in descending order
 * Best case - O(n). Middle and worst cases - O(n^2)
 * @param arr array
 * @param size size of specified array
 */
void insertionSortDescending(int *arr, size_t size);

/**
 * @brief Sorting array in descending order by selection algorithm (the lowest perfonamce algorithm)
 * @param arr array
 * @param size size of specified array
 */
void selectionSortDescending(int *arr, size_t size);

/**
 * @brief Sorting array in descending order by Shell sorting algorithm
 * @param arr array
 * @param size size of specified array
 */
void ShellSortDescending(int *arr, size_t size);

/**
 * @brief Auxiliary method for quick sort algortihm
 * @param arr array
 * @param size size of specified array
 * @param low left border
 * @param high right border
 */
void qSortDescending(int *arr, size_t size, size_t low, size_t hight);

/**
 * @brief Sorting array in descending order by quick sorting (Hoare sort) algorithm
 * @param arr array
 * @param size size of specified array
 */
void quickSortDescending(int *arr, size_t size);

/**
 * @brief Converting int matrix to an array (other types similar)
 * @param src matrix to convert
 * @param dest future array
 * @param rows count of rows
 * @param cols count of columns
 */
void matrixToArr(int **src, int *dest, size_t rows, size_t cols);

/**
 * @brief Converting array to a matrix (other types similar)
 * @param src array to convert
 * @param dest future matrix
 * @param rows count of rows
 * @param cols count of columns
 */
void arrayToMatrix(int *src, int **dest, size_t rows, size_t cols);

/**
 * @brief Converts string represented in hex to "unsigned long" type value
 * @param str string to convert
 * @return Converting of hex result
 */
unsigned long hex_to_ulong(const char *str);

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
char *str_to_upper(char *str);

/**
 * @brief Converts all of string characters to lowercase.
 * @param str string to modify
 * @return Pointer to new string (!!! Do not forget to deallocate memory !!!)
 */
char *str_to_lower(char *str);

/**
 * @brief Converts integer value to a hex string
 * @param value integer value to convert
 * @param maxlen Maximum number of bytes to be used in the buffer.
 * The generated string has a length of at most n-1, leaving space
 * for the additional terminating null character. [src: https://cplusplus.com/reference/cstdio/snprintf/]
 * @return Hex string represented as "char *" (!!! Don't forget to deallocate memory !!!)
 */
char *int_to_hex(int value, size_t maxlen);

/**
 * @brief Converts hex string to an integer value
 * @param hex hex string
 * @param format format to display (0xFF; 0xff; FF -> 255)
 * @return Integer value converts from hex string
 */
int hex_to_int(const char *hex, const char *format);

/**
 * @brief Removes specified character from the string (all of them)
 * @param str string to remove character from it
 * @param c character to remove from string
 */
void remove_char(char *str, char c);

/**
 * @brief Removes specified character from the string (all of them) - version 2
 * @param str string to remove character from it
 * @param c character to remove from string
 */
void remove_char_v2(const char *str_in, char *str_out, char c);

/**
 * @brief Gets the substring from the specified string 'str'
 * @param str string to get a substring from it
 * @param begin position of character to copy all content since it
 * @param end position of character to copy all content until it
 * @return Substring from 'begin' to 'end': str[begin:end].
 * Returns 'NULL' if some error or invalid cases occures
 */
char *substr(const char *str, size_t begin, size_t end);

/**
 * @brief Adds specified character into passed string to certain position
 * (!!! DO NOT FORGET TO DEALLOC MEMORY FOR 'dest' !!!)
 * Usage hint:
 * char *s = "Hello, World!";
 * char *buf = NULL;
 * insert_ch_to_str(s, &buf, 3, '*');
 * free(buf);
 * If you want to print result do not forget check if 'buf' is "NULL", because if it "NULL"
 * "printf()" func invokes "Segmentation fault" or another error
 * @param src source string
 * @param dest buffer to store new modified string complicated with old string 'src'
 * @param pos position to insert character
 * @param c char to append it in certain position
 */
void insert_ch_to_str(const char *restrict src, char **dest, size_t pos, char c);

/**
 * @brief Adds specified character into passed string to certain position
 * (!!! DO NOT FORGET TO DEALLOC MEMORY FOR 'dest' !!!)
 * Usage hint:
 * char *s = "Hello, World!";
 * char *buf = NULL;
 * insert_str_to_str(s, &buf, 7, "THIS IS STRING");
 * free(buf);
 * If you want to print result do not forget check if 'buf' is "NULL", because if it "NULL"
 * "printf()" func invokes "Segmentation fault" or another error
 * @param src source string
 * @param dest buffer to store new modified string complicated with old string 'src'
 * @param pos position to insert character
 * @param str string to append it in certain position
 */
void insert_str_to_str(const char *restrict src, char **dest, size_t pos, const char *restrict str);
#endif // !_ALGORITHMS_

#endif // !LVT_H

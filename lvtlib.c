#include "lvtlib.h"

#ifndef _PRINT_FUNCTIONS_
// Prints array on terminal (other types is similar)
void print_pint(const int *__parr, const size_t __arr_size)
{
    printf("\n==== ==== ==== ==== ====\nArray:\n");
    for (size_t i = 0UL; i < __arr_size; i++)
    {
        printf("arr[%ld] = %d\n", i, __parr[i]);
    }
    printf("==== ==== ==== ==== ====\n\n");
}

// Prints matrix on terminal (other types is similar)
void print_ppint(int **__pp, const size_t __rows, const size_t __cols)
{
    printf("\n==== ==== ==== ==== ==== ==== ==== ==== ====\nMatrix:\n");
    // Simple iterating over the matrix by indeces of row and column
    for (size_t row = 0UL; row < __rows; row++)
    {
        for (size_t col = 0UL; col < __cols; col++)
        {
            printf("%d\t", __pp[row][col]);
        }
        printf("\n");
    }
    printf("==== ==== ==== ==== ==== ==== ==== ==== ====\n\n");
}
#endif

#ifndef _MEMORY_
#ifndef _CHECK_ALLOCATING_
// Returns "true" if memory for int
// array was allocated correctly
// Otherwise returns "false" (other types is similar)
bool is_alloc_pint(const int *__p)
{
    return (!__p) ? false : true;
}

// Return "true" if memory of matrix allocated correctly  (other types is similar)
bool is_alloc_ppint(const int **__pp, const size_t __rows)
{
    for (size_t row = 0UL; row < __rows; row++)
    {
        if (!__pp[row])
            return false;
    }
    if (!__pp)
        return false;

    return true;
}

// Returns "true" if memory for double
// array was allocated correctly
// Otherwise returns "false" (other types is similar)
bool is_alloc_pdouble(const double *__p)
{
    return (!__p) ? false : true;
}

// Return "true" if memory of matrix allocated correctly  (other types is similar)
bool is_alloc_ppdouble(const double **__pp, const size_t __rows)
{
    for (size_t row = 0UL; row < __rows; row++)
    {
        if (!__pp[row])
            return false;
    }
    if (!__pp)
        return false;

    return true;
}
#endif

#ifndef _ALLOCATING_
// Allocates memory for integer array with cheking on correctness
// Exiting with status '-1' if can't allocate memory (other types is similar)
int *alloc_mem_pint(const size_t __arr_size)
{
    int *p = (int *)calloc(__arr_size, sizeof(int));

    if (!is_alloc_pint(p))
    {
        printf("Can't allocate memory for array of integers. Exiting with \'-1\' status\n");
        exit(-1);
    }

    return p;
}

// Allocates memory to matrix with checkings on correctness of allocating
// Returns pointer on a matrix of integer values
int **alloc_mem_ppint(const size_t __rows, const size_t __cols)
{
    int **pp = (int **)calloc(__cols, sizeof(int *));

    if (!pp)
    {
        printf("Can't allocate memory for each row of matrix. Exiting with \'-1\' status\n");
        exit(-1);
    }

    for (size_t row = 0UL; row < __cols; row++)
    {
        pp[row] = (int *)calloc(__rows, sizeof(int));

        if (!pp[row])
        {
            printf("Can't allocate memory for each column of matrix. Exiting with \'-1\' status\n");
            exit(-1);
        }
    }

    return pp;
}

// Allocates memory for 'double' array with cheking on correctness
// Exiting with status '-1' if can't allocate memory (other types is similar)
double *alloc_mem_pdouble(const size_t __arr_size)
{
    double *p = (double *)calloc(__arr_size, sizeof(double));

    if (!is_alloc_pdouble(p))
    {
        printf("Can't allocate memory for array of doubles. Exiting with \'-1\' status\n");
        exit(-1);
    }

    return p;
}

// Allocates memory to matrix with checkings on correctness of allocating
// Returns pointer on a matrix of doubles values
double **alloc_mem_ppdouble(const size_t __rows, const size_t __cols)
{
    double **pp = (double **)calloc(__cols, sizeof(double *));

    if (!pp)
    {
        printf("Can't allocate memory for each row of matrix. Exiting with \'-1\' status\n");
        exit(-1);
    }

    for (size_t row = 0UL; row < __rows; row++)
    {
        pp[row] = (double *)calloc(__rows, sizeof(double));

        if (!pp[row])
        {
            printf("Can't allocate memory for each column of matrix. Exiting with \'-1\' status\n");
            exit(-1);
        }
    }

    return pp;
}
#endif

#ifndef _DEALLOCATING_
// Deallocating memory of int pointer (other types is similar)
void dealloc_mem_pint(int *__p)
{
    free(__p);
    __p = NULL;
}

// Deallocating memory of '__pp' pointer (other types is similar)
void dealloc_mem_ppint(int **__pp, const size_t __rows)
{
    for (size_t row = 0UL; row < __rows; row++)
    {
        free(__pp[row]);
    }

    free(__pp);
    __pp = NULL;
}
#endif
#endif

#ifndef _INPUT_
// Handles an error when a user enters a character or string
// when asked to enter a number. Returns the integer number entered by the user
int input_int()
{
    char buf[256] = {0};
    scanf("%s", buf);

    while ((atoi(buf) == 0) && (buf[0] != '0'))
    {
        printf("Input error. Try again: ");
        scanf("%s", buf);
    }
    return atoi(buf);
}

// Handles an error when a user enters a character or string
// when asked to enter a number. Returns the double number entered by the user
double input_double()
{
    char buf[256] = {0};
    scanf("%s", buf);
    while ((atof(buf) == 0.0) && (buf[0] != '0'))
    {
        printf("Input error. Try again: ");
        scanf("%s", buf);
    }
    return atof(buf);
}

// Returns an integer array, which is filled with a manually entered values
int *input_manual_pint(const size_t __size)
{
    int *parr = alloc_mem_pint(__size);

    for (size_t i = 0UL; i < __size; i++)
    {
        printf("parr[%ld] = ", i);
        parr[i] = input_int();
    }

    return parr;
}

// Returns an integer array, which is filled with a random numbers
// "rand % __num1" returns numbers from 0 to '__num1'
// adding '__num2' gives number between '__num2' and '__num1 + __num2'
int *input_random_pint(const size_t __size, const int __num1, const int __num2)
{
    srand(time(NULL));
    int *parr = alloc_mem_pint(__size);

    // Filling array with random integer values
    for (size_t i = 0UL; i < __size; i++)
    {
        parr[i] = rand() % __num1 + __num2;
    }

    return parr;
}

// Returns an integer matrix, which is filled with a manually entered values
int **input_manual_ppint(const size_t __rows, const size_t __cols)
{
    int **matrix = alloc_mem_ppint(__rows, __cols);

    for (size_t row = 0UL; row < __rows; row++)
    {
        for (size_t col = 0UL; col < __cols; col++)
        {
            printf("matrix[%ld][%ld] = ", row, col);
            matrix[row][col] = input_int();
        }
    }

    return matrix;
}

// Returns an integer matrix, which is filled with a random numbers
int **input_random_ppint(const size_t __rows, const size_t __cols, const int __num1, const int __num2)
{
    int **matrix = alloc_mem_ppint(__rows, __cols);

    srand(time(NULL));

    for (size_t row = 0UL; row < __rows; row++)
    {
        for (size_t col = 0UL; col < __cols; col++)
        {
            matrix[row][col] = rand() % __num1 + __num2;
        }
    }

    return matrix;
}

// Returns a 'double' array, which is filled with a random numbers
double *input_random_pdouble(const size_t __size, const double __min, const double __max)
{
    srand(time(NULL));
    double *parr = alloc_mem_pdouble(__size);

    // Filling array with random integer values
    for (size_t i = 0UL; i < __size; i++)
    {
        double f = (double)rand() / RAND_MAX;
        parr[i] = __min + f * (__max - __min);
    }

    return parr;
}

// Returns a 'double' matrix, which is filled with a random numbers
double **input_random_ppdouble(const size_t __rows, const size_t __cols, const double __min, const double __max)
{
    double **matrix = alloc_mem_ppdouble(__rows, __cols);

    srand(time(NULL));

    for (size_t row = 0UL; row < __rows; row++)
    {
        for (size_t col = 0UL; col < __cols; col++)
        {
            double f = (double)rand() / RAND_MAX;
            matrix[row][col] = __min + f * (__max - __min);
        }
    }

    return matrix;
}
#endif

#include "lvtlib.h"

#ifndef _PRINT_FUNCTIONS_
// Prints array on terminal
void print_int_arr(const int *__parr, const size_t __arr_size)
{
    printf("\n==== ==== ==== ==== ====\nArray:\n");
    for (size_t i = 0; i < __arr_size; i++)
    {
        printf("arr[%ld] = %d\n", i, __parr[i]);
    }
    printf("==== ==== ==== ==== ====\n\n");
}
#endif

#ifndef _MEMORY_
#ifndef _CHECK_ALLOCATING_
// Returns "true" if memory for int
// array was allocated correctly
// Otherwise returns "false"
bool is_alloc_pint(const int *__p)
{
    return (!__p) ? false : true;
}

// Returns "true" if memory for float
// array was allocated correctly
// Otherwise returns "false"
bool is_alloc_pfloat(const float *__p)
{
    return (!__p) ? false : true;
}

// Returns "true" if memory for double
// array was allocated correctly
// Otherwise returns "false"
bool is_alloc_pdouble(const double *__p)
{
    return (!__p) ? false : true;
}

// Returns "true" if memory for char
// array was allocated correctly
// Otherwise returns "false"
bool is_alloc_pchar(const char *__p)
{
    return (!__p) ? false : true;
}
#endif

#ifndef _ALLOCATING_
// Allocates memory for integer array with cheking on correctness
// Exiting with status '-1' if can't allocate memory
int *alloc_mem_pint(const size_t __arr_size)
{
    int *p = (int *)calloc(__arr_size, sizeof(int));

    if (!is_alloc_pint(p))
        exit(-1);

    return p;
}

// Allocates memory for float array with cheking on correctness
// Exiting with status '-1' if can't allocate memory
float *alloc_mem_pfloat(const size_t __arr_size)
{
    float *p = (float *)calloc(__arr_size, sizeof(float));

    if (!is_alloc_pfloat(p))
        exit(-1);

    return p;
}

// Allocates memory for double array with cheking on correctness
// Exiting with status '-1' if can't allocate memory
double *alloc_mem_pdouble(const size_t __arr_size)
{
    double *p = (double *)calloc(__arr_size, sizeof(double));

    if (!is_alloc_pdouble(p))
        exit(-1);

    return p;
}

// Allocates memory for char array with cheking on correctness
// Exiting with status '-1' if can't allocate memory
char *alloc_mem_pchar(const size_t __arr_size)
{
    char *p = (char *)calloc(__arr_size, sizeof(char));

    if (!is_alloc_pchar(p))
        exit(-1);

    return p;
}
#endif

#ifndef _DEALLOCATING_
// Deallocating memory of int pointer
void dealloc_mem_arr_int(int *__p)
{
    free(__p);
    __p = NULL;
}

// Deallocating memory of float pointer
void dealloc_mem_pfloat(float *__p)
{
    free(__p);
    __p = NULL;
}

// Deallocating memory of double pointer
void dealloc_mem_pdouble(double *__p)
{
    free(__p);
    __p = NULL;
}

// Deallocating memory of char pointer
void dealloc_mem_pchar(char *__p)
{
    free(__p);
    __p = NULL;
}
#endif
#endif

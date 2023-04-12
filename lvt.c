#include "lvt.h"

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

// Returns "true" if memory for char
// array was allocated correctly
// Otherwise returns "false" (other types is similar)
bool is_alloc_pchar(const char *__p)
{
    return (!__p) ? false : true;
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

    for (size_t row = 0UL; row < __rows; row++)
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

// Allocates memory for char array with cheking on correctness
// Exiting with status '-1' if can't allocate memory (other types is similar)
char *alloc_mem_pchar(const size_t __arr_size)
{
    char *p = (char *)calloc(__arr_size, sizeof(char));

    if (!is_alloc_pchar(p))
    {
        printf("Can't allocate memory for array of characters. Exiting with \'-1\' status\n");
        exit(-1);
    }

    return p;
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

// Deallocating memory of char pointer (other types is similar)
void dealloc_mem_pchar(char *__p)
{
    free(__p);
    __p = NULL;
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

#ifndef _ALGORITHMS_
// Return count of digits in specified number
int get_count_of_digits_in_number(int num)
{
    int size = 0;
    while (num > 0)
    {
        num /= 10;
        size++;
    }
    return size;
}

// Return count of digits of specified number (using math.h)
int get_count_of_digits_in_number_v2(int const num)
{
    return floor(log10(num)) + 1;
}

// Returns int array (in descending order) that contains digits of a number
int *split_number_on_digits(int num)
{
    int size = get_count_of_digits_in_number(num), i = 0;
    int *digits = alloc_mem_pint(size);

    while (num > 0)
    {
        digits[i] = num % 10;
        num /= 10;
        i++;
    }
    return digits;
}

// Reversing number
void reverse_pint(int *pint, const int size)
{
    int temp = 0;
    for (int i = 0; i < size / 2; i++)
    {
        temp = pint[i];
        pint[i] = pint[size - i - 1];
        pint[size - i - 1] = temp;
    }
}

// Returns char array from integer value
char *int_to_pchar(int num)
{
    int size = log10(num) + 1;
    char *pChar = alloc_mem_pchar((size_t)size);
    for (int i = size - 1; i >= 0; i--, num /= 10)
    {
        pChar[i] = (num % 10) + '0';
    }
    return pChar;
}

// Returns "true" if passed argument 'num' is a prime number
bool is_prime(const int num)
{
    if (num <= 0)
        return false;

    for (int i = 2; i <= (int)sqrt(num); i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

// Sorting 1d array by bubble sorting algorithm
void bubbleSortAscending(int arr[])
{
    for (size_t i = 0; i < ARRSIZE(arr); i++)
        for (size_t j = 0; j < ARRSIZE(arr); j++)
            if (arr[i] < arr[j])
                SWAP(arr[i], arr[j]);
}

// Sorting elems in vector. Best case - O(n). Middle and worst cases - O(n^2)
void insertionSortAscending(int arr[])
{
    // Iterating by vector from 2nd element to end: [begin + 1; end]
    for (size_t i = 1UL; i < ARRSIZE(arr); i++)
    {
        // Initializing position of previous element from 'i'
        size_t j = i - 1UL;

        // Initializing currenint value = of vector
        int value = arr[i];

        // While position of prev element is lower than size of vector
        // and element in this position is bigger than currenint value = ->
        // assigning it to next element (j + 1) of vector
        while (j < ARRSIZE(arr) && arr[j] > value)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        // Assigning current element to next from previous
        arr[j + 1] = value;
    }
}

// Sorting vector by selection algorithm (the lowest perfonamce algorithm)
void selectionSortAscending(int arr[])
{
    // Iterating over the range
    for (size_t i = 0; i < ARRSIZE(arr); i++)
    {
        // For example, minimal element is begin element of the vector
        size_t minPos = i;

        // Iterating over the unsorted range
        for (size_t j = i + 1UL; j < ARRSIZE(arr); j++)
        {
            // If element from the unsorted range is lower than the current ->
            // assigning new position to 'minPos' variable
            if (arr[j] < arr[minPos])
                minPos = j;
        }
        // Swap minimal element with current
        SWAP(arr[i], arr[minPos]);
    }
}

// Sorting array by Shell sorting algorithm
void ShellSortAscending(int arr[])
{
    for (size_t interval = ARRSIZE(arr) / 2; interval > 0; interval /= 2)
    {
        for (size_t i = 0; i < ARRSIZE(arr); i++)
        {
            int val = arr[i];
            size_t j = 0;
            for (j = i; (j >= interval) && (arr[j - interval] > val); j -= interval)
            {
                arr[j] = arr[j - interval];
            }
            arr[j] = val;
        }
    }
}

// Auxiliary method for quick sort algortihm
void qSortAscending(int arr[], size_t low, size_t high)
{
    size_t i = low, j = high;
    // Select pivoint value =
    int pivot = arr[(i + j) / 2], tmp = 0;

    while (i <= j && i < ARRSIZE(arr) && j < ARRSIZE(arr))
    {
        while (arr[i] < pivot && i < ARRSIZE(arr))
            i++;
        while (arr[j] > pivot && j < ARRSIZE(arr))
            j--;
        if (i <= j && i < ARRSIZE(arr) && j < ARRSIZE(arr))
        {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    // Recursive call sorting to left side from pivot
    if (j > low && j < ARRSIZE(arr))
        qSortAscending(arr, low, j);
    // Recursive call sorting to right side from pivot
    if (i < high && i < ARRSIZE(arr))
        qSortAscending(arr, i, high);
}

// Sorting array by quick sorting (Hoare sort) algorithm
void quickSortAscending(int arr[])
{
    qSortAscending(arr, 0, ARRSIZE(arr) - 1);
}

// Sorting 1d array by bubble sorting algorithm
void bubbleSortDescending(int arr[])
{
    for (size_t i = 0; i < ARRSIZE(arr); i++)
        for (size_t j = 0; j < ARRSIZE(arr); j++)
            if (arr[i] > arr[j])
                SWAP(arr[i], arr[j]);
}

// Sorting elems in vector. Best case - O(n). Middle and worst cases - O(n^2)
void insertionSortDescending(int arr[])
{
    // Iterating by vector from 2nd element to end: [begin + 1; end]
    for (size_t i = 1UL; i < ARRSIZE(arr); i++)
    {
        // Initializing currenint value = of vector
        int val = arr[i];

        // Initializing position of previous element from 'i'
        size_t pos = i - 1;

        // While position of prev element is lower than size of vector
        // and element in this position is bigger than currenint value = ->
        // assigning it to next element (j + 1) of vector
        while (pos < ARRSIZE(arr) && arr[pos] < val)
        {
            arr[pos + 1] = arr[pos];
            pos--;
        }
        // Assigning current element to next from previous
        arr[pos + 1] = val;
    }
}

// Sorting vector by selection algorithm (the lowest perfonamce algorithm)
void selectionSortDescending(int arr[])
{
    // Iterating over the range
    for (size_t i = 0; i < ARRSIZE(arr); i++)
    {
        // For example, minimal element is begin element of the vector
        size_t maxPos = i;

        // Iterating over the unsorted range
        for (size_t j = i + 1UL; j < ARRSIZE(arr); j++)
        {
            // If element from the unsorted range is lower than the current ->
            // assigning new position to 'maxPos' variable
            if (arr[j] > arr[maxPos])
                maxPos = j;
        }
        // Swap minimal element with current
        SWAP(arr[i], arr[maxPos]);
    }
}

// Sorting array by Shell sorting algorithm
void ShellSortDescending(int arr[])
{
    for (size_t interval = ARRSIZE(arr) / 2; interval > 0; interval /= 2)
    {
        for (size_t i = 0; i < ARRSIZE(arr); i++)
        {
            int val = arr[i];
            size_t j = 0;
            for (j = i; (j >= interval) && (arr[j - interval] < val); j -= interval)
            {
                arr[j] = arr[j - interval];
            }
            arr[j] = val;
        }
    }
}

// Auxiliary method for quick sort algortihm
void qSortDescending(int arr[], size_t low, size_t high)
{
    size_t i = low, j = high;
    // Select pivoint value =
    int pivot = arr[(i + j) / 2], tmp = 0;

    while (i <= j && i < ARRSIZE(arr) && j < ARRSIZE(arr))
    {
        while (arr[i] > pivot && i < ARRSIZE(arr))
            i++;
        while (arr[j] < pivot && j < ARRSIZE(arr))
            j--;
        if (i <= j && i < ARRSIZE(arr) && j < ARRSIZE(arr))
        {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    // Recursive call sorting to left side from pivot
    if (j > low && j < ARRSIZE(arr))
        qSortDescending(arr, low, j);
    // Recursive call sorting to right side from pivot
    if (i < high && i < ARRSIZE(arr))
        qSortDescending(arr, i, high);
}

// Sorting array by quick sorting (Hoare sort) algorithm
void quickSortDescending(int arr[])
{
    qSortDescending(arr, 0, ARRSIZE(arr) - 1);
}
#endif // _ALGORITHMS_

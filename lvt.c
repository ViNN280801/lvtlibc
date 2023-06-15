#include "lvt.h"

#ifndef _PRINT_FUNCTIONS_
void print_pint(int *pint, size_t size)
{
    for (size_t i = 0ul; i < size; i++)
        printf("%d ", pint[i]);
    printf("\n");
}

void print_pchar(char *pchar, size_t size)
{
    for (size_t i = 0ul; i < size; i++)
        printf("%c ", pchar[i]);
    printf("\n");
}

void print_ppint(int **ppint, size_t rows, size_t cols)
{
    // Simple iterating over the matrix by indeces of row and column
    for (size_t row = 0ul; row < rows; row++)
    {
        for (size_t col = 0ul; col < cols; col++)
        {
            printf("%d\t", ppint[row][col]);
        }
        printf("\n");
    }
}

void print_ppchar(int **ppchar, size_t rows, size_t cols)
{
    for (size_t row = 0ul; row < rows; row++)
    {
        for (size_t col = 0ul; col < cols; col++)
        {
            printf("%c\t", ppchar[row][col]);
        }
        printf("\n");
    }
}
#endif // !_PRINT_FUNCTIONS_

#ifndef _MEMORY_
#ifndef _CHECK_ALLOCATING_
bool is_alloc_pint(int *pint)
{
    return (!pint) ? false : true;
}

bool is_alloc_ppint(int **ppint, size_t rows)
{
    for (size_t row = 0ul; row < rows; row++)
    {
        if (!ppint[row])
            return false;
    }
    if (!ppint)
        return false;

    return true;
}

bool is_alloc_pchar(char *pchar)
{
    return (!pchar) ? false : true;
}

bool is_alloc_ppchar(int **ppchar, size_t rows)
{
    for (size_t row = 0ul; row < rows; row++)
    {
        if (!ppchar[row])
            return false;
    }
    if (!ppchar)
        return false;

    return true;
}

bool is_alloc_pdouble(double *pd)
{
    return (!pd) ? false : true;
}

bool is_alloc_ppdouble(double **ppd, size_t rows)
{
    for (size_t row = 0ul; row < rows; row++)
    {
        if (!ppd[row])
            return false;
    }
    if (!ppd)
        return false;

    return true;
}
#endif

#ifndef _ALLOCATING_
int *alloc_mem_pint(size_t size)
{
    int *p = (int *)calloc(size, sizeof(int));

    if (!is_alloc_pint(p))
    {
        printf("Can't allocate memory for array of integers. Exiting with \'-1\' status\n");
        exit(-1);
    }

    return p;
}

int **alloc_mem_ppint(size_t rows, size_t cols)
{
    int **pp = (int **)calloc(cols, sizeof(int *));

    if (!pp)
    {
        printf("Can't allocate memory for each row of matrix. Exiting with \'-1\' status\n");
        exit(-1);
    }

    for (size_t row = 0ul; row < rows; row++)
    {
        pp[row] = (int *)calloc(rows, sizeof(int));

        if (!pp[row])
        {
            printf("Can't allocate memory for each column of matrix. Exiting with \'-1\' status\n");
            exit(-1);
        }
    }

    return pp;
}

char *alloc_mem_pchar(size_t size)
{
    char *p = (char *)calloc(size, sizeof(char));

    if (!is_alloc_pchar(p))
    {
        printf("Can't allocate memory for array of characters. Exiting with \'-1\' status\n");
        exit(-1);
    }

    return p;
}

char **alloc_mem_ppchar(size_t rows, size_t cols)
{
    char **pp = (char **)calloc(cols, sizeof(char *));

    if (!pp)
    {
        printf("Can't allocate memory for each row of matrix. Exiting with \'-1\' status\n");
        exit(-1);
    }

    for (size_t row = 0ul; row < rows; row++)
    {
        pp[row] = (char *)calloc(rows, sizeof(char));

        if (!pp[row])
        {
            printf("Can't allocate memory for each column of matrix. Exiting with \'-1\' status\n");
            exit(-1);
        }
    }

    return pp;
}

double *alloc_mem_pdouble(size_t size)
{
    double *p = (double *)calloc(size, sizeof(double));

    if (!is_alloc_pdouble(p))
    {
        printf("Can't allocate memory for array of doubles. Exiting with \'-1\' status\n");
        exit(-1);
    }

    return p;
}

double **alloc_mem_ppdouble(size_t rows, size_t cols)
{
    double **pp = (double **)calloc(cols, sizeof(double *));

    if (!pp)
    {
        printf("Can't allocate memory for each row of matrix. Exiting with \'-1\' status\n");
        exit(-1);
    }

    for (size_t row = 0ul; row < rows; row++)
    {
        pp[row] = (double *)calloc(rows, sizeof(double));

        if (!pp[row])
        {
            printf("Can't allocate memory for each column of matrix. Exiting with \'-1\' status\n");
            exit(-1);
        }
    }

    return pp;
}
#endif // !_ALLOCATING_

#ifndef _DEALLOCATING_
void dealloc_mem_pint(int *pint)
{
    free(pint);
    pint = NULL;
}

void dealloc_mem_ppint(int **ppint, size_t rows)
{
    for (size_t row = 0ul; row < rows; row++)
    {
        free(ppint[row]);
        ppint[row] = NULL;
    }

    free(ppint);
    ppint = NULL;
}

void dealloc_mem_pchar(char *pchar)
{
    free(pchar);
    pchar = NULL;
}

void dealloc_mem_ppchar(char **ppchar, size_t rows)
{
    for (size_t row = 0ul; row < rows; row++)
    {
        free(ppchar[row]);
        ppchar[row] = NULL;
    }

    free(ppchar);
    ppchar = NULL;
}

void dealloc_mem_pdouble(double *pd)
{
    free(pd);
    pd = NULL;
}

void dealloc_mem_ppdouble(double **ppd, size_t rows)
{
    for (size_t row = 0ul; row < rows; row++)
    {
        free(ppd[row]);
        ppd[row] = NULL;
    }

    free(ppd);
    ppd = NULL;
}
#endif // !_DEALLOCATING_
#endif // !_MEMORY_

#ifndef _INPUT_
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

int *input_manual_pint(size_t size)
{
    int *parr = alloc_mem_pint(size);

    for (size_t i = 0ul; i < size; i++)
    {
        printf("parr[%lu] = ", i);
        parr[i] = input_int();
    }

    return parr;
}

int *input_random_pint(size_t size, int low, int high)
{
    srand(time(NULL));
    int *parr = alloc_mem_pint(size);

    // Filling array with random integer values
    for (size_t i = 0ul; i < size; i++)
        parr[i] = rand() % low + high;

    return parr;
}

int **input_manual_ppint(size_t rows, size_t cols)
{
    int **matrix = alloc_mem_ppint(rows, cols);

    for (size_t row = 0ul; row < rows; row++)
    {
        for (size_t col = 0ul; col < cols; col++)
        {
            printf("matrix[%ld][%ld] = ", row, col);
            matrix[row][col] = input_int();
        }
    }

    return matrix;
}

int **input_random_ppint(size_t rows, size_t cols, int low, int high)
{
    srand(time(NULL));
    int **matrix = alloc_mem_ppint(rows, cols);

    for (size_t row = 0ul; row < rows; row++)
    {
        for (size_t col = 0ul; col < cols; col++)
        {
            matrix[row][col] = rand() % low + high;
        }
    }

    return matrix;
}

double *input_random_pdouble(size_t size, double low, double high)
{
    srand(time(NULL));
    double *parr = alloc_mem_pdouble(size);

    // Filling array with random integer values
    for (size_t i = 0ul; i < size; i++)
    {
        double f = (double)rand() / RAND_MAX;
        parr[i] = low + f * (high - low);
    }

    return parr;
}

double **input_random_ppdouble(size_t rows, size_t cols, double low, double high)
{
    srand(time(NULL));
    double **matrix = alloc_mem_ppdouble(rows, cols);

    for (size_t row = 0ul; row < rows; row++)
    {
        for (size_t col = 0ul; col < cols; col++)
        {
            double f = (double)rand() / RAND_MAX;
            matrix[row][col] = low + f * (high - low);
        }
    }

    return matrix;
}
#endif // !_INPUT_

#ifndef _ALGORITHMS_

/**
 * @brief Counts number of digits in a number 'n'
 * @param n specified number to count it digits
 * @return Count of digits in number 'n'
 */
int get_count_of_digits_in_number(int n)
{
    int size = 0;
    while (n > 0)
    {
        n /= 10;
        size++;
    }
    return size;
}

int get_count_of_digits_in_number_v2(int n) { return floor(log10(n)) + 1; }

int *split_number_on_digits(int n)
{
    int size = get_count_of_digits_in_number(n), i = 0;
    int *digits = alloc_mem_pint(size);

    while (n > 0)
    {
        digits[i] = n % 10;
        n /= 10;
        i++;
    }
    return digits;
}

void reverse_pint(int *pint, int size)
{
    int temp = 0;
    for (int i = 0; i < size / 2; i++)
    {
        temp = pint[i];
        pint[i] = pint[size - i - 1];
        pint[size - i - 1] = temp;
    }
}

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

bool is_prime(int num)
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

void bubbleSortAscending(int arr[])
{
    for (size_t i = 0; i < ARRSIZE(arr); i++)
        for (size_t j = 0; j < ARRSIZE(arr); j++)
            if (arr[i] < arr[j])
                SWAP(arr[i], arr[j]);
}

void bubbleSortMatrixAscending(int **arr, size_t rows, size_t cols)
{
    // Perform bubble sort on the diagonal elements
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < rows; j++)
            for (int k = 0; k < cols; k++)
                for (int m = 0; m < cols; m++)
                    if (arr[i][k] < arr[j][m])
                    {
                        SWAP(arr[i][k], arr[j][m]);
                    }
}

void insertionSortAscending(int arr[])
{
    // Iterating by vector from 2nd element to end: [begin + 1; end]
    for (size_t i = 1ul; i < ARRSIZE(arr); i++)
    {
        // Initializing position of previous element from 'i'
        size_t j = i - 1ul;

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

void insertionSortMatrixAscending(int **arr, size_t rows, size_t cols)
{
    int *pint = alloc_mem_pint(rows * cols);
    matrixToArr(arr, pint, rows, cols);
    for (size_t i = 1; i < rows * cols; i++)
    {
        int val = pint[i];
        size_t pos = i - 1;
        while (pos < rows * cols && pint[pos] > val)
        {
            pint[pos + 1] = pint[pos];
            pos--;
        }
        pint[pos + 1] = val;
    }

    arrayToMatrix(pint, arr, rows, cols);
}

void selectionSortAscending(int arr[])
{
    // Iterating over the range
    for (size_t i = 0; i < ARRSIZE(arr); i++)
    {
        // For example, minimal element is begin element of the vector
        size_t minPos = i;

        // Iterating over the unsorted range
        for (size_t j = i + 1ul; j < ARRSIZE(arr); j++)
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

void selectionSortMatrixAscending(int **arr, size_t rows, size_t cols)
{
    for (size_t row = 0; row < rows; row++)
    {
        for (size_t col = 0; col < cols; col++)
        {
            size_t minRow = row, minCol = col;
            int min = arr[row][col];

            for (size_t j = col + 1; j < cols; j++)
            {
                if (arr[row][j] < min)
                {
                    minRow = row;
                    minCol = j;
                    min = arr[row][j];
                }
            }
            for (size_t i = row + 1; i < rows; i++)
            {
                for (size_t j = 0; j < cols; j++)
                {
                    if (arr[i][j] < min)
                    {
                        minRow = i;
                        minCol = j;
                        min = arr[i][j];
                    }
                }
            }
            arr[minRow][minCol] = arr[row][col];
            SWAP(arr[row][col], min);
        }
    }
}

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

void ShellSortMatrixAscending(int **arr, size_t rows, size_t cols)
{
    int *pint = alloc_mem_pint(rows * cols);
    matrixToArr(arr, pint, rows, cols);
    for (size_t gap = rows * cols / 2; gap > 0; gap /= 2)
    {
        for (size_t i = gap; i < rows * cols; i++)
        {
            int temp = pint[i];
            size_t j = i;
            while (j >= gap && pint[j - gap] > temp)
            {
                pint[j] = pint[j - gap];
                j -= gap;
            }
            pint[j] = temp;
        }
    }
    arrayToMatrix(pint, arr, rows, cols);
}

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

void quickSortAscending(int arr[])
{
    qSortAscending(arr, 0, ARRSIZE(arr) - 1);
}

void quickSortMatrixAscending(int **arr, size_t rows, size_t cols)
{
    int *pint = alloc_mem_pint(rows * cols);
    matrixToArr(arr, pint, rows, cols);
    quickSortAscending(pint);
    arrayToMatrix(pint, arr, rows, cols);
}

void bubbleSortDescending(int arr[])
{
    for (size_t i = 0; i < ARRSIZE(arr); i++)
        for (size_t j = 0; j < ARRSIZE(arr); j++)
            if (arr[i] > arr[j])
                SWAP(arr[i], arr[j]);
}

void insertionSortDescending(int arr[])
{
    // Iterating by vector from 2nd element to end: [begin + 1; end]
    for (size_t i = 1ul; i < ARRSIZE(arr); i++)
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

void selectionSortDescending(int arr[])
{
    // Iterating over the range
    for (size_t i = 0; i < ARRSIZE(arr); i++)
    {
        // For example, minimal element is begin element of the vector
        size_t maxPos = i;

        // Iterating over the unsorted range
        for (size_t j = i + 1ul; j < ARRSIZE(arr); j++)
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

void quickSortDescending(int arr[])
{
    qSortDescending(arr, 0, ARRSIZE(arr) - 1);
}

void matrixToArr(int **src, int *dest, size_t rows, size_t cols)
{
    size_t counter = 0;
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
        {
            dest[counter] = src[i][j];
            ++counter;
        }
}

void arrayToMatrix(int *src, int **dest, size_t rows, size_t cols)
{
    size_t counter = 0;
    for (size_t i = 0; i < rows && counter < rows * cols; i++)
        for (size_t j = 0; j < cols; j++)
        {
            dest[i][j] = src[counter];
            counter++;
        }
}

unsigned long hex_to_ulong(const char *str)
{
    return strtoul(str, NULL, 16);
}

char *str_to_upper(char *str)
{
    // If string is empty no need to perform any actions with it
    if (strlen(str) == 0)
        return "";

    char *copy = alloc_mem_pchar(strlen(str));
    strcpy(copy, str);

    // Modifying each character of string 'str' to uppercase
    for (size_t i = 0; i < strlen(str); i++)
        copy[i] = toupper(copy[i]);

    return copy;
}

char *str_to_lower(char *str)
{
    if (strlen(str) == 0)
        return "";
    char *copy = alloc_mem_pchar(strlen(str));
    strcpy(copy, str);
    for (size_t i = 0; i < strlen(str); i++)
        copy[i] = tolower(copy[i]);
    return copy;
}

char *int_to_hex(int value, size_t maxlen)
{
    char *hex = (char *)calloc(maxlen, sizeof(char));
    snprintf(hex, maxlen, "0x%X", value);
    return hex;
}

int hex_to_int(const char *hex, const char *format)
{
    unsigned res = 0;
    sscanf(hex, format, &res);
    return res;
}

void remove_char(char *str, char c)
{
    char *src = NULL, *dst = NULL;
    for (src = dst = str; *src != '\0'; src++)
    {
        *dst = *src;
        if (*dst != c)
            dst++;
    }
    *dst = '\0';
}

void remove_char_v2(const char *str_in, char *str_out, char c)
{
    do
    {
        if (*str_in++ != c)
            *str_out++ = *str_in;
    } while (*str_in++);
}

char *substr(const char *str, size_t begin, size_t end)
{
    // Check if ending position is lower then beginning
    // and ending position can't be greater then the length of string
    // or 'str' is not null pointer
    if (end <= begin || end > strlen(str) || !str)
        return NULL;

    // Allocating memory for substring
    char *substring = (char *)calloc(end - begin, sizeof(char));

    // Checking of properly allocating memory
    if (!substring)
        return NULL;

    // Copying content from the specified string in specified interval
    memcpy(substring, &str[begin], end - begin);
    return substring;
}
#endif // _ALGORITHMS_

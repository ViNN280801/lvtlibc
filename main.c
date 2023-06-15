#include "lvt.h"

int main()
{
    int *pint = (int *)calloc(100, sizeof(int));
    if (!pint)
        return -1;
    for (size_t i = 0; i < 99; i++)
        pint[i] = i;
    pint[100] = 0x00;

    char *str = "Hello, World!";

    PRINT_ARR(pint, 100);
    PRINT_ARR(str, 14);

    return 0;
}

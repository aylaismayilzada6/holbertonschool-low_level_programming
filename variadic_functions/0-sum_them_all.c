#include <stdarg.h>
#include "variadic_functions.h"

/**
 * sum_them_all - returns the sum of all its parameters
 * @n: number of arguments passed to the function
 *
 * Return: sum of arguments, or 0 if n == 0
 */
int sum_them_all(const unsigned int n, ...)
{
    va_list args;
    unsigned int i;
    int sum = 0;

    if (n == 0)
        return (0);

    va_start(args, n);

    /* Change 1: i < n ensures we stop at the correct count */
    for (i = 0; i < n; i++)
    {
        /* Change 2: Pass 'int' as the type, not the variable 'n' */
        sum += va_arg(args, int);
    }

    va_end(args);

    return (sum);
}

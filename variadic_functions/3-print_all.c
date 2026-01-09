#include <stdarg.h>
#include <stdio.h>

/**
 * struct printer - Struct to match format char with a function
 * @symbol: The format character (c, i, f, s)
 * @print: Pointer to the function that prints the type
 */
typedef struct printer
{
    char *symbol;
    void (*print)(va_list arg);
} p_t;

/* Helper functions to handle the printing */
void p_char(va_list arg) { printf("%c", va_arg(arg, int)); }
void p_int(va_list arg) { printf("%d", va_arg(arg, int)); }
void p_float(va_list arg) { printf("%f", va_arg(arg, double)); }
void p_string(va_list arg)
{
    char *str = va_arg(arg, char *);
    if (!str)
    {
        printf("(nil)");
        return;
    }
    printf("%s", str);
}

/**
 * print_all - Prints anything based on format
 * @format: list of types of arguments
 */
void print_all(const char * const format, ...)
{
    va_list args;
    int i = 0, j = 0;
    char *sep = "";
    p_t funcs[] = {
        {"c", p_char},
        {"i", p_int},
        {"f", p_float},
        {"s", p_string},
        {NULL, NULL}
    };

    va_start(args, format);

    while (format && format[i])
    {
        j = 0;
        while (funcs[j].symbol)
        {
            if (format[i] == *(funcs[j].symbol))
            {
                printf("%s", sep);
                funcs[j].print(args);
                sep = ", ";
            }
            j++;
        }
        i++;
    }

    printf("\n");
    va_end(args);
}

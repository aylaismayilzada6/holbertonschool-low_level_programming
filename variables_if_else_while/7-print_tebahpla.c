#include <stdlib.h>
#include <time.h>
#include <stdio.h>


/**
 * main - prints lowercase alphabet, then uppercase alphabet
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
        char c;

        for (c = 'z'; c >= 'a'; c--)
        {
                putchar(c);
        }
        
        putchar('\n');

        return (0);
}


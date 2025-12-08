#include "main.h"

/**
 * puts_half - prints the second half of a string,
 * followed by a new line
 * @str: pointer to the string
 *
 * Return: void
 */
void puts_half(char *str)
{
	int len = 0;
	int start;
	int i;

	if (!str)
		return;

	/* Calculate the length of the string */
	while (str[len] != '\0')
		len++;

	/* Determine the starting index for printing */
	if (len % 2 == 0)
		start = len / 2;
	else
		start = (len + 1) / 2;

	/* Print from start to end */
	for (i = start; i < len; i++)
		_putchar(str[i]);

	_putchar('\n');
}


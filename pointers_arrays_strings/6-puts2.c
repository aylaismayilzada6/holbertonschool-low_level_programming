#include "main.h"

/**
 * puts2 - prints every other character of a string,
 * starting with the first character, followed by a new line
 * @str: pointer to the string to print
 *
 * Return: void
 */
void puts2(char *str)
{
	int i = 0;

	if (!str)
		return;

	while (str[i] != '\0')
	{
		_putchar(str[i]);

		/* move to the next character to print */
		i += 2;

		/* safety check to avoid reading past null terminator */
		if (str[i] == '\0')
			break;
	}

	_putchar('\n');
}


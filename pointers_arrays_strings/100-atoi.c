#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 *
 * Return: the integer value, or 0 if no numbers
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int num = 0;
	int found = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign = -sign;

		if (s[i] >= '0' && s[i] <= '9')
		{
			found = 1;
			num = num * 10 + (s[i] - '0');
		}
		else if (found)
		{
			break;
		}

		i++;
	}

	return (num * sign);
}


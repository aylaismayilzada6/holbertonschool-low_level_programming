#include "main.h"
#include <limits.h>

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 *
 * Return: converted integer, or 0 if no digits found
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int num = 0;
	int found = 0;
	int digit;

	while (s[i] != '\0')
	{
		if (!found && s[i] == '-')
			sign = -sign;
		else if (!found && s[i] >= '0' && s[i] <= '9')
		{
			found = 1;
			digit = s[i] - '0';

			if (num < (INT_MIN + digit) / 10)
				return (sign == 1 ? INT_MAX : INT_MIN);

			num = num * 10 - digit;
		}
		else if (found && (s[i] < '0' || s[i] > '9'))
		{
			break;
		}

		i++;
	}

	if (!found)
		return (0);

	if (sign == 1)
	{
		if (num == INT_MIN)
			return (INT_MAX);
		return (-num);
	}

	return (num);
}


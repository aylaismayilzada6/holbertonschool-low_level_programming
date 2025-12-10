#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @s: the string to modify
 *
 * Return: pointer to the modified string
 */
char *cap_string(char *s)
{
	int i = 0, j;
	char separators[] = " \t\n,;.!?\"(){}";

	/* capitalize first character if needed */
	if (s[0] >= 'a' && s[0] <= 'z')
		s[0] -= 32;

	while (s[i] != '\0')
	{
		/* check if current char is a separator */
		for (j = 0; separators[j] != '\0'; j++)
		{
			if (s[i] == separators[j])
			{
				/* capitalize next character if lowercase letter */
				if (s[i + 1] >= 'a' && s[i + 1] <= 'z')
					s[i + 1] -= 32;
				break;
			}
		}
		i++;
	}

	return (s);
}


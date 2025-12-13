#include "main.h"
#include <stddef.h>

/**
 * _strstr - locates a substring
 * @haystack: string to be searched
 * @needle: substring to find
 *
 * Return: pointer to the beginning of the located substring,
 * or NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
	int i, j;

	/* If needle is empty, return haystack */
	if (needle[0] == '\0')
		return (haystack);

	for (i = 0; haystack[i] != '\0'; i++)
	{
		j = 0;

		while (haystack[i + j] == needle[j] && needle[j] != '\0')
		{
			j++;
		}

		if (needle[j] == '\0')
			return (&haystack[i]);
	}

	return (NULL);
}


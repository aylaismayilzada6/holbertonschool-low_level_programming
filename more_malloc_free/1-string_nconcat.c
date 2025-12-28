#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - concatenates two strings using n bytes of s2.
 * @s1: first string
 * @s2: second string
 * @n: number of bytes of s2 to concatenate
 *
 * Return: pointer to new string, or NULL on failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *str;
	unsigned int i, j, len1 = 0, len2 = 0;

	/* 1. Treat NULL as empty strings */
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* 2. Determine lengths of s1 and s2 */
	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;

	/* 3. If n >= len2, use the entire s2 string */
	if (n >= len2)
		n = len2;

	/* 4. Allocate space for s1 + n bytes of s2 + null terminator */
	str = malloc(sizeof(char) * (len1 + n + 1));

	if (str == NULL)
		return (NULL);

	/* 5. Copy s1 into the new space */
	for (i = 0; i < len1; i++)
		str[i] = s1[i];

	/* 6. Copy n bytes of s2 into the new space */
	for (j = 0; j < n; j++, i++)
		str[i] = s2[j];

	/* 7. Add null terminator */
	str[i] = '\0';

	return (str);
}

#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings.
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer to new string, or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	char *conct;
	int i, j, len1 = 0, len2 = 0;

	/* 1. Treat NULL as empty strings */
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* 2. Calculate lengths */
	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;

	/* 3. Malloc total size (+1 for '\0') */
	conct = malloc(sizeof(char) * (len1 + len2 + 1));

	/* Check for malloc failure */
	if (conct == NULL)
		return (NULL);

	/* 4. Copy s1 */
	for (i = 0; i < len1; i++)
		conct[i] = s1[i];

	/* 5. Copy s2 starting from the end of s1 */
	for (j = 0; j < len2; j++, i++)
		conct[i] = s2[j];

	/* 6. Add the null terminator */
	conct[i] = '\0';

	return (conct);
}

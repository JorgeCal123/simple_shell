#include "hsh.h"
/**
 * _strcat - concatenates 2 strings
 * @s1: first string
 * @s2: second string
 * Return: String complete
 */

char *_strcat(char *s1, char *s2)
{
	char *p;
	int i, j;
	int size_s1 = 0;
	int size_s2 = 0;

	if (s1 != NULL)
		size_s1 = strlen(s1);
	if (s2 != NULL)
		size_s2 = strlen(s2);
	p = malloc(sizeof(char) * (size_s1 + size_s2) + 1);
	if (p != NULL)
	{
		for (i = 0; i < size_s1; i++)
		{
			p[i] = s1[i];
		}
		i = 0;
		for (j = size_s1; j < (size_s1 + size_s2); j++)
		{
			p[j] = s2[i];
			i++;
		}
		return (p);
	}
	else
		return (NULL);
}

/**
 * _strdup - Copies a string pointed to by src, including the
 * terminating null byte
 * @src: The source string to copy.
 * Return: pointer destination dest.
 */
char *_strdup(char *src)
{
	int i = 0;
	char *dest;

	dest = malloc(sizeof(char) * _strlen(src));
	if (!dest)
	{
		fprintf(stderr, "error: allocation error");
		exit(EXIT_FAILURE);
	}
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strlen - function that returns the length of a string.
 * @dup: Pointers or arrays
 * Return: length of a string.
 */
int _strlen(char *dup)
{
	int cant = 0;

	while (dup[cant] != '\0')
		cant++;
	return (cant);
}
/**
 * _strcmp -  compares two strings.
 * @s1: first String
 * @s2: Second String
 * Return: integer less than, equal to, or greater than zero
 */
int _strcmp(char *s1, char *s2)
{
	int answer = 0;
	int i = 0;
	int stop = 1;

	while (s1[i] != '\0' && s2[i] != '\0' && stop)
	{
		if (s1[i] != s2[i])
		{
			answer = s1[i] - s2[i];
			stop = 0;
		}
		i++;
	}
	return (answer);
}

#include "Main.h"

/**
 * *_strcpy - copies the string pointed to by src
 * @dest: variable name
 * @src: variable name
 * Return: string
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	if (src[i] == '\0')
		dest[i] = '\0';
	return (dest);
}

/**
 * _strcat - Function that concatenates two strings.
 * @dest: input parameter
 * @src: input parameter
 * Return: pointer to the resulting string dest.
 */

char *_strcat(char *dest, char *src)
{
	int lendest;
	int lensrc;
	int lenfdest;
	int i;

	lendest = _strlen(dest);
	lensrc = _strlen(src);
	lenfdest = lendest + lensrc;
	i = 0;
	while (lendest <= lenfdest)
	{
		*(dest + lendest) = *(src + i);
		lendest++;
		i++;
	}
	return (dest);
}

/**
 * _strlen - returns the length of a string.
 * @s: Pointer to string to measure
 * Return: Lenght of the string
 */

int _strlen(char *s)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (*(s + i) != '\0')
	{
		len = len + 1;
		i++;
	}
	return (len);
}

/**
 * _strcmp - compares two strings
 * @s1: input parameter
 * @s2: input parameter
 *
 * Return: 0 if equal or b if is different
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0, j = 0;

	for ( ; s1[i] != '\0' && j == 0; i++)
		j = s1[i] - s2[i];
	return (j);
}

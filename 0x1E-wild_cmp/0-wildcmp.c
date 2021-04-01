#include "holberton.h"

/**
 * loop_recursion_star - get the last star in secuence of a string
 * @s2: string
 * Return: a pointer with the last start in secuence
 */
char *loop_recursion_star(char *s2)
{
	char *next_star = 0;

	if (s2[1] && s2[1] == '*')
	{
		next_star = loop_recursion_star(&(s2[1]));
	}
	else
	{
		next_star = s2;
	}
	return (next_star);
}

/**
 * wildcmp - compares two strings.
 * The special char * can replace any string (including an empty string)
 * @s1: string 1
 * @s2: string 2 can contain the special character *
 * Return: 1 if the strings can be considered identical, otherwise return 0
 */
int wildcmp(char *s1, char *s2)
{
	if (s1[0] == '\0' && s2[0] == '\0')
	{
		return (1);
	}

	if ((s1[0] == '\0' && s2[0] != '\0') || (s1[0] != '\0' && s2[0] == '\0'))
	{
		return (0);
	}

	if (s2[1] && s2[1] == '*')
	{
		wildcmp(s1, &(s2[1]));
	}

	if ((s1[0] == s2[0]) || s2[0] == '*')
	{
		s2 = loop_recursion_star(s2);
		if (wildcmp(&(s1[1]), &(s2[0])) || wildcmp(&(s1[1]), &(s2[1])))
		{
			return (1);
		}
	}
	return (0);
}

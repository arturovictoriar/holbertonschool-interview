#include "regex.h"

/**
 * regex_match - Checks whether a given pattern matches a given string
 * @str: can be empty, and can contain any ASCII character in
 * the exception of . and *
 * @pattern: can be empty, and can contain any ASCII character,
 * including . and *
 * Return: 1 if the pattern matches the string, or 0 if it doesnt
 */
int regex_match(char const *str, char const *pattern)
{
	if (str[0] == '\0' && pattern[0] == '\0')
		return (1);
	else if (pattern[0] == '*')
	{
		if (regex_match(str, &pattern[1]) == 1)
			return (1);
	}
	else if (str[0] == '\0' && pattern[0] == '.')
	{
		if (regex_match(str, &pattern[1]) == 1)
			return (1);
	}
	else if (str[0] == pattern[0] && pattern[1] != '*')
	{
		if (regex_match(&str[1], &pattern[1]) == 1)
			return (1);
	}
	else if ((str[0] == pattern[0] || pattern[0] == '.') && pattern[1] == '*')
	{
		if (regex_match(&str[1], &pattern[0]) == 1)
			return (1);
		if (regex_match(&str[1], &pattern[1]) == 1)
			return (1);
		if (regex_match(&str[0], &pattern[1]) == 1)
			return (1);
	}
	else if (str[0] != pattern[0] && pattern[1] == '*')
	{
		if (regex_match(&str[0], &pattern[1]) == 1)
			return (1);
	}
	else if (str[0] != '\0' && pattern[0] == '.' && pattern[1] != '*')
	{
		if (regex_match(&str[1], &pattern[1]) == 1)
			return (1);
	}
	return (0);
}

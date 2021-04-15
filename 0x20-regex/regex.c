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
	int ismatch = 0;

	if (str[0] == '\0' && pattern[0] == '\0')
		return (1);
	if ((str[0] == pattern[0] || pattern[0] == '.') && pattern[1] != '*')
		return (regex_match(&str[1], &pattern[1]));
	if (pattern[1] == '*')
	{
		if (str[0] != '\0' && (str[0] == pattern[0] || pattern[0] == '.'))
			ismatch = regex_match(&str[1], pattern);
		return (regex_match(str, &pattern[2]) || ismatch);
	}
	return (0);
}

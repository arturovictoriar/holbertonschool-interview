#include "palindrome.h"

/**
* is_palindrome - find if a looong number is palindrome
* @n: a looooong number
* Return: 1 palindrome 0 otherwise
*/
int is_palindrome(unsigned long n)
{
	int num[20] = {0};
	int i = 0, len_num = 0;
	unsigned long ul_num = n;

	do {
		ul_num /= 10, len_num++;
	} while (ul_num);

	if (len_num == 1)
		return (1);

	for (i = 0; i < len_num; i++)
		num[len_num - 1 - i] = n % 10, n /= 10;

	for (i = 0; i < len_num; i++)
	{
		if (i > len_num / 2)
			break;
		else if (num[i] == num[len_num - 1 - i])
			continue;
		else
			return (0);
	}
	return (1);
}

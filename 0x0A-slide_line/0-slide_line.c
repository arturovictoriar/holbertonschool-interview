#include "slide_line.h"

/**
* left_move - slide a line to left
* @line: array of numbers (the line)
* @size: size of the array
* Return: nothing
*/
void left_move(int *line, size_t size)
{
	unsigned int pair_num = 0, zero_num = 0;
	int i = 0, j = 0;

	for (i = 0; i < (int) size; i++)
	{
		zero_num = 0;
		if (line[i])
		{
			for (j = i - 1; j > -1; j--)
			{
				if (j == 0 && line[j] == 0)
				{
					pair_num = 0;
					line[j] = line[i];
					line[i] = 0;
					break;
				}
				else if ((line[j] != 0 && line[i] != line[j]
					&& zero_num && j + 1 < (int) size)
					|| (line[j] == line[i] && pair_num))
				{
					pair_num = 0;
					line[j + 1] = line[i];
					line[i] = 0;
					break;
				}
				else if (!pair_num && line[i] == line[j])
				{
					pair_num = 1;
					line[j] += line[i];
					line[i] = 0;
					break;
				}
				else if (line[j] != 0 && line[i] != line[j])
					break;
				else if (line[j] == 0)
					zero_num = 1;
			}
		}
	}
}

/**
* right_move - slide a line to right
* @line: array of numbers (the line)
* @size: size of the array
* Return: nothing
*/
void right_move(int *line, size_t size)
{
	unsigned int pair_num = 0, zero_num = 0;
	int i = 0, j = 0;

	for (i = (int) size - 1; i >= 0; i--)
	{
		zero_num = 0;
		if (line[i])
		{
			for (j = i + 1; j < (int) size; j++)
			{
				if (j == (int) size - 1 && line[j] == 0)
				{
					pair_num = 0;
					line[j] = line[i];
					line[i] = 0;
					break;
				}
				else if ((line[j] != 0 && line[i] != line[j]
					&& zero_num && j - 1 >= 0)
					|| (line[j] == line[i] && pair_num))
				{
					pair_num = 0;
					line[j - 1] = line[i];
					line[i] = 0;
					break;
				}
				else if (!pair_num && line[i] == line[j])
				{
					pair_num = 1;
					line[j] += line[i];
					line[i] = 0;
					break;
				}
				else if (line[j] != 0 && line[i] != line[j])
					break;
				else if (line[j] == 0)
					zero_num = 1;
			}
		}
	}
}

/**
* slide_line - slide a complete line, as 2048 game do, on right or left
* @line: array of numbers (the line)
* @size: size of the array
* @direction: direction to slide the line
* Return: 1 on success, 0 otherwise
*/
int slide_line(int *line, size_t size, int direction)
{
	if (!line)
		return (0);
	if (direction)
		right_move(line, size);
	else
		left_move(line, size);
	return (1);
}

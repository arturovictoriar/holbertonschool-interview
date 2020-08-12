#include "sandpiles.h"

/**
 * print_grid - print the matrix grid
 * @grid: matriz pile
 * Return: nothing
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * make_toppling - stabilize the grid piles
 * @grid1: matriz pile
 * Return: nothing
 */
void make_toppling(int grid1[3][3])
{
	int i = 0, j = 0, flag_stable = 0;
	int sand_grid1[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	do {
		printf("=\n");
		print_grid(grid1);
		flag_stable = 0;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					grid1[i][j] -= 4;
					if (j - 1 >= 0)
						sand_grid1[i][j - 1]++;
					if (i - 1 >= 0)
						sand_grid1[i - 1][j]++;
					if (j + 1 <= 2)
						sand_grid1[i][j + 1]++;
					if (i + 1 <= 2)
						sand_grid1[i + 1][j]++;
				}
			}
		}
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				grid1[i][j] = grid1[i][j] + sand_grid1[i][j];
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3 && !flag_stable)
					flag_stable = 1;
				sand_grid1[i][j] = 0;
			}
		}
	} while (flag_stable);
}

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: matriz pile
 * @grid2: matriz pile
 * Return: nothing
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i = 0, j = 0, flag_stable = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
			if (grid1[i][j] > 3 && !flag_stable)
				flag_stable = 1;
		}
	}

	if (!flag_stable)
		return;
	make_toppling(grid1);
}

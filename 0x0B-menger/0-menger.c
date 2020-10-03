#include "menger.h"

/**
* menger - print a menger sponge
* @level: sponge level
* Return: nothing
*/
void menger(int level)
{
	int sponge[1200][1200] = {{0}}, i = 0, j = 0, ori_level = 0, k = 0, l = 0;
	unsigned int start_margin_x = 0, start_margin_y = 0;

	if (level < 0)
		return;

	ori_level = level;
	while (level > 0)
	{
		for (k = 0; k < pow(3, ori_level - level); k++)
		{
			for (l = 0; l < pow(3, ori_level - level); l++)
			{
				start_margin_x = (pow(3, level) / 3);
				start_margin_x += !k ? 1 : (1 + pow(3, level) * k);
				start_margin_y = (pow(3, level) / 3);
				start_margin_y += !l ? 1 : (1 + pow(3, level) * l);
				for (i = start_margin_x; i < start_margin_x + pow(3, level - 1); i++)
					for (j = start_margin_y; j < start_margin_y + pow(3, level - 1); j++)
						sponge[i - 1][j - 1] = 1;
			}
		}
		level--;
	}

	for (i = 0; i < pow(3, ori_level); i++)
	{
		for (j = 0; j < pow(3, ori_level); j++)
			!sponge[i][j] ? printf("#") : printf(" ");
		printf("\n");
	}
}

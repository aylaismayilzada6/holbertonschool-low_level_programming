#include "main.h"
#include <stdlib.h>

/**
 * free_grid - frees a 2 dimensional grid previously created
 * by your alloc_grid function.
 * @grid: the 2D array to be freed
 * @height: the height of the grid
 *
 * Return: Nothing.
 */
void free_grid(int **grid, int height)
{
	int i;

	/* 1. Safety check: If the grid is already NULL, do nothing */
	if (grid == NULL)
		return;

	/* 2. Loop through each row and free it */
	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}

	/* 3. Free the main array of pointers */
	free(grid);
}

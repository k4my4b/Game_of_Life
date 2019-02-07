#include <stdio.h>
#include <stdlib.h>

#include "gridio.h"

#define unreadable_entry "Unable to read entry (%ld:%ld).\n"
#define invalid_entry "Illegal entry value %d for cell (%ld:%ld).\n"
#define grid_width_err "Unable to read grid width.\n"
#define malloc_err "Unable to allocate %ld bytes.\n"

/**
 * helper function for read_seed_grid(...) assumes that the first line of the file
 * describes the size of the grid 
 * @param file containing the seed grid
 * @return the size of the grid
 */
static inline long get_width(FILE* file)
{
    long width; /* size of the grid */

    if (fscanf(file, "%ld", &width) != 1)
    {
        fprintf(stderr, "%s", grid_width_err);
        exit(EXIT_FAILURE); /* exit with failure flag*/
    }

    return width;
}

GRID* read_seed_grid(FILE* file)
{
    GRID* grid = (GRID*) malloc(sizeof (GRID)); /* array of ones and zeroes where 1 = live cell 0 = empty cell */

    long width = get_width(file); /* get the size of the grid from the file */

    long i, j; /* loop counters */

    int value; /* value read from input file */

    /* allocate memory for a 2d grid with dimensions "width" */
    if ((grid->cells = (int*) malloc((width * width) * sizeof (int))) == NULL)
    {
        fprintf(stderr, malloc_err, sizeof (int) * width * width);
    }

    for (i = 0; i < width; ++i)
    {
        for (j = 0; j < width; ++j)
        {
            /* attempt to read next entry */
            if (fscanf(file, "%d", &value) != 1)
            {
                fprintf(stderr, unreadable_entry, i, j);
                /* free memory and close file */
                free(grid);
            }
            else
            {
                /* sanity check */
                if ((value == 0) || (value == 1))
                {
                    grid->cells[i * width + j] = value; /* if all went well add the cell to grid.cells */
                }
                else
                {
                    fprintf(stderr, invalid_entry, value, i, j);
                    /* free memory and close file */
                    free(grid);
                }
            }
        }
    }

    grid->width = width; /* size of grid is self-contained so set the size once we get it */

    return grid;
}

void print_grid(const GRID* grid)
{
    int i, j; /* loop counters */

    for (i = 0; i <= grid->width; ++i)
    {
        /* print horizontal lines */
        for (j = 0; j < (grid->width * 4) + 1; ++j)
        {
            fprintf(stdout, "-");
        }
        fprintf(stdout, "\n");

        /* print the vertical lines + cell values */
        if (i != grid->width)
        {
            for (j = 0; j < ((grid->width * 2) + 1); ++j)
            {
                if (j % 2 == 0)
                {
                    fprintf(stdout, "| ");
                }
                else
                {
                    if (grid->cells[i * (grid->width) + (j / 2)] == 1)
                    {
                        fprintf(stdout, "x ");
                    }
                    else
                    {
                        fprintf(stdout, ". ");
                    }
                }
            }
            fprintf(stdout, "\n");
        }
    }
}
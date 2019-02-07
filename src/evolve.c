#include <stdio.h>
#include <stdlib.h>

#include "evolve.h"
#include "gridio.h"

/* #define ALT_COUNT to use the alternative function for counting alive cells */
#ifndef ALT_COUNT 

/* row and column index offset for following neighbours of cell(x,y) */
int neighbour_offset[8][2] = {
    {-1, -1}, /* top left */
    {-1, 0}, /* top */
    {-1, +1}, /* top right */
    {0, -1}, /* left */
    {0, +1}, /* right */
    {+1, -1}, /* bottom left */
    {+1, 0}, /* bottom */
    {+1, +1}, /* bottom right */
};

int count_alive_neighbours(GRID* grid, int x, int y)
{
    int i; /* loop counter */
    int _x, _y; /* row and column index of neighbours */
    int alive = 0; /* total number of alive neighbours so far */

    /* iterate over the 8 neighbourhood */
    for (i = 0; i < 8; ++i)
    {
        /* calculate the x and y position of the neighbour using the lookup table */
        _x = x + neighbour_offset[i][0];
        _y = y + neighbour_offset[i][1];

        /* make sure the calculated position is within bounds i.e. side cells */
        if ((_x < grid->width) && (_y < grid->width) && (_x >= 0) && (_y >= 0)) /* bound check */
        {
            alive += grid->cells[_x * grid->width + _y]; /* cells[_x][_y] == 1 OR 0 */
        }
    }

    return alive;
}

#else

int count_alive_neighbours(GRID* grid, int x, int y)
{
    int i, j; /* loop counters */
    int alive = 0; /* total number of alive neighbouring cells of (x,y) */

    for (i = (x - 1); i <= (x + 1); ++i) /* i-1 = left west neighbour, i+1 = right neighbour */
    {
        for (j = (y - 1); j <= (y + 1); ++j) /* j-1 = top neighbour, j+1 = bottom neighbour */
        {
            if ((i != x) || (j != y)) /* skip the the cell at (x,y) we only want the neighbours */
            {
                if ((i < grid->width) && (j < grid->width) && (i >= 0) && (j >= 0)) /* bound check */
                {
                    alive += grid->cells[i * grid->width + j]; /* cells[i][j] == 1 OR 0 */
                }
            }
        }
    }

    return alive;
}

#endif

void evolve(GRID* grid)
{
    int i, j; /* loop counters */

    int alive; /* holds number of alive neighbours of cell(i,j) */

	/* holds evolved cells */
    int* cells = (int*) malloc(sizeof (int) * (grid->width) * (grid->width));

    for (i = 0; i < grid->width; ++i)
    {
        for (j = 0; j < grid->width; ++j)
        {
            alive = count_alive_neighbours(grid, i, j); /* count the number of alive neighbours */

            if (grid->cells[i * (grid->width) + j]) /* if cell itself is alive */
            {
                if ((alive < 4) && (alive > 1)) /* if the cell has 2 or 3 alive neighbours */
                {
                    cells[i * (grid->width) + j] = 1; /* then it stays alive */
                }
                else
                {
                    cells[i * (grid->width) + j] = 0; /* otherwise it dies */
                }
            }
            else /* otherwise if the cell is dead/empty */
            {
                if (alive != 3) /* it stays dead unless it has 3 neighbours */
                {
                    cells[i * (grid->width) + j] = 0;
                }
                else
                {
                    cells[i * (grid->width) + j] = 1;
                }
            }
        }
    }

    /* delete the previous cells */
    free(grid->cells);

    /* update the grid with the evovled cells */
    grid->cells = cells;
}


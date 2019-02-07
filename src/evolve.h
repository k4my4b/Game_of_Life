#ifndef EVOLVE_H
#define EVOLVE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef GRID_H
#include "grid.h"
#endif

    /**
     * count the number of alive cells which are neighbour of cell(x,y)
     * @param grid The grid
     * @param x coordinate of the cell (row index)
     * @param y coordinate of the cell (column index)
     * @return number of alive neighbours, 0 if none exist
     */
    extern int count_alive_neighbours(GRID* grid, int x, int y);

    /**
     * "evolve" the cells one generation using the following rules: 
     * *all cells interact with their eight-neighbourhood*
     *  - if a cell is alive 
     *      then it stays alive if it has 2 or 3 living neighbours 
     *      otherwise it dies due to over-population or under-population
     *  - if a cell is dead/empty 
     *      then a cell is born in that location if it has exactly 3 living neighbours 
     *      otherwise it says dead/empty    
     * @param grid to operate on
     */
    extern void evolve(GRID* grid);

#ifdef __cplusplus
}
#endif

#endif /* EVOLVE_H */


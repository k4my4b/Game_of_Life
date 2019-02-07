#ifndef GRIDIO_H
#define GRIDIO_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef GRID_H
#include "grid.h"
#endif

    /**
     * Reads in the seed grid from file and construct a representation in memory. 
     * The file is expected to have the width/size of the grid on the first line 
     * followed by subsequent rows and columns of ones and zeroes separated by space,
     * for example:  
     *                  3           // size 
     *                  0 0 0       // first row
     *                  1 1 1       // ... 
     *                  0 0 0       // last row 
     * 
     * @param file containing the seed grid 
     * @return pointer to grid read from the file
     */
    extern GRID* read_seed_grid(FILE* file);

    /**
     * print out a formatted and styled interpretation  of the grid onto stdout
     * @param grid of N x N cells of ones and zeroes
     */
    extern void print_grid(const GRID* grid);

#ifdef __cplusplus
}
#endif

#endif /* GRIDIO_H */


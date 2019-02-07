#ifndef GRID_H
#define GRID_H

#ifdef __cplusplus
extern "C" {
#endif

    /* N x N grid */
    typedef struct grid {
        int* cells;
        long width; /* self contained width/size */
    } GRID;

#ifdef __cplusplus
}
#endif

#endif /* GRID_H */


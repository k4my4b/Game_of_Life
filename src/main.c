#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "read_stdin.h"
#include "open_file.h"
#include "gridio.h"
#include "evolve.h"

/*
 * add/modify static messages/strings here
 */
#define get_file_msg "Please enter URI of seed-grid file:"
#define get_gen "How many generation(s) would you like to see?"

int main(int argc, char** argv)
{
    FILE* file; /* file pointer to a file containing seed grid */

    if (argc < 2) /* if file URI was not passed in then ask for it */
    {
        /* get the the file URI from user */
        char* file_uri = read_stdin(get_file_msg);

        /* try to open the file */
        file = open_file(file_uri, "r");

        /* free the memory for URI string, no longer needed */
        free(file_uri);
    }
    else /* otherwise use the one that was passed in */
    {
        file = open_file(argv[1], "r");
    }

    GRID* grid = read_seed_grid(file); /* seed grid */

    /* how many runs of evolution should take place */
    long gen;
    fprintf(stdout, "%s\n", get_gen);
    fscanf(stdin, "%ld", &gen);

    /* evolve the grid "gen" number of times */
    for (long x = 0; x <= gen; ++x)
    {
        /* print generation count and the grid */
        fprintf(stdout, "Generation: %ld\n", x);
        print_grid(grid);
        
        /* evolve cells */
        evolve(grid);
    }

    fclose(file); /* close file to avoid unused open files */

    /* release memory used for grid */
    free(grid->cells);
    free(grid);

    return (EXIT_SUCCESS);
}

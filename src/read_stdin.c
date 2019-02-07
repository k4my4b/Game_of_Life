#include <stdlib.h>
#include <stdio.h>
#include "read_stdin.h"

#define init_cap 1024
#define trim_fail "realloc() failed while trying to trim excess buffer\n"
#define str_too_long "Oops! input was too long\n"

char* read_stdin(const char* msg)
{
    fprintf(stdout, "%s\n", msg);

    long cap = init_cap; /* capacity of the string char array with initial size 1024 */

    long len = 0; /* current length of the char array */
    
    int _char; /* single character read from stdin */

    char* str_buffer = (char*) malloc(init_cap * sizeof (char)); /* dynamic string buffer */

    while ((_char = fgetc(stdin)) != EOF)
    {
        if (_char != '\n') /* check for new-line */
        {
            str_buffer[len] = _char; /* if not a new-line character simply add it to the string array */
        }
        else /* if we hit new-line, add terminating null and exit */
        {
            str_buffer[len] = '\0';
            break;
        }

        ++len; /* increment length of string */

        if (len >= cap) /* if new length is equal to capacity double the buffer for some headroom*/
        {
            if ((str_buffer = (char*) realloc(str_buffer, (cap *= 2) * sizeof (char))) == NULL)
            {
                fprintf(stderr, str_too_long);
            }
        }
        else
        {
            continue;
        }
    }

    /* trim the excess buffer, if buffer is not empty */
    if (len < cap && len != 0)
    {
        if ((str_buffer = (char*) realloc(str_buffer, len * sizeof (char))) == NULL)
        {
            fprintf(stderr, trim_fail);
        }
    }

    return str_buffer;
}
#ifndef READ_STDIN_H
#define READ_STDIN_H

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * &#42; dynamic memory allocation! input can be of any size as long as we have memory for it &#42;
     * &#42;&#42; memory leak! free returned string once it is no longer needed &#42;&#42;
     * @param msg message to be displayed for input e.g. ask for something specific 
     * @return user input from stdin (keyboard). 
     */
    extern char* read_stdin(const char* msg);

#ifdef __cplusplus
}
#endif

#endif /* READ_STDIN_H */


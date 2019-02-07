#ifndef OPEN_FILE_H
#define OPEN_FILE_H

#ifdef __cplusplus
extern "C" {
#endif

#define open_file_err "Could not open file: %s\n" 

    /**
     * @param file_address of the file to open and read from 
     */
    static inline FILE* open_file(const char* file_address, const char* mode) {
        FILE* file;

        if ((file = fopen(file_address, mode)) == NULL) {
            fprintf(stderr, open_file_err, file_address);
            exit(EXIT_FAILURE);
        }

        return file;
    }

#ifdef __cplusplus
}
#endif

#endif /* OPEN_FILE_H */


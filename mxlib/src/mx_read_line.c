#include "../inc/libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    static off_t file_position = 0;  
    ssize_t total_bytes = 0;  
    ssize_t read_bytes;  
    char *buffer = (char *)malloc(buf_size);  

    if (fd < 0)
        return -2;  

    *lineptr = NULL;  

    while ((read_bytes = read(fd, buffer, buf_size)) > 0) {
    
    for (ssize_t i = 0; i < read_bytes; ++i) {
        if (buffer[i] == delim || buffer[i] == -1) {  
            
            *lineptr = (char *)mx_realloc(*lineptr, total_bytes + i + 1);
            if (*lineptr == NULL) {
                free(buffer);
                return -2;  
            }
            
            mx_memcpy(*lineptr + total_bytes, buffer, i);
            total_bytes += i;
            (*lineptr)[total_bytes] = '\0';

            
            file_position += total_bytes + 1;  
            lseek(fd, file_position, SEEK_SET);
            free(buffer);
            return total_bytes;
        }
    }

    *lineptr = (char *)mx_realloc(*lineptr, total_bytes + read_bytes + 1);
    if (*lineptr == NULL) {
        free(buffer);
        return -2;  
    }
    mx_memcpy(*lineptr + total_bytes, buffer, read_bytes);  
    total_bytes += read_bytes;
}

    if (read_bytes == 0 && total_bytes > 0) {
        
        free(buffer);
        return -1;
    } else {
        free(buffer);
        return -2;  
    }
}


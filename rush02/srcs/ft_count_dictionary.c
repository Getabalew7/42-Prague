#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 4096
void	ft_print_str(char *str);
int ft_count_lines(const char* filename) {
    int file = open(filename, O_RDONLY);
    if (file == -1) {
        ft_print_str("Dict Error\n");
        return -1;
    }

    int lineCount = 0;
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

    while ((bytesRead = read(file, buffer, sizeof(buffer))) > 0) {
        for (ssize_t i = 0; i < bytesRead; i++) {
            if (buffer[i] == '\n') {
                lineCount++;
            }
        }
    }

    close(file);
    return lineCount;
}
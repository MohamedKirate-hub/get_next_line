#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int main()
{
    char *line;
    int fd;
    
    fd = open("file.txt", O_RDONLY);
    line = get_next_line_v1(fd);
    printf("%s",line);
    free(line);
    line = get_next_line_v1(fd);
    printf("%s",line);
    free(line);
    return (0);
}
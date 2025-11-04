#include "get_next_line.h"
#include <stdio.h>

int main()
{
    char *line;
    line = NULL;
    int fd = open("file.txt", O_RDONLY);
    line = get_next_line(fd);
    printf("%s",line);
    free(line);

    line = get_next_line(fd);
    printf("%s",line);
    free(line);

    line = get_next_line(fd);
    printf("%s",line);
    free(line);

    line = get_next_line(fd);
    printf("%s",line);
}
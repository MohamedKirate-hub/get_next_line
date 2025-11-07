#include "get_next_line.h"
#include <stdio.h>

int main()
{
    int fd1 = open("kjv.txt", O_RDONLY);
    if (fd1 < 0)
        return (printf("Error in fd"));

    char *line;
    while (((line = get_next_line(fd1)) != NULL))
    {
        printf("%s", line);
        free(line);
    }
    printf("%s", line);
    free(line);
}
#include "get_next_line.h"
#include <stdio.h>

int main()
{
    char *line;
    line = NULL;
    int fd = open("file.txt", O_RDONLY);
    
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    printf("%s", line);
    free(line);
    return (0);
}
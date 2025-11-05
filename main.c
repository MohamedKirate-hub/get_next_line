#include "get_next_line_bonus.h"
#include <stdio.h>

int main()
{
    int fd1 = open("file.txt", O_RDONLY);
    int fd2 = open("kjv.txt", O_RDONLY);
    if (fd1 < 0 || fd2 < 0)
        return (printf("Error in fd"));

    char *line;
    char *line2 ;
    while ((line = get_next_line_bonus(fd1)) != NULL 
            && (line2 = get_next_line_bonus(fd2)) != NULL)
    {
        printf("%s", line);
        free(line);

        printf("%s", line2);
        free(line2);
    }
    free(line);
    free(line2);
}
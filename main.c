#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

char *test(int fd)
{
    static char data[5000];
    char *storage;
    int i;
    static int offset;
    static int read_size;
    int len;

    offset = 0;
    read_size = 0;
    if (offset >= read_size)
        read_size = read(fd, data, BUFFER_SIZE);
    i = offset;
    printf("i = %d , read_size = %d", i, read_size);
    while (i < read_size && data[i] != '\n')
        i++;
    len = i;
    storage = (char *)malloc(sizeof(char) * (len + 1));
    if (!storage)
        return (NULL);
    ft_strncpy(storage, data + offset, len);
    if (i < read_size && data[i] != '\n')
    {
        storage[len] = '\n';
        storage[len + 1] = '\0';
        offset = len + 1;
        return (storage);
    }
    else
    {
        offset = len;
        char *new_storage = get_next_line(fd);
        if (!new_storage)
            return (NULL);
        char *result = ft_strjoin(storage, new_storage);
        free(storage);
        free(new_storage);
        return (result);
    }
}
int main()
{
    int fd = open("file.txt", O_RDONLY);
    printf("%s",test(fd));
    printf("%s",test(fd));
    return (0);
}
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>


void ft_test()
{
    int fd = open("file.txt", O_RDONLY);
    char data[1000];
    int read_size = read(fd, data, 10);
    printf("%s +++=", data);
}
int main()
{
    ft_test();
    ft_test();
}

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int     main(void)
{
    int fd;

    fd = open("cub3d.c", O_RDONLY);
    fd = -1;
    if (fd == -1)
    {
        perror("open");
        exit(1);
    }
    return (0);
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 32

ssize_t ft_strcpy(char *s1, char **s2, ssize_t n, ssize_t size)
{
    ssize_t i;

    if (n == 0)
        while (s1[n])
            n++;
    if (!(*s2 = (char *)malloc(sizeof(char) * (n + size + 1))))
        return (0);
    i = 0;
    while (i < n)
    {
        (*s2)[i] = s1[i];
        i++;
    }
    (*s2)[i] = '\0';
    return (i);
}
void    ft_strcat(char *buf, char **backup, ssize_t read_size)
{
    char    *temp;
    ssize_t len;
    ssize_t i;

    if (*backup == NULL)
        ft_strcpy(buf, backup, 0, 0);
    else
    {
        temp = NULL;
        len = ft_strcpy(*backup, &temp, 0, read_size);
        i = 0;
        while (buf[i])
        {
            temp[len] = buf[i];
            len++;
            i++;
        }
        temp[len] = '\0';
        ft_strcpy(temp, backup, 0, 0);
    }
}

ssize_t ft_cutline(char *backup, char **line)
{
    ssize_t cut;

    if (backup[0] == '\n')
    {
        if (!(*line = (char *)malloc(sizeof(char) * 1)))
            return (-1);
        (*line)[0] = '\0';
        return (0);
    }
    cut = 0;
    while (backup[cut] != '\0')
    {
        if (backup[cut] == '\n')
            break;
        cut++;
    }
    if (backup[cut] == '\0')
        return (-1);
    ft_strcpy(backup, line, cut, 0);
    return (cut);
}

int get_next_line(int fd, char **line)
{
    char        buf[BUFFER_SIZE + 1];
    static char *backup;
    ssize_t     read_size;
    ssize_t     cut;

    if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
        return (-1);
    while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
    {
        buf[read_size] = '\0';
        ft_strcat(buf, &backup, read_size);
        if (backup != NULL)
            if ((cut = ft_cutline(backup, line)) >= 0)
            {
                backup = &backup[cut + 1];
                return (1);
            }
    }
    if (backup == NULL)
        return (0);
    if ((cut = ft_cutline(backup, line)) >= 0)
    {
        backup = &backup[cut + 1];
        return (1);
    }
    ft_strcpy(backup, line, 0, 0);
    free(backup);
    backup = NULL;
    return (1);
}

int main(void)
{
	char	*line = 0;
	int 	ret;
	int		fd;
	
	fd = open("./test.txt", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("result = %s\n", line);
		free(line);
	}
	free(line);
	close(fd);
	return (0);
}

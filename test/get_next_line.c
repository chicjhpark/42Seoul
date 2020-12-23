#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 31

ssize_t ft_strncpy(char *s1, char **s2, ssize_t n, ssize_t read_size)
{
    ssize_t i;

    if (n == 0)
    {
        while (s1[n])
            n++;
    }
    if(!(*s2 = (char *)malloc(sizeof(char) * (n + read_size + 1))))
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

void    ft_arrange(char *buf, char **backup, ssize_t read_size)
{
    char    *temp;
    ssize_t len;
    ssize_t i;

    if (*backup == NULL)
        ft_strncpy(buf, backup, 0, 0);
    else
    {
        temp = NULL;
        len = ft_strncpy(*backup, &temp, 0, read_size);
        free(backup);
        i = 0;
        while (buf[i])
        {
            temp[len] = buf[i];
            len++;
            i++;
        }
        temp[len] = '\0';
        ft_strncpy(temp, backup, 0, 0);
    }
}

ssize_t ft_cutline(char *backup, char **line)
{
    ssize_t cut;

    if (backup == NULL)
        return (0);
    cut = 0;
    while (backup[cut])
    {
        if (backup[cut] == '\n')
            break;
        cut++;
    }
    if (!backup[cut])
        return (0);
    ft_strncpy(backup, line, cut, 0);
    return (cut);
}

int     get_next_line(int fd, char **line)
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
        ft_arrange(buf, &backup, read_size);
        if ((cut = ft_cutline(backup, line)) > 0)
        {
            if (read_size == BUFFER_SIZE)
                backup = &backup[cut + 1];
            return (1);
        }
    }
    ft_strncpy(backup, line, 0, 0);
    return (0);
}

int main(void)
{
	char	*line = 0;
	int 	ret;
	int		fd;
	
	fd = open("C:\\Users\\Administrator\\42Seoul\\test\\test.txt", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("result = %s\n", line);
		free(line);
	}
	free(line);
	close(fd);
	return (0);
}
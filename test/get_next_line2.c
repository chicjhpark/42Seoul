#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 3

ssize_t ft_strlen(char *s)
{
    ssize_t i;

    if (s == NULL)
        return (-1);
    i = 0;
    while (s[i])
        i++;
    return (i);
}

void    ft_strncpy(char *s1, char **s2, ssize_t n)
{
    ssize_t i;

    if (!(*s2 = (char *)malloc(sizeof(char) * (n + 1))))
        return ;
    i = 0;
    while (i < n)
    {
        (*s2)[i] = s1[i];
        i++;
    }
    (*s2)[i] = '\0';
}

void    ft_strjoin(char *backup, char *buf, char **temp)
{
    ssize_t len1;
    ssize_t len2;
    ssize_t i;

    len1 = ft_strlen(backup);
    len2 = ft_strlen(buf);
    if (!(*temp = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
        return ;
    i = 0;
    while (i < len1)
    {
        (*temp)[i] = backup[i];
        i++;
    }
    i = 0;
    while (i < len2)
    {
        (*temp)[len1] = buf[i];
        len1++;
        i++;
    }
    (*temp)[len1] = '\0';
}

void    ft_strcat(char *buf, char **backup)
{
    char    *temp;

    if (*backup == NULL)
        ft_strncpy(buf, backup, ft_strlen(buf));
    else
    {
        temp = NULL;
        ft_strjoin(*backup, buf, &temp);
        free(*backup);
        ft_strncpy(temp, backup, ft_strlen(temp));
        free(temp);
    }
    
}

ssize_t ft_strline(char *backup)
{
    ssize_t i;

    if (backup == NULL)
        return (-1);
    i = 0;
    while (backup[i])
    {
        if (backup[i] == '\n')
            return (i);
        i++;
    }
    return (-1);
}

ssize_t ft_cutline(char **backup, char **line)
{
    char    *temp;
    ssize_t cut;
    ssize_t len;
    ssize_t i;

    if ((cut = ft_strline(*backup)) >= 0)
    {
        ft_strncpy(*backup, line, cut);
        ft_strncpy(*backup, &temp, ft_strlen(*backup));
        free(*backup);
        len = ft_strlen(temp);
        if (!(*backup = (char *)malloc(sizeof(char) * (len - cut))))
            return (0);
        i = 0;
        cut = cut + 1;
        while (temp[cut])
        {
            (*backup)[i] = temp[cut];
            i++;
            cut++;
        }
        (*backup)[i] = '\0';
        return (1);
    }
    return (0);
}

int get_next_line(int fd, char **line)
{
    char        buf[BUFFER_SIZE + 1];
    static char *backup;
    ssize_t     read_size;

    if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
        return (-1);
    while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
    {
        buf[read_size] = '\0';
        ft_strcat(buf, &backup);
        if (ft_cutline(&backup, line) > 0)
            return (1);
    }
    if (ft_cutline(&backup, line) > 0)
        return (1);
    ft_strncpy(backup, line, ft_strlen(backup));
    free(backup);
    backup = NULL;
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
		printf("result : %s\n", line);
		free(line);
	}
    printf("end : %s\n", line);
	free(line);
	close(fd);
	return (0);
}
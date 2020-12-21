/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:00:10 by jaehpark          #+#    #+#             */
/*   Updated: 2020/12/17 20:18:10 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 32

char	*ft_strcat(char *s1, char *s2)
{
	ssize_t len;
	ssize_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = 0;
	while (s2[len])
		len++;
	i = 0;
	while (s1[i])
	{
		s2[len] = s1[i];
		len++;
		i++;
	}
	s2[len] = '\0';
	return (s2);
}

void	ft_arrange(char **backup, char *buf, ssize_t read_size)
{
	char	*temp;
	ssize_t	len;
	ssize_t	i;

	if ((*backup) != NULL)
	{
		len = 0;
		while ((*backup)[len])
			len++;
		if (!(temp = (char *)malloc(sizeof(char) * (len + read_size + 1))))
			return ;
		i = 0;
		while ((*backup)[i])
		{
			temp[i] = (*backup)[i];
			i++;
		}
		temp[i] = '\0';
		free(*backup);
		temp = ft_strcat(buf, temp);
		if (!(*backup = (char *)malloc(sizeof(char) * (i + 1))))
			return ;
		i = 0;
		while (temp[i])
		{
			(*backup)[i] = temp[i];
			i++;
		}
		(*backup)[i] = 0;
	}
	else
	{
		if (!(*backup = (char *)malloc(sizeof(char) * (read_size + 1))))
			return ;
		i = 0;
		while (buf[i])
		{
			(*backup)[i] = buf[i];
			i++;
		}
		(*backup)[i] = '\0';
	}
}

ssize_t	ft_cutline(char **backup, char **line)
{
	ssize_t	cut;
	ssize_t	i;

	if (*backup == NULL)
		return (0);
	cut = 0;
	while ((*backup)[cut])
	{
		if ((*backup)[cut] == '\n')
			break;
		cut++;
	}
	if (!((*backup)[cut]))
		return (0);
	if (!(*line = (char *)malloc(sizeof(char) * (cut + 1))))
		return (0);
	i = 0;
	while (i < cut)
	{
		(*line)[i] = (*backup)[i];
		i++;
	}
	(*line)[i] = '\0';
	*backup = &(*backup)[cut + 1];
	return (cut);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*backup;
	ssize_t		read_size;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[BUFFER_SIZE] = '\0';
		ft_arrange(&backup, buf, read_size);
		if (ft_cutline(&backup, line) > 0)
			return (1);
	}
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
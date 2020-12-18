#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
	char	*line = 0;
	int 	ret;
	int		fd;
	
	fd = open("empty_lines", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("result = %s\n", line);
		free(line);
	}
	free(line);
	close(fd);
	return (0);

}

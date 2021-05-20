#include "cub3d.h"
#include "libft.h"
#include "mlx.h"

int		exit_success(t_set set)
{
	printf("Resolution : %d %d\n", set.win_x, set.win_y);
	printf("North texture path : %s\n", set.north);
	printf("South texture path : %s\n", set.south);
	printf("West texture path : %s\n", set.west);
	printf("East texture path : %s\n", set.east);
	printf("Sprite texture path : %s\n", set.sprite);
	printf("Floor RGB : %d %d %d\n", set.floor.r, set.floor.g, set.floor.b);
	printf("Ceilling RGB : %d %d %d\n", set.ceil.r, set.ceil.g, set.ceil.b);
	printf("EXIT SUCCESS\n");
	return (0);
}

void	exit_msg(const char *msg)
{
	printf("Error\n%s\n", msg);
	exit(0);
}

void    init_default(t_set *set)
{
    ft_memset(set, 0, sizeof(t_set));
    set->mlx = mlx_init();
}

void    free_array(char **arr)
{
    int     i;

    i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

int		check_extension(const char *s, const char *ext)
{
	int		i;
	int		j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i + j] == ext[j] && s[i] && ext[j])
			j++;
		if (s[i + j] == '\0' && ext[j] == '\0')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int		check_num(char *num)
{
	int		i;

	if (num[0] == '0' && num[1] != '\0')
		return (FALSE);
	i = 0;
	while (num[i])
	{
		if (num[i] < '0' || num[i] > '9')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	parse_resolution(t_set *set, char **data)
{
	int		count;
	int		x;
	int		y;

	count = 0;
	if (set->type[0] == 1)
		exit_msg("Duplicate resolution.");
	while (data[count])
		count++;
	if (count != 3)
		exit_msg("Invalid resolution.");
	if (check_num(data[1]) == FALSE || check_num(data[2]) == FALSE)
		exit_msg("Invalid resolution.");
	mlx_get_screen_size(set->mlx, &set->win_x, &set->win_y);
	x = ft_atoi(data[1]);
	y = ft_atoi(data[2]);
	if (x <= 0 || y <= 0)
		exit_msg("Invalid resolution.");
	if (x < set->win_x)
		set->win_x = x;
	if (y < set->win_y)
		set->win_y = y;
	set->type[0] = 1;
}

int		check_texture(t_set *set, char *type)
{
	if (type[0] == 'N' && set->type[1] == 1)
		exit_msg("Duplicate north texture.");
	else if (type[0] == 'N' && set->type[1] != 1)
		set->type[1] = 1;
	else if (type[0] == 'S' && type[1] == 'O' && set->type[2] == 1)
		exit_msg("Duplicate south texture");
	else if (type[0] == 'S' && type[1] == 'O' && set->type[2] != 1)
		set->type[2] = 1;
	else if (type[0] == 'W' && set->type[3] == 1)
		exit_msg("Duplicate west texture.");
	else if (type[0] == 'W' && set->type[3] != 1)
		set->type[3] = 1;
	else if (type[0] == 'E' && set->type[4] == 1)
		exit_msg("Duplicate east texture.");
	else if (type[0] == 'E' && set->type[4] != 1)
		set->type[4] = 1;
	else if (type[0] == 'S' && type[1] == '\0' && set->type[5] == 1)
		exit_msg("Duplicate sprite texture.");
	else if (type[0] == 'S' && type[1] == '\0' && set->type[5] != 1)
		set->type[5] = 1;
	return (TRUE);
}

void	parse_texture(t_set *set, char **data)
{
	int		count;

	count = 0;
	while (data[count])
		count++;
	if (count != 2)
		exit_msg("Invalid texture or sprite.");
	if (check_extension(data[1], ".xpm") == FALSE)
		exit_msg("Invalid texture extension.");
	if (data[0][0] == 'N' && check_texture(set, "N") == TRUE)
		set->north = ft_strdup(data[1]);
	else if (data[0][0] == 'S' && data[0][1] == 'O' && check_texture(set, "SO") == TRUE)
		set->south = ft_strdup(data[1]);
	else if (data[0][0] == 'W' && check_texture(set, "W") == TRUE)
		set->west = ft_strdup(data[1]);
	else if (data[0][0] == 'E' && check_texture(set, "E") == TRUE)
		set->east = ft_strdup(data[1]);
	else if (data[0][0] == 'S' && data[0][1] == '\0' && check_texture(set, "S") == TRUE)
		set->sprite = ft_strdup(data[1]);
}

int		check_rgb(const int rgb)
{
	if (rgb < 0 || rgb > 255)
		exit_msg("Invalid rgb.");
	return (1);
}

void	parse_rgb(t_set *set, char **rgb, const char type)
{
	int		temp[3];

	temp[0] = ft_atoi(rgb[0]);
	temp[1] = ft_atoi(rgb[1]);
	temp[2] = ft_atoi(rgb[2]);
	if (check_rgb(temp[0]) && check_rgb(temp[1]) && check_rgb(temp[2]))
	{
		if (type == 'F' && set->type[6] != 1)
		{
			set->floor.r = temp[0];
			set->floor.g = temp[1];
			set->floor.b = temp[2];
			set->type[6] = 1;
		}
		else if (type == 'C' && set->type[7] != 1)
		{
			set->ceil.r = temp[0];
			set->ceil.g = temp[1];
			set->ceil.b = temp[2];
			set->type[7] = 1;
		}
		else
			exit_msg("Duplitcate color of floor or ceilling.");
	}
}

void	parse_color(t_set *set, char **data)
{
	int		count;
	char	**rgb;

	count = 0;
	while (data[count])
		count++;
	rgb = NULL;
	if (count != 2 || (rgb = ft_split(data[1], ',')) == NULL)
		exit_msg("Invalid color of floor or ceilling.");
	count = 0;
	while (rgb[count])
		count++;
	if (count != 3)
		exit_msg("Invalid color of floor or ceilling.");
	if (check_num(rgb[0]) == FALSE || check_num(rgb[1]) == FALSE
				|| check_num(rgb[2]) == FALSE)
		exit_msg("Invalid color of floor or ceilling.");
	if (data[0][0] == 'F')
		parse_rgb(set, rgb, 'F');
	else if (data[0][0] == 'C')
		parse_rgb(set, rgb, 'C');
	free_array(rgb);
}

void	parse_type(t_set *set, char **data)
{
	if (data[0][0] == 'R' && data[0][1] == '\0')
		parse_resolution(set, data);
	else if (data[0][0] == 'N' && data[0][1] == 'O' && data[0][2] == '\0')
		parse_texture(set, data);
	else if (data[0][0] == 'S' && data[0][1] == 'O' && data[0][2] == '\0')
		parse_texture(set, data);
	else if (data[0][0] == 'W' && data[0][1] == 'E' && data[0][2] == '\0')
		parse_texture(set, data);
	else if (data[0][0] == 'E' && data[0][1] == 'A' && data[0][2] == '\0')
		parse_texture(set, data);
	else if (data[0][0] == 'S' && data[0][1] == '\0')
		parse_texture(set, data);
	else if (data[0][0] == 'F' && data[0][1] == '\0')
		parse_color(set, data);
	else if (data[0][0] == 'C' && data[0][1] == '\0')
		parse_color(set, data);
	else
		exit_msg("Invalid type.");
}

void	parse_types(t_set *set, const char *content)
{
	char	**data;

	if (content[0])
	{
		data = NULL;
		if ((data = ft_split(content, ' ')) == NULL)
			exit_msg("Invalid split.");
		if (data[0] == NULL)
			exit_msg("Invalid type.");
		parse_type(set, data);
		free_array(data);
	}
}

int		check_type(int *type)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		if (type[i] != 1)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	parse_map_line(t_set *set, char *content, t_list *map)
{
	if (content[0])
	{
		map = 
		exit_msg("Invalid map.");
		free_array(map);
	}
}

void	parse_map(t_set *set, int fd)
{
	char	*content;
	int		check;
	t_list	*map;

	contetn = NULL;
	map = NULL;
	while ((check = get_next_line(fd, &content)) >= 0)
	{

		free(content);
		if (check == 0)
			break;
	}
	if (check == -1)
		exit_msg("Invalid reading."); 
}

void	parse_content(t_set *set, int fd)
{
	char	*content;
	int		check;

	content = NULL;
	while ((check = get_next_line(fd, &content)) > 0)
	{
		parse_types(set, content);
		free(content);
		content = NULL;
		if (check_type(set->type) == TRUE)
			break;
	}
	if (check == 0 || check_type(set->type) == FALSE)
		exit_msg("Invalid content.");
	if (check == -1)
		exit_msg("Invalid reading.");
	parse_map(set, fd);
	if (close(fd) == FALSE)
		exit_msg("Invalid closing.");
}

int		main(int argc, char **argv)
{
	t_set	set;
	int		fd;
	
	if (argc < 2)
		exit_msg("Missing file.");
	if (check_extension(argv[1], ".cub") == FALSE)
		exit_msg("Invalid extension.");
	if ((fd = open(argv[1], O_RDONLY)) == FALSE)
		exit_msg("Invalid opening.");
	init_default(&set);
	parse_content(&set, fd);
	return (exit_success(set));
}
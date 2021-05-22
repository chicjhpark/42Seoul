/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 20:24:24 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/22 19:15:03 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

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

int		check_texture_path(t_set *set)
{
	if (set->north == NULL)
		exit_msg("Failed malloc.");
	if (set->south == NULL)
		exit_msg("Failed malloc.");
	if (set->west == NULL)
		exit_msg("Failed malloc.");
	if (set->east == NULL)
		exit_msg("Failed malloc.");
	if (set->sprite == NULL)
		exit_msg("Failed malloc.");
	return (TRUE);
}

void	parse_type(t_set *set, char **data)
{
	if (ft_strcmp(data[0], "R") == TRUE)
		parse_resolution(set, data);
	else if (ft_strcmp(data[0], "NO") == TRUE)
		parse_texture(set, data);
	else if (ft_strcmp(data[0], "SO") == TRUE)
		parse_texture(set, data);
	else if (ft_strcmp(data[0], "WE") == TRUE)
		parse_texture(set, data);
	else if (ft_strcmp(data[0], "EA") == TRUE)
		parse_texture(set, data);
	else if (ft_strcmp(data[0], "S") == TRUE)
		parse_texture(set, data);
	else if (ft_strcmp(data[0], "F") == TRUE)
		parse_color(set, data);
	else if (ft_strcmp(data[0], "C") == TRUE)
		parse_color(set, data);
	else
		exit_msg("Invalid type.");
}

void	parse_types(t_set *set, const char *content)
{
	char	**data;
	
	data = NULL;
	if ((data = ft_split(content, ' ')) == NULL)
		exit_msg("Invalid split.");
	if (data[0] == NULL)
		exit_msg("Invalid type.");
	parse_type(set, data);
	free_array(data);
}

void	parse_content(t_set *set, int fd)
{
	char	*content;
	int		check;

	content = NULL;
	while ((check = get_next_line(fd, &content)) > 0)
	{
		if (content[0])
			parse_types(set, content);
		free(content);
		content = NULL;
		if (check_type(set->type) == TRUE && check_texture_path(set) == TRUE)
			break;
	}
	if (check == 0 || check_type(set->type) == FALSE)
		exit_msg("Invalid content.");
	if (check == FALSE)
		exit_msg("Failed reading.");
	parse_map(set, fd);
	if (close(fd) == FALSE)
		exit_msg("Failed closing.");
}
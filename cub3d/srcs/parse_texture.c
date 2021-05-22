/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 20:24:20 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/22 19:14:57 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		check_texture(t_set *set, char *type)
{
	if (ft_strcmp(type, "NO") == TRUE && set->type[1] == 1)
		exit_msg("Duplicate north texture.");
	else if (ft_strcmp(type, "NO") == TRUE && set->type[1] != 1)
		set->type[1] = 1;
	else if (ft_strcmp(type, "SO") == TRUE && set->type[2] == 1)
		exit_msg("Duplicate south texture");
	else if (ft_strcmp(type, "SO") == TRUE && set->type[2] != 1)
		set->type[2] = 1;
	else if (ft_strcmp(type, "WE") == TRUE && set->type[3] == 1)
		exit_msg("Duplicate west texture.");
	else if (ft_strcmp(type, "WE") == TRUE && set->type[3] != 1)
		set->type[3] = 1;
	else if (ft_strcmp(type, "EA") == TRUE && set->type[4] == 1)
		exit_msg("Duplicate east texture.");
	else if (ft_strcmp(type, "EA") == TRUE && set->type[4] != 1)
		set->type[4] = 1;
	else if (ft_strcmp(type, "S") == TRUE && set->type[5] == 1)
		exit_msg("Duplicate sprite texture.");
	else if (ft_strcmp(type, "S") == TRUE && set->type[5] != 1)
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
	if (ft_strcmp(data[0], "NO") == TRUE && check_texture(set, "NO") == TRUE)
		set->north = ft_strdup(data[1]);
	else if (ft_strcmp(data[0], "SO") == TRUE && check_texture(set, "SO") == TRUE)
		set->south = ft_strdup(data[1]);
	else if (ft_strcmp(data[0], "WE") == TRUE && check_texture(set, "WE") == TRUE)
		set->west = ft_strdup(data[1]);
	else if (ft_strcmp(data[0], "EA") == TRUE && check_texture(set, "EA") == TRUE)
		set->east = ft_strdup(data[1]);
	else if (ft_strcmp(data[0], "S") == TRUE && check_texture(set, "S") == TRUE)
		set->sprite = ft_strdup(data[1]);
}
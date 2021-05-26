/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 20:40:39 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/25 16:45:49 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		check_valid_map(char **map, int x, int y)
{
	if (y != 0 && (int)ft_strlen(map[y - 1]) <= x)
		return (FALSE);
	else if (y != 0 && map[y - 1][x] == ' ')
		return (FALSE);
	else if (map[y][x + 1] && map[y][x + 1] == ' ')
		return (FALSE);
	else if ((int)ft_strlen(map[y + 1]) <= x)
		return (FALSE);
	else if (map[y + 1][x] == ' ')
		return (FALSE);
	else if (x != 0 && map[y][x - 1] == ' ')
		return (FALSE);
	return (TRUE);
}

void	check_position(t_set *set, int x, int y, char *pos)
{
	int		i;

	i = 0;
	while (pos[i])
	{
		if (set->map[y][x] == pos[i])
		{
			if (pos[i] == 'N')
				set->player.rot_ang = 270 * (M_PI / 180);
			else if (pos[i] == 'S')
				set->player.rot_ang = 90 * (M_PI / 180);
			else if (pos[i] == 'W')
				set->player.rot_ang = 180 * (M_PI / 180);
			else if (pos[i] == 'E')
				set->player.rot_ang = 0;
			set->player.x = x;
			set->player.y = y;
		}
		i++;
	}
}

void	check_sprite(t_set *set)
{
	int		x;
	int		y;
	int		i;

	if (!(set->sprites =
		(t_sprite *)malloc(sizeof(t_sprite) * (set->sprite_num))))
		exit_msg("Failed malloc.");
	y = 0;
	i = 0;
	while (set->map[y])
	{
		x = 0;
		while (set->map[y][x])
		{
			if (set->map[y][x] == '2')
			{
				set->sprites[i].x = x;
				set->sprites[i].y = y;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	check_map(t_set *set, char **map)
{
	int		y;
	int		x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (y == 0 && map[y][x] != '1' && map[y][x] != ' ')
				exit_msg("Invalid map.");
			else if (y == set->map_y - 1 &&
						map[y][x] != '1' && map[y][x] != ' ')
				exit_msg("Invalid map.");
			else if (map[y][x] != ' ' && map[y][x] != '1' &&
						check_valid_map(map, x, y) == FALSE)
				exit_msg("Invalid map.");
			check_position(set, x, y, "NSWE");
			x++;
		}
		y++;
	}
	check_sprite(set);
	if (!set->dir)
		exit_msg("Missing player position.");
}

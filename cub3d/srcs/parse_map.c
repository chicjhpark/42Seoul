/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 20:39:04 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/23 05:58:53 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		get_map_x(t_list *map)
{
	int		x;
	int		max_x;

	max_x = 0;
	while (map)
	{
		x = ft_strlen((char *)map->content);
		if (x > max_x)
			max_x = x;
		map = map->next;
	}
	return (max_x);
}

int		check_dir(t_set *set, char map_x, char *dir)
{
	int		i;

	i = 0;
	while (dir[i])
	{
		if (map_x == dir[i])
		{
			if (set->dir)
				return (FALSE);
			else
			{
				set->dir = map_x;
				return (TRUE);
			}
		}
		i++;
	}
	return (TRUE);
}

void	check_content(t_set *set, char *content, char *form)
{
	int		i;
	int		j;

	if (content[0] != '1' && content[0] != ' ')
		exit_msg("Invalid map content.");
	i = 0;
	while (content[i])
	{
		j = 0;
		while (form[j])
		{
			if (content[i] == form[j])
			{
				if (check_dir(set, content[i], "NSEW") == FALSE)
					exit_msg("Duplicate player dir.");
				break;
			}
			j++;
		}
		if (!form[j])
			exit_msg("Invalid map content.");
		i++;
	}
	if (content[i - 1] != '1' && content[i - 1] != ' ')
		exit_msg("Invalid map content.");
}

void	copy_map(t_set *set, t_list *map)
{
	int		x;
	int		y;

	set->map_y = ft_lstsize(map);
	if (!(set->map = (char **)malloc(sizeof(char *) * (set->map_y + 1))))
		exit_msg("Failed malloc.");
	set->map_x = get_map_x(map);
	y = 0;
	while (y < set->map_y && map)
	{
		if (!(set->map[y] = (char *)malloc(sizeof(char) * (set->map_x + 1))))
			exit_msg("Failed malloc.");
		x = 0;
		while (x < set->map_x && (map->content)[x])
		{
			set->map[y][x] = (map->content)[x];
			x++;
		}
		set->map[y][x] = '\0';
		map = map->next;
		y++;
	}
	set->map[y] = NULL;
}

void	parse_map(t_set *set, int fd)
{
	char	*content;
	int		check;
	t_list	*map;

	content = NULL;
	map = NULL;
	while ((check = get_next_line(fd, &content)) >= 0)
	{
		if (content[0])
		{
			check_content(set, content, " 012NSEW");
			ft_lstadd_back(&map, ft_lstnew(content));
		}
		if (check == 0)
			break;
	}
	if (check == -1)
		exit_msg("Failed reading.");
	copy_map(set, map);
	ft_lstclear(&map, 0);
	check_map(set, set->map);
}
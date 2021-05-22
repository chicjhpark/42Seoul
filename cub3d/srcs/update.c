/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:16:58 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/22 23:23:44 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update.h"

void	update_player(t_set *set, t_player *player)
{
	int		move;
	float	new_x;
	float	new_y;

	player->rot_ang += player->rot_dir * player->rot_spd;
	if (player->move_side == 1 || player->move_side == -1)
	{
		move = player->move_side * player->move_spd;
		new_x = player->x - sin(player->rot_ang) * move;
		new_y = player->y + cos(player->rot_ang) * move;
	}
	else
	{
		move = player->move_dir * player->move_spd;
		new_x = player->x + cos(player->rot_ang) * move;
		new_y = player->y + sin(player->rot_ang) * move;
	}
	if (check_collision(set, new_x, new_y) == FALSE)
	{
		player->x = new_x;
		player->y = new_y;
	}
}

void	update_ray(t_set *set, t_player *player, t_ray *ray, float ang, int i)
{
	ang = normalize_ang(ang);
	init_data(&ray->data, ang);
	init_horiz_data(player, &ray->data, ang);
	horiz_intersection(set, &ray->data);
	init_vert_data(player, &ray->data, ang);
	vert_intersection(set, &ray->data);
	select_closest_distance(player, ray, &ray->data, ang, i);
}

void	update_rays(t_set *set, t_player *player, t_ray *ray)
{
	float	ang;
	int		i;

	ang = player->rot_ang - (FOV / 2);
	i = 0;
	while (i < set->rays)
	{
		update_ray(set, player, ray, ang, i);
		ang += FOV / (set->rays - 1);
		i++;
	}
}

void	update(t_set *set)
{
	update_player(set, &set->player);
	update_rays(set, &set->player, set->ray);
}
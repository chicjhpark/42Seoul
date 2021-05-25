/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:38:12 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/26 05:09:35 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	check_visible_sprite(t_set *set, t_player *player, t_sprite *sprite)
{
	int		i;
	float	ang;
	float	epsilon;

	i = -1;
	epsilon = 0.2;
	while (++i < set->sprite_num)
	{
		ang = player->rot_ang -
				atan2(sprite[i].y - player->y, sprite[i].x - player->x);
		if (ang > M_PI)
			ang -= M_PI * 2;
		if (ang < -M_PI)
			ang += M_PI * 2;
		ang = fabs(ang);
		if (ang < (set->fov / 2) + epsilon)
		{
			sprite[i].visible = 1;
			sprite[i].ang = ang;
			sprite[i].distance = distance_between_point(sprite[i].x,
								sprite[i].y, player->x, player->y);
		}
		else
			sprite[i].visible = 0;
	}
}

void	relocate_sprite(t_set *set, t_sprite *sprite)
{
	int			i;
	int			j;
	t_sprite	temp;

	i = 0;
	while (i < set->sprite_num)
	{
		j = i + 1;
		while (j < set->sprite_num)
		{
			if (sprite[i].distance < sprite[j].distance)
			{
				temp = sprite[i];
				sprite[i] = sprite[j];
				sprite[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	init_sprite(t_set *set, t_player *player, t_sprite *sprite, int i)
{
	sprite[i].perp = sprite[i].distance * cos(sprite[i].ang);
	sprite[i].height =
		(GRID_SIZE / sprite[i].perp) * ((set->win_x / 2) / tan(set->fov / 2));
	sprite[i].width = sprite[i].height;
	sprite[i].top = (set->win_y / 2) - (sprite[i].height / 2);
	sprite[i].top = (sprite[i].top < 0) ? 0 : sprite[i].top;
	sprite[i].bot = (set->win_y / 2) + (sprite[i].height / 2);
	sprite[i].bot = (sprite[i].bot > set->win_y) ? set->win_y : sprite[i].bot;
	sprite[i].ang = atan2(sprite[i].y - player->y,
							sprite[i].x - player->x) - player->rot_ang;
	sprite[i].pos = tan(sprite[i].ang) * ((set->win_x / 2) / tan(set->fov / 2));
	sprite[i].left = (set->win_x / 2) + sprite[i].pos - (sprite[i].width / 2);
	sprite[i].right = sprite[i].left + sprite[i].width;
	sprite[i].texel_width = (set->tex_size[4].x / sprite[i].width);
}

void	render_sprite(t_set *set, t_sprite *sprite, int x, int i)
{
	int		y;
	int		tex_x;
	int		tex_y;
	int		dist_top;
	int		color;

	tex_x = (x - sprite[i].left) * sprite[i].texel_width;
	y = sprite[i].top;
	while (y < sprite[i].bot)
	{
		if (x > 0 && x < set->win_x && y > 0 && y < set->win_y)
		{
			dist_top = y + (sprite[i].height / 2) - (set->win_y / 2);
			tex_y = dist_top * (set->tex_size[4].y / sprite[i].height);
			color = set->tex[4][set->tex_size[4].x * tex_y + tex_x];
			if (sprite[i].distance < set->ray[x].distance && color != 0x000000)
				set->img.data[set->win_x * y + x] = color;
		}
		y++;
	}
}

void	render_sprites(t_set *set, t_player *player, t_sprite *sprite)
{
	int		i;
	int		x;

	check_visible_sprite(set, player, sprite);
	relocate_sprite(set, sprite);
	i = 0;
	while (i < set->sprite_num)
	{
		if (sprite[i].visible == 1)
		{
			init_sprite(set, player, sprite, i);
			x = sprite[i].left;
			while (x < sprite[i].right)
			{
				render_sprite(set, sprite, x, i);
				x++;
			}
		}
		i++;
	}
}

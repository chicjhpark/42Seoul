# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    temp2                                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/24 23:23:36 by jaehpark          #+#    #+#              #
#    Updated: 2021/05/25 15:38:23 by jaehpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#include "render.h"

void	render_sprites(t_set *set, t_player *player, t_ray *ray, t_sprite *sprite)
{
	int		i;
	int		j;

	i = 0;
	while (i < set->sprite_num)
	{
		float	ang;

		ang = player->rot_ang - atan2(sprite[i].y - player->y, sprite[i].x - player->x);
		if (ang > M_PI)
			ang -= M_PI * 2;
		if (ang < -M_PI)
			ang += M_PI * 2;
		ang = fabs(ang);
		if (ang < set->fov / 2)
		{
			sprite[i].visible = 1;
			sprite[i].ang = ang;
			sprite[i].distance = distance_between_point(sprite[i].x, sprite[i].y, player->x, player->y);
		}
		else
			sprite[i].visible = 0;
		i++;
	}

	i = 0;
	while (i < set->sprite_num)
	{
		j = i + 1;
		while (j < set->sprite_num)
		{
			if (sprite[i].distance < sprite[j].distance)
			{
				t_sprite	temp;

				temp = sprite[i];
				sprite[i] = sprite[j];
				sprite[j] = temp;
			}
			j++;
		}
		i++;
	}
	
	i = 0;
	while (i < set->sprite_num)
	{
		float	height;
		float	width;
		float	top;
		float	bot;
		float	ang;
		float	pos;
		float	left;
		float	right;
		int		x;
		int		y;
		int		color;
		float	perp;

		if (sprite[i].visible == 1)
		{
			perp = sprite[i].distance * cos(sprite[i].ang);
			height = (GRID_SIZE / perp) * ((set->win_x / 2) / tan(set->fov / 2));
			width = height;
			top = (set->win_y / 2) - (height / 2);
			top = (top < 0) ? 0 : top;
			bot = (set->win_y / 2) + (height / 2);
			bot = (bot > set->win_y) ? set->win_y : bot;
			ang = atan2(sprite[i].y - player->y, sprite[i].x - player->x) - player->rot_ang;
			pos = tan(ang) * ((set->win_x / 2) / tan(set->fov / 2));
			left = (set->win_x / 2) + pos - (width / 2);
			right = left + width;
			x = left;
			while (x < right)
			{
				float	texel_width;
				int		tex_x;

				texel_width = (TEX_WIDTH / width);
				tex_x = (x - left) * texel_width;
				y = top;
				while (y < bot)
				{
					if (x > 0 && x < set->win_x && y > 0 && y < set->win_y)
					{
						int		dist_top;
						int		tex_y;

						dist_top = y + (height / 2) - (set->win_y / 2);
						tex_y = dist_top * (TEX_HEIGHT / height);
						color = set->tex[4][TEX_WIDTH * tex_y + tex_x];
						if (sprite[i].distance < ray[x].distance && color != 0x000000)
							set->img.data[set->win_x * y + x] = color;
					}
					y++;
				}
				x++;
			}
		}
		i++;
	}
}
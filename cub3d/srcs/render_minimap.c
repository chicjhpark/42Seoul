/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:31:10 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/26 22:46:13 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_grid(t_set *set, int x1, int y1, int color)
{
	int		x2;
	int		y2;

	y2 = 0;
	while (y2 < MINIMAP * set->tex_size[0].y)
	{
		x2 = 0;
		while (x2 < MINIMAP * set->tex_size[0].x)
		{
			if (y2 == 0 || x2 == 0 || y2 == MINIMAP * set->tex_size[0].y
				- MINIMAP || x2 == MINIMAP * set->tex_size[0].x - MINIMAP)
				set->img.data[set->win_x * (y1 + y2) + x1 + x2] = LINE_COLOR;
			else
				set->img.data[set->win_x * (y1 + y2) + x1 + x2] = color;
			x2++;
		}
		y2++;
	}
}

void	render_map(t_set *set)
{
	int		x;
	int		y;

	y = 0;
	while (set->map[y])
	{
		x = 0;
		while (set->map[y][x])
		{
			if (set->map[y][x] == '1')
				render_grid(set, MINIMAP * set->tex_size[0].x * x,
							MINIMAP * set->tex_size[0].y * y, BLOCK_COLOR);
			else if (set->map[y][x] != ' ')
				render_grid(set, MINIMAP * set->tex_size[0].x * x,
							MINIMAP * set->tex_size[0].y * y, GRID_COLOR);
			x++;
		}
		y++;
	}
}

void	render_player_line(t_img *img, t_player *player)
{
	int		x;
	int		y;
	int		len;

	len = 0;
	while (len < 40)
	{
		x = MINIMAP * (player->x + cos(player->rot_ang) * len);
		y = MINIMAP * (player->y + sin(player->rot_ang) * len);
		img->data[img->x * y + x] = PLAYER_COLOR;
		len++;
	}
}

void	render_player(t_img *img, t_player *player)
{
	int		x;
	int		y;
	int		size;
	int		ang;

	ang = 0;
	while (ang < 360)
	{
		size = 0;
		while (size < player->size)
		{
			x = MINIMAP * (player->x + cos(ang * (M_PI / 180)) * size);
			y = MINIMAP * (player->y + sin(ang * (M_PI / 180)) * size);
			img->data[img->x * y + x] = PLAYER_COLOR;
			size++;
		}
		ang++;
	}
	render_player_line(img, player);
}

void	render_map_sprites(t_set *set, t_img *img, t_sprite *sprites)
{
	int		i;
	int		x;
	int		y;
	int		ang;
	int		size;

	i = -1;
	while (++i < set->sprite_num)
	{
		ang = -1;
		while (++ang < 360)
		{
			size = 0;
			while (size < set->player.size * 3)
			{
				x = MINIMAP * (sprites[i].x + cos(ang * (M_PI / 180)) * size);
				y = MINIMAP * (sprites[i].y + sin(ang * (M_PI / 180)) * size);
				if (sprites[i].visible)
					img->data[set->win_x * y + x] = YELLOW;
				else
					img->data[set->win_x * y + x] = DARK_YELLOW;
				size++;
			}
		}
	}
}

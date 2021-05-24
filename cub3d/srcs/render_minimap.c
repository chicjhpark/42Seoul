/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:31:10 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/24 22:24:34 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "color.h"
#include "init.h"

void	render_grid(t_set *set, int x1, int y1, int color)
{
	int		x2;
	int		y2;

	y2 = 0;
	while (y2 < MINIMAP * GRID_SIZE)
	{
		x2 = 0;
		while (x2 < MINIMAP * GRID_SIZE)
		{
			if (y2 == 0 || x2 == 0 || y2 == MINIMAP * GRID_SIZE - MINIMAP || x2 == MINIMAP * GRID_SIZE - MINIMAP)
				set->img.data[set->win_x * (y1 + y2) + x1 + x2] = GRID_LINE_COLOR;
			else
				set->img.data[set->win_x * (y1 + y2) + x1 + x2] = color;
			x2++;
		}
		y2++;
	}
}

void	render_map(t_set *set) // 맵을 그린다.
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
				render_grid(set, MINIMAP * GRID_SIZE * x, MINIMAP * GRID_SIZE * y, BLOCK_COLOR);
			else if (set->map[y][x] != ' ')
				render_grid(set, MINIMAP * GRID_SIZE * x, MINIMAP * GRID_SIZE * y, GRID_COLOR);
			x++;
		}
		y++;
	}
}

void	render_player_line(t_img *img, t_player *player) // 플레이어의 시야 방향을 나타내는 줄 하나를 그린다.
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

void	render_player(t_img *img, t_player *player) // 플레이어를 그린다.
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

void	render_map_sprite(t_set *set, t_img *img, t_sprite *sprite_tex)
{
	int		i;
	int		x;
	int		y;
	int		ang;
	int		size;

	i = 0;
	while (i < set->sprite_num)
	{
		ang = 0;
		while (ang < 360)
		{
			size = 0;
			while (size < set->player.size * 3)
			{
				x = MINIMAP * (sprite_tex[i].x + cos(ang * (M_PI / 180)) * size);
				y = MINIMAP * (sprite_tex[i].y + sin(ang * (M_PI / 180)) * size);
				img->data[set->win_x * y + x] = sprite_tex[i].visible ? YELLOW : DARK_YELLOW;
				size++;
			}
			ang++;
		}
		i++;
	}
}
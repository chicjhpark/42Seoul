/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:40:13 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/24 17:35:27 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

u_int	replace_color(t_color color)
{
	return (color.r * 256 * 256 + color.g * 256 + color.b);
}

void	render_wall(t_set *set, t_img *img, t_player player, t_ray *ray)
{
	int		i;

	i = 0;
	while (i < img->x)
	{
		float	vert_dist;
		float	wall_height;
		int		top;
		int		bot;
		int		y;
		int		tex_x;
		int		num;

		vert_dist = ray[i].distance * cos(ray[i].ang - player.rot_ang);
		wall_height = (GRID_SIZE / vert_dist) * ((img->x / 2) / (tan(FOV) / 2));
		top = (img->y / 2) - (wall_height / 2);
		top = top < 0 ? 0 : top;
		bot = (img->y / 2) + (wall_height / 2);
		bot = bot > img->y ? img->y : bot;
		y = -1;
		while (++y < top)
			img->data[(img->x * y) + i] = replace_color(set->ceil);
		if (ray[i].hit_vert)
		{
			tex_x = (int)ray[i].hit_y % TEX_HEIGHT;
			if (ray[i].left)
			{
				num = 3;
			}
			else
				num = 2;
		}
		else
		{
			tex_x = (int)ray[i].hit_x % TEX_WIDTH;
			if (ray[i].up)
				num = 0;
			else
			{
				num = 1;
			}
		}
		while (++y < bot)
		{
			int		distance_top;
			int		tex_y;
			int		wall_color;

			distance_top = y + (wall_height / 2) - (img->y / 2); // ?
			tex_y = distance_top * ((float)TEX_HEIGHT / wall_height);
			wall_color = set->tex[num][(TEX_WIDTH * tex_y) + tex_x];
			img->data[(img->x * y) + i] = wall_color;
		}
		while (++y < img->y)
			img->data[(img->x * y) + i] = replace_color(set->floor);
		i++;
	}
}
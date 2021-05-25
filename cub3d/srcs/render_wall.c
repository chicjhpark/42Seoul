/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:40:13 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/26 05:09:39 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int		replace_color(t_color color)
{
	return (color.r * 256 * 256 + color.g * 256 + color.b);
}

void	update_wall(t_set *set, t_ray *ray, t_wall *wall, int i)
{
	wall->vert_dist = ray[i].distance * cos(ray[i].ang - set->player.rot_ang);
	wall->height = (GRID_SIZE / wall->vert_dist) *
					((set->win_x / 2) / tan(set->fov / 2));
	wall->top = (set->win_y / 2) - (wall->height / 2);
	wall->top = wall->top < 0 ? 0 : wall->top;
	wall->bot = (set->win_y / 2) + (wall->height / 2);
	wall->bot = wall->bot > set->win_y ? set->win_y : wall->bot;
	if (set->ray[i].hit_vert)
	{
		wall->tex_x = (int)set->ray[i].hit_y % set->tex_size[wall->num].y;
		wall->tex_x = set->ray[i].left ?
						-wall->tex_x + set->tex_size[wall->num].x - 1 : wall->tex_x;
		wall->num = set->ray[i].left ? 3 : 2;
	}
	else
	{
		wall->tex_x = (int)set->ray[i].hit_x % set->tex_size[wall->num].x;
		wall->tex_x = set->ray[i].up ?
						wall->tex_x : -wall->tex_x + set->tex_size[wall->num].x - 1;
		wall->num = set->ray[i].up ? 0 : 1;
	}
}

void	render_wall(t_set *set, t_img *img, t_ray *ray)
{
	int		i;
	int		y;
	int		color;
	int		dist_top;
	int		tex_y;

	i = -1;
	while (++i < img->x)
	{
		update_wall(set, ray, &set->wall, i);
		y = -1;
		while (++y < set->wall.top)
			img->data[(img->x * y) + i] = replace_color(set->ceil);
		while (++y < set->wall.bot)
		{
			dist_top = y + (set->wall.height / 2) - (set->win_y / 2);
			tex_y = dist_top * ((float)set->tex_size[set->wall.num].y / set->wall.height);
			color = set->tex[set->wall.num]
							[(set->tex_size[set->wall.num].x * tex_y) + set->wall.tex_x];
			set->img.data[(set->win_x * y) + i] = color;
		}
		while (++y < img->y)
			img->data[(img->x * y) + i] = replace_color(set->floor);
	}
}

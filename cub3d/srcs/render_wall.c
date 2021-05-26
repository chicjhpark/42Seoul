/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:40:13 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/26 20:36:42 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		replace_color(t_color color)
{
	return (color.r * 256 * 256 + color.g * 256 + color.b);
}

void	update_wall(t_set *set, t_ray *ray, t_wall *wall, int x)
{
	wall->vert_dist = ray[x].distance * cos(ray[x].ang - set->player.rot_ang);
	wall->height = (set->tex_size[0].y / wall->vert_dist) *
					((set->win_x / 2) / tan(set->fov / 2));
	wall->top = (set->win_y / 2) - (wall->height / 2);
	wall->top = wall->top < 0 ? 0 : wall->top;
	wall->bot = (set->win_y / 2) + (wall->height / 2);
	wall->bot = wall->bot > set->win_y ? set->win_y : wall->bot;
	if (set->ray[x].hit_vert)
	{
		wall->tex_x = (int)set->ray[x].hit_y % set->tex_size[wall->num].y;
		wall->tex_x = set->ray[x].left ?
				-wall->tex_x + set->tex_size[wall->num].x - 1 : wall->tex_x;
		wall->num = set->ray[x].left ? 3 : 2;
	}
	else
	{
		wall->tex_x = (int)set->ray[x].hit_x % set->tex_size[wall->num].x;
		wall->tex_x = set->ray[x].up ?
				wall->tex_x : -wall->tex_x + set->tex_size[wall->num].y - 1;
		wall->num = set->ray[x].up ? 0 : 1;
	}
}

void	render_wall_bot(t_set *set, t_wall *wall, int x, int y)
{
	int		color;
	int		dist_top;
	int		tex_y;

	dist_top = y + (wall->height / 2) - (set->win_y / 2);
	tex_y = dist_top * ((float)set->tex_size[wall->num].y / wall->height);
	color = set->tex[wall->num]
			[(set->tex_size[wall->num].x * tex_y) + wall->tex_x];
	set->img.data[(set->win_x * y) + x] = color;
}

void	render_wall(t_set *set, t_img *img, t_ray *ray, t_wall *wall)
{
	int		x;
	int		y;

	x = 0;
	while (x < img->x)
	{
		update_wall(set, ray, wall, x);
		y = 0;
		while (y < wall->top)
		{
			img->data[(img->x * y) + x] = replace_color(set->ceil);
			y++;
		}
		while (y < wall->bot)
		{
			render_wall_bot(set, wall, x, y);
			y++;
		}
		while (y < img->y)
		{
			img->data[(img->x * y) + x] = replace_color(set->floor);
			y++;
		}
		x++;
	}
}

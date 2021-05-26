/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 19:15:13 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/25 17:30:50 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int		check_collision(t_set *set, float x, float y)
{
	int		map_x;
	int		map_y;

	if (x < 0 || x >= set->map_x * set->tex_size[0].x ||
		y < 0 || y >= set->map_y * set->tex_size[0].y)
		return (TRUE);
	map_x = floor(x / set->tex_size[0].x);
	map_y = floor(y / set->tex_size[0].y);
	if (set->map[map_y][map_x] == '1')
		return (TRUE);
	return (FALSE);
}

float	normalize_ang(float ang)
{
	ang = remainder(ang, M_PI * 2);
	if (ang < 0)
		ang += M_PI * 2;
	return (ang);
}

float	distance_between_point(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	init_data(t_data *data, float ang)
{
	data->down = ang > 0 && ang < M_PI;
	data->up = !data->down;
	data->right = ang < 0.5 * M_PI || ang > 1.5 * M_PI;
	data->left = !data->right;
	data->h_hit = 0;
	data->h_hit_x = 0;
	data->h_hit_y = 0;
	data->h_content = 0;
	data->v_hit = 0;
	data->v_hit_x = 0;
	data->v_hit_y = 0;
	data->v_content = 0;
}

void	render_ray(t_set *set, t_img *img, t_player *player, t_ray *ray)
{
	int		x;
	int		y;
	int		i;
	int		j;

	i = 0;
	while (i < set->rays)
	{
		j = 0;
		while (j <= ray[i].distance)
		{
			x = MINIMAP * (player->x + cos(ray[i].ang) * j);
			y = MINIMAP * (player->y + sin(ray[i].ang) * j);
			img->data[img->x * y + x] = RAY_COLOR;
			j++;
		}
		i++;
	}
}

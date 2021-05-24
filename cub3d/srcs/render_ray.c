/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 19:15:13 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/24 05:45:56 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int		check_collision(t_set *set, float x, float y) // 벽과 충돌했는지 검사한다. 충돌시에는 참(0)을 반환한다.
{
	int		map_x;
	int		map_y;
	
	if (x < 0 || x >= set->map_x * GRID_SIZE || y < 0 || y >= set->map_y * GRID_SIZE)
		return TRUE;
	map_x = floor(x / GRID_SIZE);
	map_y = floor(y / GRID_SIZE);
	if (set->map[map_y][map_x] == '1')
		return TRUE;
	return FALSE;
}

float	normalize_ang(float ang) // 시야의 각도가 0도보다 작거나 360도보다 클 때 각도를 초기화시킨다.
{
	ang = remainder(ang, M_PI * 2);
	if (ang < 0)
		ang += M_PI * 2;
	return (ang);
}

float	distance_between_point(float x1, float y1, float x2, float y2) // 플레이어의 좌표와 벽이나 물체에 충돌한 지점의 거리를 계산한다.
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	init_data(t_data *data, float ang)
{
	data->down = ang > 0 && ang < M_PI; // 0도 ~ 180도는 컴퓨터 좌표상에서는 180도 ~ 360도로 적용되므로 아래를 보고 있는 것이다.
	data->up = !data->down;
	data->right = ang < 0.5 * M_PI || ang > 1.5 * M_PI; // 90도 보다 작거나 270보다 크면 오른쪽을 보고 있는 것이디.
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

void	render_ray(t_set *set, t_img *img, t_player *player, t_ray *ray) // 광선들을 그린다.
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
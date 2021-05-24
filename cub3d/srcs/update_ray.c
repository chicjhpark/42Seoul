/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 05:44:19 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/24 05:45:46 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	init_horiz_data(t_player *player, t_data *data, float ang)
{
	data->y_block = floor(player->y / GRID_SIZE) * GRID_SIZE; // 플레이어의 y좌표 위치를 수평교차로에 맞춘 것이다.
	data->y_block += data->down ? GRID_SIZE : 0; // 플레이어가 아래쪽을 보고 있으면 수평교차로 지점을 한칸 내려서 맞춘다.
	data->x_block = player->x + (data->y_block - player->y) / tan(ang); // 플레이어의 x좌표 위치를 수평교차로에 맞춘 것이다.
	data->y_step = GRID_SIZE; // 수평 교차로를 만나게 되는 y의 폭이다.
	data->y_step *= data->up ? -1 : 1; // 위를 보고 있다면 -1을 곱해준다. 이유는 컴퓨터상의 좌표에서는 위쪽으로 갈수록 값이 작아지기 때문이다.
	data->x_step = GRID_SIZE / tan(ang); // 수평 교차로를 만나게 되는 x의 폭이다.
	data->x_step *= (data->left && data->x_step > 0) ? -1 : 1; // 왼쪽을 보고 있으면 -가 되야하는데 x의 폭이 양수이기 떄문에 음수로 만들어준다.
	data->x_step *= (data->right && data->x_step < 0) ? -1 : 1; // 오른쪽을 보고 있으면 +가 되야하는데 x의 폭이 음수이기 때문에 양수로 만들어준다.
	data->h_touch_x = data->x_block;
	data->h_touch_y = data->y_block;
}

void	horiz_intersection(t_set *set, t_data *data)
{
	while (data->h_touch_x >= 0 && data->h_touch_x <= set->map_x * GRID_SIZE && data->h_touch_y > 0 && data->h_touch_y < set->map_y * GRID_SIZE)
	{
		float	x_check;
		float	y_check;

		x_check = data->h_touch_x;
		y_check = data->h_touch_y + (data->up ? -1 : 0);

		if (check_collision(set, x_check, y_check) == TRUE)
		{
			data->h_hit_x = data->h_touch_x;
			data->h_hit_y = data->h_touch_y;
			data->h_content = set->map[(int)floor(y_check / GRID_SIZE)][(int)floor(x_check / GRID_SIZE)];
			data->h_hit = 1;
			break;
		}
		else
		{
			data->h_touch_x += data->x_step;
			data->h_touch_y += data->y_step;
		}
	}
}

void	init_vert_data(t_player *player, t_data *data, float ang)
{
	data->x_block = floor((player->x) / GRID_SIZE) * GRID_SIZE;
	data->x_block += data->right ? GRID_SIZE : 0;
	data->y_block = player->y + (data->x_block - player->x) * tan(ang);
	data->x_step = GRID_SIZE;
	data->x_step *= data->left ? -1 : 1;
	data->y_step = GRID_SIZE * tan(ang);
	data->y_step *= (data->up && data->y_step > 0) ? -1 : 1;
	data->y_step *= (data->down && data->y_step < 0) ? -1 : 1;
	data->v_touch_x = data->x_block;
	data->v_touch_y = data->y_block;
}

void	vert_intersection(t_set *set, t_data *data)
{
	while (data->v_touch_x > 0 && data->v_touch_x <= set->map_x * GRID_SIZE && data->v_touch_y >= 0 && data->v_touch_y <= set->map_y * GRID_SIZE)
	{
		float	x_check;
		float	y_check;

		x_check = data->v_touch_x + (data->left ? -1 : 0);
		y_check = data->v_touch_y;

		if (check_collision(set, x_check, y_check) == TRUE)
		{
			data->v_hit_x = data->v_touch_x;
			data->v_hit_y = data->v_touch_y;
			data->v_content = set->map[(int)floor(y_check / GRID_SIZE)][(int)floor(x_check / GRID_SIZE)];
			data->v_hit = 1;
			break;
		}
		else
		{
			data->v_touch_x += data->x_step;
			data->v_touch_y += data->y_step;
		}
	}
}

void	select_closest_distance(t_player *player, t_ray *ray, t_data *data, float ang, int i)
{
	data->h_distance = data->h_hit ? distance_between_point(player->x, player->y, data->h_hit_x, data->h_hit_y) : FLT_MAX;
	data->v_distance = data->v_hit ? distance_between_point(player->x, player->y, data->v_hit_x, data->v_hit_y) : FLT_MAX;
	if (data->v_distance < data->h_distance)
	{
		ray[i].distance = data->v_distance;
		ray[i].hit_x = data->v_hit_x;
		ray[i].hit_y = data->v_hit_y;
		ray[i].hit_content = data->v_content;
		ray[i].hit_vert = 1;
	}
	else
	{
		ray[i].distance = data->h_distance;
		ray[i].hit_x = data->h_hit_x;
		ray[i].hit_y = data->h_hit_y;
		ray[i].hit_content = data->h_content;
		ray[i].hit_vert = 0;
	}
	ray[i].ang = ang;
	ray[i].down = data->down;
	ray[i].up = data->up;
	ray[i].left = data->left;
	ray[i].right = data->right;
}
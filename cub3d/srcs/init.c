/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 23:07:19 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/23 04:54:29 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "color.h"

void    init_default(t_set *set)
{
    ft_memset(set, 0, sizeof(t_set));
    set->mlx = mlx_init();
}

void	init_win(t_set *set)
{
	set->mlx = mlx_init();
	set->win = mlx_new_window(set->mlx, set->win_x, set->win_y, "Cub3D");
}

void	init_img(t_set *set, t_img *img)
{
	img->x = set->win_x;
	img->y = set->win_y;
	img->img = mlx_new_image(set->mlx, img->x, img->y);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
}

void	init_player(t_player *player)
{
	player->x = (0.5 + player->x) * GRID_SIZE;
	player->y = (0.5 + player->y) * GRID_SIZE;
	player->size = MINIMAP * 32;
	player->rot_dir = 0;
	player->move_dir = 0;
	player->move_spd = 3;
	player->rot_spd = 3 * (M_PI / 180);
}

void		init_ray(t_set *set, t_ray **ray)
{
	*ray = NULL;
    set->rays = set->win_x;
	if (!(*ray = (t_ray *)malloc(sizeof(t_ray) * set->rays)))
		exit_msg("Failed malloc.");
}

void	init_tex(int **wall_tex)
{
	int		x;
	int		y;

	*wall_tex = NULL;
	if (!(*wall_tex = (int *)malloc(sizeof(int) * TEX_WIDTH * TEX_HEIGHT)))
		exit_msg("Failed malloc.");
	x = 0;
	while (x < TEX_WIDTH)
	{
		y = 0;
		while (y < TEX_HEIGHT)
		{
			(*wall_tex)[TEX_WIDTH * y + x] = (x % 16 && y % 16) ? RED : BLACK;
			y++;
		}
		x++;
	}
}

void	init_set(t_set *set)
{
	init_win(set);
	init_img(set, &set->img);
	init_player(&set->player);
	init_ray(set, &set->ray);
	init_tex(&set->wall_tex);
}
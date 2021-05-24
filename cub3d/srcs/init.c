/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 23:07:19 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/24 22:38:14 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "color.h"

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

void	init_wall_tex(int **tex)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	while (i < 5)
	{
		tex[i] = NULL;
		if (!(tex[i] = (int *)malloc(sizeof(int) * TEX_WIDTH * TEX_HEIGHT)))
			exit_msg("Failed malloc.");
		x = 0;
		while (x < TEX_WIDTH)
		{
			y = 0;
			while (y < TEX_HEIGHT)
			{
				tex[i][TEX_WIDTH * y + x] = (x % 16 && y % 16) ? RED : BLACK;
				y++;
			}
			x++;
		}
		i++;
	}
}

void	check_texture_file(t_set *set)
{
	int		fd;
	
	if ((fd = open(set->north, O_RDONLY)) == -1)
		exit_msg("Failed open texture.");
	close(fd);
	if ((fd = open(set->south, O_RDONLY)) == -1)
		exit_msg("Failed open texture.");
	close(fd);
	if ((fd = open(set->east, O_RDONLY)) == -1)
		exit_msg("Failed open texture.");
	close(fd);
	if ((fd = open(set->west, O_RDONLY)) == -1)
		exit_msg("Failed open texture.");
	close(fd);
	if ((fd = open(set->sprite, O_RDONLY)) == -1)
		exit_msg("Failed open texture.");
	close(fd);
}

void	get_texture(t_set *set, t_img *img, int *tex, char *path)
{
	int		x;
	int		y;

	img->img = mlx_xpm_file_to_image(set->mlx, path, &img->x, &img->y);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
	y = 0;
	while (y < img->y)
	{
		x = 0;
		while (x < img->x)
		{
			tex[img->x * y + x] = img->data[img->x * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(set->mlx, img->img);
}

void	init_tex(t_set *set)
{
	t_img	img;
	
	check_texture_file(set);
	init_wall_tex(set->tex);
	get_texture(set, &img, set->tex[0], set->north);
	get_texture(set, &img, set->tex[1], set->south);
	get_texture(set, &img, set->tex[2], set->east);
	get_texture(set, &img, set->tex[3], set->west);
	get_texture(set, &img, set->tex[4], set->sprite);
	free(set->north);
	free(set->south);
	free(set->east);
	free(set->west);
	free(set->sprite);
}

void	init_set(t_set *set)
{
	set->fov = 60 * (M_PI / 180);
	init_win(set);
	init_img(set, &set->img);
	init_player(&set->player);
	init_ray(set, &set->ray);
	init_tex(set);
}
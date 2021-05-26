/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:50:35 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/26 21:21:12 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		data_size(int *arr)
{
	int		i;

	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
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

void	get_texture(t_set *set, t_tex *size, int **tex, char *path)
{
	t_img	img;
	int		x;
	int		y;

	*tex = NULL;
	img.img = mlx_xpm_file_to_image(set->mlx, path, &size->x, &size->y);
	img.data = (int *)mlx_get_data_addr(img.img,
				&img.bpp, &img.size_l, &img.endian);
	if (!(*tex = (int *)malloc(sizeof(int) * (size->x * size->y))))
		exit_msg("Failed malloc.");
	y = 0;
	while (y < size->y)
	{
		x = 0;
		while (x < size->x)
		{
			(*tex)[size->x * y + x] = img.data[size->x * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(set->mlx, img.img);
}

void	sprite_pos(t_set *set, t_sprite *pos)
{
	int		i;

	i = 0;
	while (i < set->sprite_num)
	{
		pos[i].x = (pos[i].x + 0.5) * set->tex_size[0].x;
		pos[i].y = (pos[i].y + 0.5) * set->tex_size[0].y;
		i++;
	}
}

void	init_tex(t_set *set)
{
	check_texture_file(set);
	get_texture(set, &set->tex_size[0], &set->tex[0], set->north);
	get_texture(set, &set->tex_size[1], &set->tex[1], set->south);
	get_texture(set, &set->tex_size[2], &set->tex[2], set->east);
	get_texture(set, &set->tex_size[3], &set->tex[3], set->west);
	get_texture(set, &set->tex_size[4], &set->tex[4], set->sprite);
	sprite_pos(set, set->sprites);
	free(set->north);
	free(set->south);
	free(set->east);
	free(set->west);
	free(set->sprite);
}

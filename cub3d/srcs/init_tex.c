/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:50:35 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/25 20:39:03 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "color.h"

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

void	get_texture(t_set *set, int *tex, char *path)
{
	t_img	img;
	int		x;
	int		y;

	img.img = mlx_xpm_file_to_image(set->mlx, path, &img.x, &img.y);
	img.data = (int *)mlx_get_data_addr(img.img, &img.bpp, &img.size_l, &img.endian);
	y = 0;
	while (y < img.y)
	{
		x = 0;
		while (x < img.x)
		{
			tex[img.x * y + x] = img.data[img.x * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(set->mlx, img.img);
}

void	init_tex(t_set *set)
{
	check_texture_file(set);
	init_wall_tex(set->tex);
	get_texture(set, set->tex[0], set->north);
	get_texture(set, set->tex[1], set->south);
	get_texture(set, set->tex[2], set->east);
	get_texture(set, set->tex[3], set->west);
	get_texture(set, set->tex[4], set->sprite);
	free(set->north);
	free(set->south);
	free(set->east);
	free(set->west);
	free(set->sprite);
}
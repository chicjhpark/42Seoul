/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 00:54:31 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/27 04:02:28 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			file_header(t_set *set, int fd)
{
	int						size;
	int						padding;
	static unsigned char	header[14];

	ft_memset(header, 0, 14);
	padding = (4 - (set->win_x * 3) % 4) % 4;
	size = 54 + (3 * set->win_x + padding) * set->win_y;
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	header[2] = (unsigned char)(size);
	header[3] = (unsigned char)(size >> 8);
	header[4] = (unsigned char)(size >> 16);
	header[5] = (unsigned char)(size >> 24);
	header[10] = (unsigned char)(54);
	write(fd, header, 14);
}

void			info_header(t_set *set, int fd)
{
	static unsigned char	header[40];

	ft_memset(header, 0, 40);
	header[0] = (unsigned char)(40);
	header[4] = (unsigned char)(set->win_x);
	header[5] = (unsigned char)(set->win_x >> 8);
	header[6] = (unsigned char)(set->win_x >> 16);
	header[7] = (unsigned char)(set->win_x >> 24);
	header[8] = (unsigned char)(set->win_y);
	header[9] = (unsigned char)(set->win_y >> 8);
	header[10] = (unsigned char)(set->win_y >> 16);
	header[11] = (unsigned char)(set->win_y >> 24);
	header[12] = (unsigned char)(1);
	header[14] = (unsigned char)(24);
	write(fd, header, 40);
}

void			save_buffer(t_set *set, int fd)
{
	int						i;
	int						j;
	int						padding;
	static unsigned char	rgb[3];

	ft_memset(rgb, 0, 3);
	padding = (4 - (set->win_x * 3) % 4) % 4;
	i = set->win_y;
	while (i > 0)
	{
		i--;
		j = 0;
		while (j < set->win_x)
		{
			write(fd, &set->img.data[i * set->win_x + j], 3);
			j++;
		}
		if (padding > 0)
			write(fd, &rgb, padding);
	}
}

void			save_bmp(t_set *set)
{
	int fd;

	set->img.img = mlx_new_image(set->mlx, set->win_x, set->win_y);
	set->img.data = (int *)mlx_get_data_addr(set->img.img, &set->img.bpp,
										&set->img.size_l, &set->img.endian);
	render_loop(set);
	if ((fd = open("screen_shot.bmp"
					, O_WRONLY | O_TRUNC | O_CREAT, 0744)) == -1)
		exit_msg("Failed save.");
	file_header(set, fd);
	info_header(set, fd);
	save_buffer(set, fd);
	close(fd);
	free_set(set);
	printf("Save success.\n");
	exit(0);
}

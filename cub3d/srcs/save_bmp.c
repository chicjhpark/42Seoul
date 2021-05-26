/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 00:54:31 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/27 01:02:57 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_file_header(t_set *set, int fd)
{
	int						filesize;
	int						padding;
	static unsigned char	fileheader[] = {
		0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
	};

	padding = (4 - (set->win_x * 3) % 4) % 4;
	filesize = 54 + (3 * set->win_x + padding) * set->win_y;
	fileheader[0] = (unsigned char)('B');
	fileheader[1] = (unsigned char)('M');
	fileheader[2] = (unsigned char)(filesize);
	fileheader[3] = (unsigned char)(filesize >> 8);
	fileheader[4] = (unsigned char)(filesize >> 16);
	fileheader[5] = (unsigned char)(filesize >> 24);
	fileheader[10] = (unsigned char)(54);
	write(fd, fileheader, 14);
}

void			ft_image_header(t_set *set, int fd)
{
	static unsigned char	infoheader[] = {
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
	};

	infoheader[0] = (unsigned char)(40);
	infoheader[4] = (unsigned char)(set->win_x);
	infoheader[5] = (unsigned char)(set->win_x >> 8);
	infoheader[6] = (unsigned char)(set->win_x >> 16);
	infoheader[7] = (unsigned char)(set->win_x >> 24);
	infoheader[8] = (unsigned char)(set->win_y);
	infoheader[9] = (unsigned char)(set->win_y >> 8);
	infoheader[10] = (unsigned char)(set->win_y >> 16);
	infoheader[11] = (unsigned char)(set->win_y >> 24);
	infoheader[12] = (unsigned char)(1);
	infoheader[14] = (unsigned char)(24);
	write(fd, infoheader, 40);
}

void			ft_save_buffer(t_set *set, int fd)
{
	int						i;
	int						j;
	int						padding;
	static unsigned char	zero[3] = { 0, 0, 0};

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
			write(fd, &zero, padding);
	}
}

void			save_bmp(t_set *set)
{
	int fd;

	set->img.img = mlx_new_image(set->mlx, set->win_x, set->win_y);
	set->img.data = (int *)mlx_get_data_addr(set->img.img, &set->img.bpp,
			&set->img.size_l, &set->img.endian);
	render_loop(set);
	if ((fd = open("output.bmp"
					, O_WRONLY | O_TRUNC | O_CREAT, 0744)) == -1)
		exit_msg("Failed save bmp.");
	ft_file_header(set, fd);
	ft_image_header(set, fd);
	ft_save_buffer(set, fd);
	close(fd);
	printf("Save success.\n");
	exit(0);
}

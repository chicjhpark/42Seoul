/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:37:17 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/26 23:43:00 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

# define BITMAPFILEHEADER 14
# define BITMAPINFOHEADER 40

static void	bmp_header(t_set *set, int fd)
{
	int		tmp;
	char	header[BITMAPFILEHEADER];
	char	info[BITMAPINFOHEADER];

	ft_memset(&header, 0, BITMAPFILEHEADER);
	ft_memset(&info, 0, BITMAPINFOHEADER);
	ft_memmove(&header[0], "BM", 2);
	tmp = BITMAPFILEHEADER + BITMAPINFOHEADER +
		(set->img.bpp / 8) * set->win_x * set->win_y;
	ft_memmove(&header[2], &tmp, 4);
	tmp = BITMAPFILEHEADER + BITMAPINFOHEADER;
	ft_memmove(&header[10], &tmp, 4);
	write(fd, header, BITMAPFILEHEADER);
	tmp = BITMAPINFOHEADER;
	ft_memmove(&info[0], &tmp, 4);
	ft_memmove(&info[4], &set->win_x, 4);
	ft_memmove(&info[8], &set->win_y, 4);
	tmp = 1;
	ft_memmove(&info[12], &tmp, 2);
	ft_memmove(&info[14], &set->img.bpp, 2);
	write(fd, info, BITMAPINFOHEADER);
}

static void	bmp_data(t_set *set, int fd)
{
	int		x;
	int		y;

	y = set->win_y;
	while (y-- > 0)
	{
		x = -1;
		while (++x < set->win_x)
			write(fd, &set->img.data[y * set->img.size_l + x].i, (set->img.bpp / 8));
	}
}
int			save_bmp(t_set *set)
{
	int		fd;

	if ((fd = open("./image.bmp", O_CREAT | O_RDWR)) == -1)
		exit_cub3d_msg(set, "can't (create | open) image.bmp file");
	update(set);
	render(set);
	bmp_header(set, fd);
	bmp_data(set, fd);
	close(fd);
	return (0);
}

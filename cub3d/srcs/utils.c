/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 23:09:29 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/22 20:08:18 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	clear_frame(t_img *img, int color)
{
	int		x;
	int		y;

	y = 0;
	while (y < img->y)
	{
		x = 0;
		while (x < img->x)
		{
			img->data[img->x * y + x] = color;
			x++;
		}
		y++;
	}
}

int		check_num(char *num)
{
	int		i;

	if (num[0] == '0' && num[1] != '\0')
		return (FALSE);
	i = 0;
	while (num[i])
	{
		if (num[i] < '0' || num[i] > '9')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int		check_extension(const char *s, const char *ext)
{
	int		i;
	int		j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i + j] == ext[j] && s[i] && ext[j])
			j++;
		if (s[i + j] == '\0' && ext[j] == '\0')
			return (TRUE);
		i++;
	}
	return (FALSE);
}
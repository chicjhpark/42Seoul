/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 23:08:35 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/25 22:23:48 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include <mlx.h>

void	free_array(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_set(t_set *set)
{
	free_array(set->map);
	free(set->tex[0]);
	free(set->tex[1]);
	free(set->tex[2]);
	free(set->tex[3]);
	free(set->tex[4]);
	free(set->ray);
	free(set->sprites);
	mlx_destroy_image(set->mlx, set->img.img);
	mlx_destroy_window(set->mlx, set->win);
	free(set->mlx);
}

void	exit_msg(const char *msg)
{
	printf("Error\n%s\n", msg);
	exit(0);
}

int		exit_success(t_set *set)
{
	free_set(set);
	printf("EXIT SUCCESS\n");
	exit(0);
}

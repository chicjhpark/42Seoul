/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 23:08:35 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/22 22:38:02 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

void    free_array(char **arr)
{
    int     i;

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
	free(set->north);
	free(set->south);
	free(set->west);
	free(set->east);
	free(set->sprite);
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
	int		i;
	printf("Resolution : %d %d\n", set->win_x, set->win_y);
	printf("North texture path : %s\n", set->north);
	printf("South texture path : %s\n", set->south);
	printf("West texture path : %s\n", set->west);
	printf("East texture path : %s\n", set->east);
	printf("Sprite texture path : %s\n", set->sprite);
	printf("Floor RGB : %d %d %d\n", set->floor.r, set->floor.g, set->floor.b);
	printf("Ceilling RGB : %d %d %d\n", set->ceil.r, set->ceil.g, set->ceil.b);
	printf("Map : %d %d\n", set->map_x, set->map_y);
	printf("Player position : (%f, %f)\n", set->player.x, set->player.y);
	printf("\n");
	i = 0;
	while (set->map[i])
	{
		printf("%s\n", set->map[i]);
		i++;
	}
	printf("\n");
	printf("EXIT SUCCESS\n");
	free_set(set);
	return (0);
}
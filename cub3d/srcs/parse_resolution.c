/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 20:28:30 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/22 19:14:50 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	parse_resolution(t_set *set, char **data)
{
	int		count;
	int		x;
	int		y;

	count = 0;
	if (set->type[0] == 1)
		exit_msg("Duplicate resolution.");
	while (data[count])
		count++;
	if (count != 3 || check_num(data[1]) == FALSE || check_num(data[2]) == FALSE)
		exit_msg("Invalid resolution.");
	mlx_get_screen_size(set->mlx, &set->win_x, &set->win_y);
	x = ft_atoi(data[1]);
	y = ft_atoi(data[2]);
	if (x == 0 || y == 0)
		exit_msg("Invalid resolution.");
	if (x < set->win_x && x > 0)
		set->win_x = x;
	if (y < set->win_y && y > 0)
		set->win_y = y;
	set->type[0] = 1;
}
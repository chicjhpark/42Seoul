/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 20:29:47 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/24 03:56:31 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		check_rgb(const int rgb)
{
	if (rgb < 0 || rgb > 255)
		exit_msg("Invalid rgb.");
	return (1);
}

void	parse_rgb(t_set *set, char **rgb, const char type)
{
	int		temp[3];

	temp[0] = ft_atoi(rgb[0]);
	temp[1] = ft_atoi(rgb[1]);
	temp[2] = ft_atoi(rgb[2]);
	if (check_rgb(temp[0]) && check_rgb(temp[1]) && check_rgb(temp[2]))
	{
		if (type == 'F' && set->type[6] != 1)
		{
			set->floor.r = temp[0];
			set->floor.g = temp[1];
			set->floor.b = temp[2];
			set->type[6] = 1;
		}
		else if (type == 'C' && set->type[7] != 1)
		{
			set->ceil.r = temp[0];
			set->ceil.g = temp[1];
			set->ceil.b = temp[2];
			set->type[7] = 1;
		}
		else
			exit_msg("Duplitcate color of floor or ceilling.");
	}
}

void	parse_color(t_set *set, char **data)
{
	int		count;
	char	**rgb;

	count = 0;
	while (data[count])
		count++;
	rgb = NULL;
	if (count != 2 || (rgb = ft_split(data[1], ',')) == NULL)
		exit_msg("Invalid color of floor or ceilling.");
	count = 0;
	while (rgb[count])
		count++;
	if (count != 3)
		exit_msg("Invalid color of floor or ceilling.");
	if (check_num(rgb[0]) == FALSE || check_num(rgb[1]) == FALSE
				|| check_num(rgb[2]) == FALSE)
		exit_msg("Invalid color of floor or ceilling.");
	if (data[0][0] == 'F')
		parse_rgb(set, rgb, 'F');
	else if (data[0][0] == 'C')
		parse_rgb(set, rgb, 'C');
	free_array(rgb);
}

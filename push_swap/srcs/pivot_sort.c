/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:50:44 by jaehpark          #+#    #+#             */
/*   Updated: 2021/06/28 09:17:45 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		check_max_pivot(int *b, t_info *info)
{
	int		i;
	int		j;

	i = 0;
	info->p_max = b[check_max(b, info->b_num)];
	while (i < 3)
	{
		j = 0;
		info->pivot = b[check_min(b, info->b_num)];
		while (j < info->b_num)
		{
			if (info->pivot < b[j] && info->p_max > b[j])
				info->pivot = b[j];
			j++;
		}
		info->p_max = info->pivot;
		i++;
	}
}

void		push_a_max(int *a, int *b, t_info *info)
{
	int		i;
	int		j;
	int		k;

	if (info->b_num > 1)
		check_max_pivot(b, info);
	i = 0;
	while (i < 3 && info->b_num > 0)
	{
		j = 0;
		k = info->b_num - 1;
		while (b[0] <= info->p_max && j < info->b_num && k >= 0)
		{
			if (b[j] > info->p_max)
				while (b[0] <= info->p_max && info->b_num > 1)
					ft_msg(rotate_b(b, info));
			if (b[k] > info->p_max)
				while (b[0] <= info->p_max && info->b_num > 1)
					ft_msg(reverse_rotate_b(b, info));
			j++;
			k--;
		}
		ft_msg(push_a(a, b, info));
		i++;
	}
}

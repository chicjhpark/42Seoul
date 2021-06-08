/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:50:44 by jaehpark          #+#    #+#             */
/*   Updated: 2021/06/09 00:30:41 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(int *a, int *b, t_info *info)
{
	int		i;
	int		j;

	if (check_sort_a(a, info) == TRUE && info->a_num == info->num)
		return ;
	if (check_smallest(a, info->a_num - 1, info->a_num) == TRUE)
		ft_msg(reverse_rotate_a(a, info));
	else if (check_largest(a, 0, info->a_num) == TRUE)
		ft_msg(rotate_a(a, info));
	if (a[0] > a[1])
		ft_msg(swap_a(a));
	info->pivot = a[0];
	i = 0;
	while (i < info->a_num)
	{
		if (info->pivot > a[i])
		{
			info->pivot = a[i];
			info->pivot_i = i;
		}
		i++;
	}
	i = 0;
	while (info->pivot_i < info->a_num)
	{
		info->pivot_i++;
		i++;
	}
	j = 0;
	while (info->pivot_i > 0)
	{
		info->pivot_i--;
		j++;
	}
	if (i > j)
		while (info->pivot_i > 0)
		{
			ft_msg(rotate_a(a, info));
			info->pivot_i--;
		}
	else if (i < j)
		while (info->pivot_i < info->a_num)
		{
			ft_msg(reverse_rotate_a(a, info));
			info->pivot_i++;
		}
	ft_msg(push_b(b, a, info));
	while (check_sort_a(a, info) == TRUE && info->b_num > 0)
		ft_msg(push_a(a, b, info));
	sort_stack(a, b, info);
}

int		main(int argc, char **argv)
{
	int		a[argc - 1];
	int		b[argc - 1];
	t_info	info;

	if (argc >= 2)
	{
		init_info(&info, argc);
		init_stack(a, b, info, argv);
		sort_stack(a, b, &info);
	}
	return (0);
}

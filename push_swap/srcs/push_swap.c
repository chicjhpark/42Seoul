/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:50:44 by jaehpark          #+#    #+#             */
/*   Updated: 2021/06/24 19:46:39 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort_stack(int *a, int *b, t_info *info)
{
 	while (info->a_num <= 3 && info->b_num <= 3 && check_sort_a(a, info) == FALSE)
	{
		if (check_max(a, info->a_num) == 0 && check_min(b, info->b_num) == 0)
			ft_msg(rotate_ab(a, b, info));
		else if (check_max(a, info->a_num) == 0)
			ft_msg(rotate_a(a, info));
		else if (check_max(a, info->a_num) == 1 && check_min(b, info->b_num) == 1)
			ft_msg(reverse_rotate_ab(a, b, info));
		else if (check_max(a, info->a_num) == 1)
			ft_msg(reverse_rotate_a(a, info));
		else
			ft_msg(swap_ab(a, b, info));
	}
	while (info->a_num <= 3 && info->b_num > 3 && check_sort_a(a, info) == FALSE)
	{
		if (check_max(a, info->a_num) == 2 && b[1] > b[0] && b[1] > b[2]
			&& b[2] > b[0])
			ft_msg(rotate_ab(a, b, info));
		else if (check_max(a, info->a_num) == 0)
			ft_msg(rotate_a(a, info));
		else if (check_max(a, info->a_num) == 1
				&& b[info->b_num - 1] > b[0] && b[info->b_num - 1] > b[1])
			ft_msg(reverse_rotate_ab(a, b, info));
		else if (check_max(a, info->a_num) == 1)
			ft_msg(reverse_rotate_a(a, info));
		else if (b[1] > b[0] && b[1] > b[2] && b[0] > b[2])
			ft_msg(swap_ab(a, b, info));
		else
			ft_msg(swap_a(a));
	}
}

void	sort_stack(int *a, int *b, t_info *info)
{
	while (info->a_num > 3 && info->b_num <= 3 && check_sort_a(a, info) == FALSE)
	{
		if (a[0] > a[1])
			ft_msg(swap_ab(a, b, info));
		else if (a[1] > a[0] && a[1] > a[2] && check_min(b, info->b_num) == 0)
			ft_msg(rotate_ab(a, b, info));
		else if (a[1] > a[0] && a[1] > a[2])
			ft_msg(rotate_a(a, info));
		else if (check_min(b, info->b_num) == 1)
			ft_msg(reverse_rotate_ab(a, b, info));
		else
			ft_msg(reverse_rotate_a(a, info));
	}
	while (info->a_num > 3 && info->b_num > 3 && check_sort_a(a, info) == FALSE)
	{
		if (a[0] > a[1] && b[1] > b[0] && b[1] > b[2] && b[0] > b[2])
			ft_msg(swap_ab(a, b, info));
		else if (a[0] > a[1])
			ft_msg(swap_a(a));
		else if (a[1] > a[0] && a[1] > a[2] && b[1] > b[0] && b[1] > b[2]
				&& b[2] > b[0])
			ft_msg(rotate_ab(a, b, info));
		else if (a[1] > a[0] && a[1] > a[2])
			ft_msg(rotate_a(a, info));
		else if (b[info->b_num - 1] > b[0] && b[info->b_num - 1] > b[1])
			ft_msg(reverse_rotate_ab(a, b, info));
		else
			ft_msg(reverse_rotate_a(a, info));
	}
}

void	pivot_sort(int *a, int *b, t_info *info)
{
	if (info->a_num > 3 && a[0] < info->pivot
		&& a[0] < a[1] && a[0] < a[info->a_num - 1])
		ft_msg(push_b(b, a, info));
	else if (a[0] < a[1] && a[0] < a[info->a_num - 1])
	{
		if (a[1] < a[info->a_num - 1])
			ft_msg(rotate_a(a, info));
		else
			ft_msg(swap_a(a));
	}
	else if (a[1] < a[0] && a[1] < a[info->a_num - 1])
	{
		if (a[0] > a[info->a_num - 1])
			ft_msg(rotate_a(a, info));
		else
			ft_msg(swap_a(a));
	}
	else if (a[info->a_num - 1] < a[0] && a[info->a_num - 1] < a[1])
	{
		if (a[info->a_num - 1] < info->pivot)
			ft_msg(reverse_rotate_a(a, info));
		else if (a[0] < a[1])
			ft_msg(rotate_a(a, info));
		else
			ft_msg(swap_a(a));
	}
}

void	push_min_a(int *a, int *b, t_info *info)
{
	int		i;
	int		j;

	i = 0;
	while (i < 3 && info->b_num > 0)
	{
		j = 0;
		while (j < info->b_num)
		{
			if (j == check_max(b, info->b_num))
				break;
			j++;
		}
		if (j > info->b_num / 2)
			while (check_max(b, info->b_num) != 0 && info->b_num > 1)
				ft_msg(reverse_rotate_b(b, info));
		else
			while (check_max(b, info->b_num) != 0 && info->b_num > 1)
				ft_msg(rotate_b(b, info));
		ft_msg(push_a(a, b, info));
		i++;
	}
}

void	parse_stack(int *a, int *b, t_info *info)
{
	if (check_sort_a(a, info) == TRUE)
		return ;
	while (info->a_num > 3)
	{
		init_pivot(a, info);
		while (info->a_num > 3 && check_pivot(a, info) == TRUE)
			pivot_sort(a, b, info);
	}
	while (check_sort_a(a, info) != TRUE || info->a_num != info->num)
	{
		while (check_sort_a(a, info) == FALSE)
		{
			if (info->a_num > 3)
				sort_stack(a, b, info);
			else
				simple_sort_stack(a, b, info);
		}
		while (check_sort_a(a, info) == TRUE && info->b_num > 0)
			push_min_a(a, b, info);
	}
}

int		main(int argc, char **argv)
{
	int		*a;
	int		*b;
	t_info	info;

	if (argc >= 2)
	{
		init_info(&info, argc);
		init_stack(&a, &b, info, &argv[1]);
		parse_stack(a, b, &info);
		free(a);
		free(b);
	}
	return (0);
}

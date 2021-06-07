/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:50:44 by jaehpark          #+#    #+#             */
/*   Updated: 2021/06/08 07:52:03 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(int *a, int *b, t_info *info)
{
	if (info->a_num == info->num && check_sort_a(a, info->a_num) == TRUE)
		return ;
	if (check_smallest(a, info->a_num - 1, info->a_num) == TRUE &&
		check_largest(b, info->b_num - 1, info->b_num) == TRUE)
	{
		ft_reverse_rotate(a, info->a_num, 0);
		ft_reverse_rotate(b, info->b_num, 0);
		ft_msg("rrr");
	}
	else if (check_smallest(a, info->a_num - 1, info->a_num) == TRUE)
		ft_reverse_rotate(a, info->a_num, 'a');
	else if (check_largest(b, info->b_num - 1, info->b_num) == TRUE)
		ft_reverse_rotate(b, info->b_num, 'b');
	if (check_largest(a,  0, info->a_num) == TRUE &&
		check_smallest(b, 0, info->b_num) == TRUE)
	{
		ft_rotate(a, info->a_num, 0);
		ft_rotate(b, info->b_num, 0);
		ft_msg("rr");
	}
	else if (check_largest(a,  0, info->a_num) == TRUE)
		ft_rotate(a, info->a_num, 'a');
	else if (check_smallest(b, 0, info->b_num) == TRUE)
		ft_rotate(b, info->b_num, 'b');
	if (a[0] > a[1] && info->a_num >= 2 && b[0] < b[1] && info->b_num >= 2)
	{
		ft_swap(a, 0);
		ft_swap(b, 0);
		ft_msg("ss");
	}
	else if (a[0] > a[1] && info->a_num >= 2)
		ft_swap(a, 'a');
	else if (b[0] < b[1] && info->b_num >= 2)
		ft_swap(b, 'b');
	init_pivot(a, b, info);
	if (a[0] < info->pivot_a)
	{
		ft_push(b, a, &info->b_num, &info->a_num);
		ft_msg("pb");
	}
	else if (b[0] > info->pivot_b)
	{
		ft_push(a, b, &info->a_num, &info->b_num);
		ft_msg("pa");
	}
	else if (check_sort_a(a, info->a_num) == TRUE && check_sort_b(b, info->b_num) == TRUE)
	{
		ft_push(a, b, &info->a_num, &info->b_num);
		ft_msg("pa");
	}
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
		print_result(a, b, info);
	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 16:58:21 by jaehpark          #+#    #+#             */
/*   Updated: 2021/06/28 09:18:31 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_p_max(int *b, t_info *info)
{
	int		i;
	int		j;

	i = 0;
	j = info->b_num - 1;
	while (b[0] <= info->p_max && i < info->b_num && j >= 0)
	{
		if (b[i] > info->p_max)
			return (i);
		if (b[j] > info->p_max)
			return (j);
		i++;
		j--;
	}
	return (0);
}

void	sort_stack(int *a, int *b, t_info *info)
{
	while (info->b_num > 3 && check_sort_a(a, info) == FALSE)
	{
		if (check_max(a, info->a_num) == 0 && check_p_max(b, info) > 0
			&& check_p_max(b, info) < info->b_num / 2)
			ft_msg(rotate_ab(a, b, info));
		else if (check_max(a, info->a_num) == 0)
			ft_msg(rotate_a(a, info));
		else if (check_max(a, info->a_num) == 1
			&& check_p_max(b, info) >= info->b_num / 2)
			ft_msg(reverse_rotate_ab(a, b, info));
		else if (check_max(a, info->a_num) == 1)
			ft_msg(reverse_rotate_a(a, info));
		else if (b[0] > b[1] && check_p_max(b, info) > 0
				&& check_p_max(b, info) < info->b_num / 2)
			ft_msg(swap_ab(a, b, info));
		else
			ft_msg(swap_a(a));
	}
	sort_stack2(a, b, info);
}

void	sort_stack2(int *a, int *b, t_info *info)
{
	while (info->b_num <= 3 && check_sort_a(a, info) == FALSE)
	{
		if (check_max(a, info->a_num) == 0 && check_min(b, info->b_num) == 0)
			ft_msg(rotate_ab(a, b, info));
		else if (check_max(a, info->a_num) == 0)
			ft_msg(rotate_a(a, info));
		else if (check_max(a, info->a_num) == 1
				&& check_min(b, info->b_num) == 1)
			ft_msg(reverse_rotate_ab(a, b, info));
		else if (check_max(a, info->a_num) == 1)
			ft_msg(reverse_rotate_a(a, info));
		else
			ft_msg(swap_ab(a, b, info));
	}
}

void	sort_stack4(int *a, int *b, t_info *info)
{
	while (info->b_num > 3 && check_sort_a(a, info) == FALSE)
	{
		if (a[0] > a[1] && b[0] > b[1] && check_p_max(b, info) > 0
			&& check_p_max(b, info) < info->b_num / 2)
			ft_msg(swap_ab(a, b, info));
		else if (a[0] > a[1])
			ft_msg(swap_a(a));
		else if (a[1] > a[0] && a[1] > a[2] && check_p_max(b, info) > 0
				&& check_p_max(b, info) < info->b_num / 2)
			ft_msg(rotate_ab(a, b, info));
		else if (a[1] > a[0] && a[1] > a[2])
			ft_msg(rotate_a(a, info));
		else if (check_p_max(b, info) >= info->b_num / 2)
			ft_msg(reverse_rotate_ab(a, b, info));
		else
			ft_msg(reverse_rotate_a(a, info));
	}
}

void	sort_stack3(int *a, int *b, t_info *info)
{
	while (info->b_num <= 3 && check_sort_a(a, info) == FALSE)
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
	sort_stack4(a, b, info);
}

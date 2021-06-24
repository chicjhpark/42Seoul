/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_ab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 06:30:38 by jaehpark          #+#    #+#             */
/*   Updated: 2021/06/24 17:31:18 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*swap_ab(int *a, int *b, t_info *info)
{
	if (info->b_num < 2 || check_sort_b(b, info) == TRUE)
	{
		ft_msg(swap_a(a));
		return (NULL);
	}
	else
	{
		swap_a(a);
		swap_b(b);
	}
	return ("ss");
}

char	*rotate_ab(int *a, int *b, t_info *info)
{
	if (info->b_num < 2 || check_sort_b(b, info) == TRUE)
	{
		ft_msg(rotate_a(a, info));
		return (NULL);
	}
	else
	{
		rotate_a(a, info);
		rotate_b(b, info);
	}
	return("rr");
}

char	*reverse_rotate_ab(int *a, int *b, t_info *info)
{
	if (info->b_num < 2 || check_sort_b(b, info) == TRUE)
	{
		ft_msg(reverse_rotate_a(a, info));
		return (NULL);
	}
	else
	{
		reverse_rotate_a(a, info);
		reverse_rotate_b(b, info);
	}
	return ("rrr");
}
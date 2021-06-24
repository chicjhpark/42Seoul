/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 20:26:27 by jaehpark          #+#    #+#             */
/*   Updated: 2021/06/24 15:59:39 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*swap_b(int *b)
{
	int		temp;

	temp = b[0];
	b[0] = b[1];
	b[1] = temp;
	return ("sb");
}

char	*push_b(int *b, int *a, t_info *info)
{
	int		i;

	if (info->a_num == 0)
		return (NULL);
	i = info->b_num;
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	info->b_num += 1;
	b[0] = a[0];
	i = 0;
	while (i < info->a_num)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i] = info->max;
	info->a_num -= 1;
	return ("pb");
}

char	*rotate_b(int *b, t_info *info)
{
	int		temp;
	int		i;

	if (info->b_num < 2)
		return (NULL);
	temp = b[0];
	i = 0;
	while (i < info->b_num)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[i - 1] = temp;
	return ("rb");
}

char	*reverse_rotate_b(int *b, t_info *info)
{
	int		temp;
	int		i;

	if (info->b_num < 2)
		return (NULL);
	temp = b[info->b_num - 1];
	i = info->b_num - 1;
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = temp;
	return ("rrb");
}

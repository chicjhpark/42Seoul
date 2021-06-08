/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 05:13:11 by jaehpark          #+#    #+#             */
/*   Updated: 2021/06/09 07:45:55 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*swap_a(int *a)
{
	int		temp;

	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
	return ("sa");
}

char	*push_a(int *a, int *b, t_info *info)
{
	int		i;

	if (info->b_num == 0)
		return (NULL);
	i = info->a_num;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	info->a_num += 1;
	a[0] = b[0];
	i = 0;
	while (i < info->b_num)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[i] = 0;
	info->b_num -= 1;
	return ("pa");
}

char	*rotate_a(int *a, t_info *info)
{
	int		temp;
	int		i;

	if (info->a_num < 2)
		return (NULL);
	temp = a[0];
	i = 0;
	while (i < info->a_num)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i - 1] = temp;
	return ("ra");
}

char	*reverse_rotate_a(int *a, t_info *info)
{
	int		temp;
	int		i;

	if (info->a_num < 2)
		return (NULL);
	temp = a[info->a_num - 1];
	i = info->a_num;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = temp;
	return ("rra");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 20:32:13 by jaehpark          #+#    #+#             */
/*   Updated: 2021/06/09 00:11:43 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_sort_a(int *a, t_info *info)
{
	int		i;

	if (info->a_num < 1)
		return (FALSE);
	i = 0;
	while (i < info->a_num - 1)
	{
		if (a[i] > a[i + 1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int		check_sort_b(int *b, t_info *info)
{
	int		i;

	if (info->b_num < 1)
		return (FALSE);
	i = 0;
	while (i < info->b_num - 1)
	{
		if (b[i] < b[i + 1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int		check_largest(int *n, int i, int num)
{
	int		j;

	if (num < 2)
		return (FALSE);
	j = 0;
	while (j < num)
	{
		if (n[i] < n[j])
			return (FALSE);
		j++;
	}
	return (TRUE);
}

int		check_smallest(int *n, int i, int num)
{
	int		j;

	if (num < 2)
		return (FALSE);
	j = 0;
	while (j < num)
	{
		if (n[i] > n[j])
			return (FALSE);
		j++;
	}
	return (TRUE);
}
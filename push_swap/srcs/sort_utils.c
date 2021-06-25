/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 20:32:13 by jaehpark          #+#    #+#             */
/*   Updated: 2021/06/25 01:13:29 by jaehpark         ###   ########.fr       */
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

int		check_max(int *n, int num)
{
	int		i;
	int		j;

	if (num < 2)
		return (-1);
	i = 0;
	j = 0;
	while (i < num)
	{
		if (n[i] > n[j])
			j = i;
		i++;
	}
	return (j);
}

int		check_min(int *n, int num)
{
	int		i;
	int		j;

	if (num < 2)
		return (-1);
	i = 0;
	j = 0;
	while (i < num)
	{
		if (n[i] < n[j])
			j = i;
		i++;
	}
	return (j);
}

int		check_pivot(int *n, int num, t_info *info, char c)
{
	int		i;

	i = 0;
	if (c == 'a')
		while (i < num)
		{
			if (n[i] < info->pivot)
				return (TRUE);
			i++;
		}
	else
		while (i < num)
		{
			if (n[i] > info->pivot)
				return (TRUE);
			i++;
		}
	return (FALSE);
}
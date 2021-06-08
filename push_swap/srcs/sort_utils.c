/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 20:32:13 by jaehpark          #+#    #+#             */
/*   Updated: 2021/06/08 20:32:49 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_sort_a(int *n, int n_num)
{
	int		i;

	if (n_num < 1)
		return (FALSE);
	i = 0;
	while (i < n_num - 1)
	{
		if (n[i] > n[i + 1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int		check_sort_b(int *n, int n_num)
{
	int		i;

	if (n_num < 1)
		return (FALSE);
	i = 0;
	while (i < n_num - 1)
	{
		if (n[i] < n[i + 1])
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
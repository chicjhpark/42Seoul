/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 05:13:11 by jaehpark          #+#    #+#             */
/*   Updated: 2021/06/08 20:32:56 by jaehpark         ###   ########.fr       */
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

char	*push_a(int *a, int *b, int *a_num, int *b_num)
{
	int		i;

	if (b_num[0] == 0)
		return ;
	i = a_num[0];
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a_num[0] += 1;
	a[0] = b[0];
	i = 0;
	while (i < b_num[0])
	{
		a[i] = b[i + 1];
		i++;
	}
	a[i] = 0;
	b[0] -= 1;
	return ("pa");
}

char	*rotate_a(int *a, int num)
{
	int		temp;
	int		i;

	if (num < 2)
		return ;
	temp = a[0];
	i = 0;
	while (i < num)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i - 1] = temp;
	return("ra");
}

char	*reverse_rotate_a(int *a, int num)
{
	int		temp;
	int		i;

	if (num < 2)
		return ;
	temp = a[num - 1];
	i = num;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = temp;
	return("rra");
}
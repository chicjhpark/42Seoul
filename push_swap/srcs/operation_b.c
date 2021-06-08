/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 20:26:27 by jaehpark          #+#    #+#             */
/*   Updated: 2021/06/08 20:28:27 by jaehpark         ###   ########.fr       */
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

char	*push_b(int *b, int *a, int *b_num, int *a_num)
{
	int		i;

	if (a_num[0] == 0)
		return ;
	i = b_num[0];
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b_num[0] += 1;
	b[0] = a[0];
	i = 0;
	while (i < a_num[0])
	{
		b[i] = a[i + 1];
		i++;
	}
	b[i] = 0;
	a[0] -= 1;
	return ("pb");
}

char	*rotate_b(int *b, int num)
{
	int		temp;
	int		i;

	if (num < 2)
		return ;
	temp = b[0];
	i = 0;
	while (i < num)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[i - 1] = temp;
	return("rb");
}

char	*reverse_rotate_a(int *b, int num)
{
	int		temp;
	int		i;

	if (num < 2)
		return ;
	temp = b[num - 1];
	i = num;
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = temp;
	return("rrb");
}
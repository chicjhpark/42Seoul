/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 05:13:11 by jaehpark          #+#    #+#             */
/*   Updated: 2021/06/07 21:45:10 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *n)
{
	int		temp;

	temp = n[0];
	n[0] = n[1];
	n[1] = temp;
}

void	ft_push(int *n, int *n2, int *n_num, int *n2_num)
{
	int		i;

	if (n2_num[0] == 0)
		return ;
	i = n_num[0];
	while (i > 0)
	{
		n[i] = n[i - 1];
		i--;
	}
	n_num[0] += 1;
	n[0] = n2[0];
	i = 0;
	while (i < n2_num[0])
	{
		n2[i] = n2[i + 1];
		i++;
	}
	n2[i] = 0;
	n2_num[0] -= 1;
}

void	ft_rotate(int *n, int num)
{
	int		temp;
	int		i;

	if (num < 2)
		return ;
	temp = n[0];
	i = 0;
	while (i < num)
	{
		n[i] = n[i + 1];
		i++;
	}
	n[i - 1] = temp;
}

void	ft_reverse_rotate(int *n, int num)
{
	int		temp;
	int		i;

	if (num < 2)
		return ;
	temp = n[num - 1];
	i = num;
	while (i > 0)
	{
		n[i] = n[i - 1];
		i--;
	}
	n[0] = temp;
}
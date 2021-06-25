/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 22:46:03 by jaehpark          #+#    #+#             */
/*   Updated: 2021/06/25 12:15:18 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_pivot(int *n, int num, t_info *info)
{
	int		min;
	int		max;
	int		temp;
	int		i;

	min = n[check_min(n, num)];
	max = n[check_max(n, num)];
	while (min != max)
	{
		temp = max;
		i = -1;
		while (++i < num)
			if (min < n[i] && temp > n[i])
				temp = n[i];
		min = temp;
		i = -1;
		while (++i < num)
			if (max > n[i] && temp < n[i])
				temp = n[i];
		max = temp;
		temp = min;
		i = -1;
		while (++i < num)
			if (max > n[i] && temp < n[i])
				temp = n[i];
		max = temp;
		temp = min;
		i = -1;
		while (++i < num)
			if (max > n[i] && temp < n[i])
				temp = n[i];
		max = temp;
		temp = min;
		i = -1;
		while (++i < num)
			if (max > n[i] && temp < n[i])
				temp = n[i];
		max = temp;
		temp = min;
		i = -1;
		while (++i < num)
			if (max > n[i] && temp < n[i])
				temp = n[i];
		max = temp;
		temp = min;
		i = -1;
		while (++i < num)
			if (max > n[i] && temp < n[i])
				temp = n[i];
		max = temp;
		temp = min;
		i = -1;
		while (++i < num)
			if (max > n[i] && temp < n[i])
				temp = n[i];
		max = temp;
	}
	info->pivot = min;
}

void	init_info(t_info *info, int argc)
{
	ft_memset(info, 0, sizeof(t_info));
	info->num = argc - 1;
	info->a_num = info->num;
	info->max = 2147483647;
	info->min = -2147483648;
}

void	init_stack(int **a, int **b, t_info info, char **argv)
{
	long long	n;
	int			i;
	int			j;

	*a = (int *)malloc(sizeof(int) * (info.num + 1));
	*b = (int *)malloc(sizeof(int) * (info.num + 1));
	if (*a == NULL || *b == NULL)
		exit_msg();
	ft_intset(*a, info.max, info.num + 1);
	ft_intset(*b, info.min, info.num + 1);
	i = -1;
	while (argv[++i])
	{
		n = ft_atol(argv[i]);
		if (n < info.min || n > info.max || (argv[i][0] != '1' && n == 1))
			exit_msg();
		(*a)[i] = n;
		j = 0;
		while (j < i)
		{
			if ((*a)[i] == (*a)[j])
				exit_msg();
			j++;
		}
	}
}

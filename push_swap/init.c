/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 22:46:03 by jaehpark          #+#    #+#             */
/*   Updated: 2021/06/07 23:26:41 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		init_info(t_info *info, int argc)
{
	ft_memset(info, 0, sizeof(t_info));
	info->num = argc - 1;
	info->a_num = info->num;
}

void		init_stack(int *a, int *b, t_info info, char **argv)
{
	long long	n;
	int			i;
	int			j;

	ft_memset(a, 0, sizeof(int) * (info.num + 1));
	ft_memset(b, 0, sizeof(int) * (info.num + 1));
	i = 0;
	while (argv[i + 1])
	{
		n = ft_atol(argv[i + 1]);
		if (n < -2147483648 || n > 2147483647 ||
				(argv[i + 1][0] != '1' && n == 1))
			exit_msg();
		a[i] = n;
		i++;
	}
	i = 0;
	while (i < info.a_num)
	{
		j = 0;
		while (j < info.a_num)
		{
			if (i != j && a[i] == a[j])
				exit_msg();
			j++;
		}
		i++;
	}
}

void	init_pivot(int *a, int *b, t_info *info)
{
	int		i;

	info->pivot_a = -2147483648;
	info->pivot_b = 2147483647;
	i = 0;
	if (check_sort_a(a, info->a_num) == FALSE)
		while (i < info->a_num - 1)
		{
			if (a[i] > a[i + 1])
			{
				info->pivot_a = a[i];
				break ;
			}
			i++;
		}
	i = 0;
	if (check_sort_b(b, info->b_num) == FALSE)
		while (i < info->b_num - 1)
		{
			if (b[i] < b[i + 1])
			{
				info->pivot_b = b[i];
				break;
			}
			i++;
		}
}
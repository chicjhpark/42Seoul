/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 22:46:03 by jaehpark          #+#    #+#             */
/*   Updated: 2021/06/09 07:44:08 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		init_info(t_info *info, int argc)
{
	ft_memset(info, 0, sizeof(t_info));
	info->num = argc - 1;
	info->a_num = info->num;
	info->max = 2147483647;
	info->min = -2147483648;
}

void		init_stack(int **a, int **b, t_info info, char **argv)
{
	long long	n;
	int			i;
	int			j;

	*a = (int *)malloc(sizeof(int) * (info.num + 1));
	*b = (int *)malloc(sizeof(int) * (info.num + 1));
	if (*a == NULL || *b == NULL)
		exit_msg();
	ft_memset(a, 0, sizeof(int) * (info.num + 1));
	ft_memset(b, 0, sizeof(int) * (info.num + 1));
	i = 0;
	while (argv[++i])
	{
		n = ft_atol(argv[i]);
		if (n < info.min || n > info.max || (argv[i][0] != '1' && n == 1))
			exit_msg();
		a[i] = n;
		j = 0;
		while (j < i)
		{
			if (a[i] == a[j])
				exit_msg();
			j++;
		}
	}
}

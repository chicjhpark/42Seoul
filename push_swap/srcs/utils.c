/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 22:45:30 by jaehpark          #+#    #+#             */
/*   Updated: 2021/06/27 20:40:17 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		exit_msg(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void		ft_msg(char *s)
{
	if (s == NULL)
		return ;
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
}

int			*ft_intset(int *b, int c, size_t len)
{
	size_t			i;

	i = 0;
	while (i < len)
	{
		b[i] = c;
		i++;
	}
	return (b);
}

long long	ft_atol(char *s)
{
	long long	n;
	int			sign;
	int			i;

	n = 0;
	sign = 1;
	i = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	if (!(s[i] >= '0' && s[i] <= '9'))
		return (1);
	while (s[i] >= '0' && s[i] <= '9')
	{
		n = n * 10 + (s[i] - '0');
		i++;
	}
	if (n < 0)
		return (1);
	return (n * sign);
}

void		push_a_max(int *a, int *b, t_info *info)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	info->p_max = b[check_max(b, info->b_num)];
	while (i < 3)
	{
		j = 0;
		info->pivot = b[check_min(b, info->b_num)];
		while (j < info->b_num)
		{
			if (info->pivot < b[j] && info->p_max > b[j])
				info->pivot = b[j];
			j++;
		}
		info->p_max = info->pivot;
		i++;
	}
	i = 0;
	while (i < 3 && info->b_num > 0)
	{
		j = 0;
		k = info->b_num - 1;
		while (b[0] <= info->p_max && j < info->b_num && k >= 0)
		{
			if (b[j] > info->p_max)
				while (b[0] <= info->p_max && info->b_num > 1)
					ft_msg(rotate_b(b, info));
			if (b[k] > info->p_max)
				while (b[0] <= info->p_max && info->b_num > 1)
					ft_msg(reverse_rotate_b(b, info));
			j++;
			k--;
		}
		ft_msg(push_a(a, b, info));
		i++;
	}
}

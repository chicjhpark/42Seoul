/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 22:45:30 by jaehpark          #+#    #+#             */
/*   Updated: 2021/06/24 22:14:29 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		exit_msg(void)
{
	write(1, "Error\n", 6);
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

void	push_a_max(int *a, int *b, t_info *info)
{
	int		i;
	int		j;

	i = 0;
	while (i < 3 && info->b_num > 0)
	{
		j = 0;
		while (j < info->b_num)
		{
			if (j == check_max(b, info->b_num))
				break;
			j++;
		}
		if (j > info->b_num / 2)
			while (check_max(b, info->b_num) != 0 && info->b_num > 1)
				ft_msg(reverse_rotate_b(b, info));
		else
			while (check_max(b, info->b_num) != 0 && info->b_num > 1)
				ft_msg(rotate_b(b, info));
		ft_msg(push_a(a, b, info));
		i++;
	}
}
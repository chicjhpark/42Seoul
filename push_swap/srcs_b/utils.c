/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 22:45:30 by jaehpark          #+#    #+#             */
/*   Updated: 2021/06/26 18:16:40 by jaehpark         ###   ########.fr       */
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

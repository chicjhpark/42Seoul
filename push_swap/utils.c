/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 22:45:30 by jaehpark          #+#    #+#             */
/*   Updated: 2021/06/08 01:59:52 by jaehpark         ###   ########.fr       */
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
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
}

void		print_result(int *a, int *b, t_info info)
{
	int		i;

	i = 0;
	printf("a : ");
	while (i < info.a_num)
	{
		printf("%d ", a[i]);
		i++;
	}
	printf("\n");
	i = 0;
	printf("b : ");
	while (i < info.b_num)
	{
		printf("%d ", b[i]);
		i++;
	}
	printf("\n");
	printf("a_num : %d\nb_num : %d\n", info.a_num, info.b_num);
}

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:50:44 by jaehpark          #+#    #+#             */
/*   Updated: 2021/06/01 07:31:16 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

#define TRUE	0
#define FALSE	1

typedef unsigned long	u_long;

void	print_result(int *a, int *b, int argc)
{
	int		i;

	i = 0;
	printf("a : ");
	while (i < argc - 1)
	{
		printf("%d ", a[i]);
		i++;
	}
	printf("\n");
	printf("b : ");
	i = 0;
	while (i < argc - 1)
	{
		printf("%d ", b[i]);
		i++;
	}
	printf("\n");
}

void	init_stack(int *a, int *b, char **argv)
{
	int		i;

	i = 0;
	while (argv[i + 1])
	{
		a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	a[i] = '\0';
	ft_bzero(b, i);
}

int		check_sort(int *a, int num)
{
	int		i;

	i = 0;
	while (i < num)
	{
		if (a[i] > a[i + 1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int		ft_swap(int *n)
{
	int		temp;

	if (n[0] > n[1])
	{
		temp = n[0];
		n[0] = n[1];
		n[1] = temp;
		return (TRUE);
	}
	return (FALSE);
}

void	ft_sort(int *a, int *b, int num)
{
	if (ft_swap(a) == TRUE)
		write(1, "sa\n", 3);
	if (ft_swap(b) == TRUE)
		write(1, "sb\n", 3);
	if (check_sort(a, num) == TRUE)
		return ;
	else
		ft_sort(a, b, num);
}

int		main(int argc, char **argv)
{
	int		a[argc];
	int		b[argc];
	int		num;

	num = argc - 1;
	init_stack(a, b, argv);
	ft_sort(a, b, num);
	print_result(a, b, argc);
	return (0);
}

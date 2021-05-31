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

void	print_result(int *a, int *b, int argc)
{
	int 	i;

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

void	init_a(int *a, char **argv)
{
	int		i;

	i = 0;
	while (argv[i + 1])
	{
		a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	int		a[argc];
	int		b[argc];

	init_a(a, argv);
	print_result(a, b, argc);
	return (0);
}
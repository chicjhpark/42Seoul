/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:50:44 by jaehpark          #+#    #+#             */
/*   Updated: 2021/06/09 07:46:54 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_result(int *a, t_info info)
{
	int		i;

	i = 0;
	printf("a : ");
	while (i < info.num)
	{
		printf("%d", a[i]);
		printf(" ");
		i++;
	}
	printf("\n");
}

void	sort_opening(int *a, t_info *info)
{
	if (check_smallest(a, info->a_num - 1, info->a_num) == TRUE)
		ft_msg(reverse_rotate_a(a, info));
	else if (check_largest(a, 0, info->a_num) == TRUE)
		ft_msg(rotate_a(a, info));
	if (a[0] > a[1])
		ft_msg(swap_a(a));
}

void	sort_stack(int *a, int *b, t_info *info)
{
	if (check_sort_a(a, info) == TRUE && info->a_num == info->num)
		return ;
	sort_opening(a, info);
	
	while (check_sort_a(a, info) == TRUE && check_sort_b(b, info) == TRUE)
		push_a(a, b, info);
	sort_stack(a, b, info);
}

int		main(int argc, char **argv)
{
	int		*a;
	int		*b;
	t_info	info;

	if (argc >= 2)
	{
		init_info(&info, argc);
		init_stack(&a, &b, info, argv);
		sort_stack(a, b, &info);
		print_result(a, info);
	}
	return (0);
}

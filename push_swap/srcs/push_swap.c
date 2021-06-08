/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:50:44 by jaehpark          #+#    #+#             */
/*   Updated: 2021/06/08 20:44:06 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(int *a, int *b, t_info *info)
{
	
}

int		main(int argc, char **argv)
{
	int		a[argc - 1];
	int		b[argc - 1];
	t_info	info;

	if (argc >= 2)
	{
		init_info(&info, argc);
		init_stack(a, b, info, argv);
		sort_stack(a, b, &info);
	}
	return (0);
}
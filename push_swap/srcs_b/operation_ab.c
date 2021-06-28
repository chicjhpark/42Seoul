/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_ab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 06:30:38 by jaehpark          #+#    #+#             */
/*   Updated: 2021/06/27 12:20:37 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker_swap_ab(int *a, int *b)
{
	swap_a(a);
	swap_b(b);
}

void	checker_rotate_ab(int *a, int *b, t_info *info)
{
	rotate_a(a, info);
	rotate_b(b, info);
}

void	checker_reverse_rotate_ab(int *a, int *b, t_info *info)
{
	reverse_rotate_a(a, info);
	reverse_rotate_b(b, info);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 08:20:00 by jaehpark          #+#    #+#             */
/*   Updated: 2021/02/26 10:46:00 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_di(t_tag *tag)
{
	if (tag->nbr < 0)
	{
		tag->lspace -= 1;
		tag->rspace -= 1;
	}
	if (tag->zero != 1)
		while (tag->lspace-- > 0)
			tag->res += ft_putchar(' ');
	if (tag->nbr == 0 && tag->dot == 1 && tag->prec == 0)
	{
		if (tag->width > 0)
			while (tag->rspace-- > 0 || tag->size-- > 0)
				tag->res += ft_putchar(' ');
		return ;
	}
	if (tag->nbr < 0)
		tag->res += ft_putchar('-');
	while (tag->lspace-- > 0)
		tag->res += ft_putchar('0');
	while (tag->prec-- > 0)
		tag->res += ft_putchar('0');
	tag->res += ft_putstr(ft_itoa_sign(tag));
	while (tag->rspace-- > 0)
		tag->res += ft_putchar(' ');
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 08:20:28 by jaehpark          #+#    #+#             */
/*   Updated: 2021/02/26 08:20:37 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_tag(t_tag *tag)
{
	tag->minus = 0;
	tag->zero = 0;
	tag->width = 0;
	tag->prec = 0;
	tag->size = 0;
	tag->dot = 0;
	tag->nbr = 0;
	tag->lspace = 0;
	tag->rspace = 0;
}

int		ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int		ft_putstr(char *s)
{
	int	res;

	res = 0;
	if (s == NULL)
		return (0);
	while (*s != '\0')
	{
		write(1, &*s++, 1);
		res++;
	}
	return (res);
}

int		ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (c);
	return (0);
}

int		strchr_spec(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' ||
		c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

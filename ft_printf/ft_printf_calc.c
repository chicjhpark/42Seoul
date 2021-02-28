/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 08:20:49 by jaehpark          #+#    #+#             */
/*   Updated: 2021/02/28 23:35:01 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_sign(t_tag *tag)
{
	char	*s;

	if (!(s = (char *)malloc(sizeof(char) * (tag->size + 1))))
		return (NULL);
	s[tag->size] = '\0';
	if (tag->nbr < 0)
		while (tag->size-- > 0)
		{
			s[tag->size] = ((tag->nbr % 10) * -1) + '0';
			tag->nbr /= 10;
		}
	if (tag->nbr >= 0)
		while (tag->size-- > 0)
		{
			s[tag->size] = (tag->nbr % 10) + '0';
			tag->nbr /= 10;
		}
	return (s);
}

void	digits_size(t_tag *tag)
{
	long long	n;
	int			div;

	n = tag->nbr;
	tag->size = 1;
	div = 10;
	if (*tag->fmt == 'x' || *tag->fmt == 'X' || *tag->fmt == 'p')
	{
		n = tag->pnbr;
		div = 16;
	}
	if (n < 0)
		while (n <= -div)
		{
			n /= -div;
			tag->size++;
		}
	if (n >= 0)
		while (n >= div)
		{
			n /= div;
			tag->size++;
		}
}

void	digits_size_str(t_tag *tag)
{
	char	*s;

	s = tag->str;
	if (s == NULL)
	{
		tag->str = "(null)";
		tag->size = 6;
		return ;
	}
	while (*s != '\0')
	{
		s++;
		tag->size++;
	}
}

void	sort_width_prec(t_tag *tag)
{
	if (*tag->fmt == '.')
		dot_check(tag);
	else if (*tag->fmt == '*')
	{
		if (tag->dot == 1)
			tag->prec = va_arg(tag->ap, int);
		else
			tag->width = va_arg(tag->ap, int);
		if (tag->width < 0)
		{
			tag->minus = 1;
			tag->width *= -1;
		}
		else if (tag->prec < 0)
			tag->dot = 0;
	}
	else if (ft_isdigit(*tag->fmt) != 0)
	{
		if (tag->dot == 1)
			tag->prec = (tag->prec * 10) + *tag->fmt - '0';
		else
			tag->width = (tag->width * 10) + *tag->fmt - '0';
	}
}

void	check_tag(t_tag *tag)
{
	if (*tag->fmt == '-')
		tag->minus = 1;
	else if (*tag->fmt == '0' && tag->width == 0 && tag->dot == 0)
		tag->zero = 1;
	else if (*tag->fmt == '*' || *tag->fmt == '.' || ft_isdigit(*tag->fmt))
		sort_width_prec(tag);
	else if (*tag->fmt == ' ')
		tag->res += ft_putchar(' ');
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 08:20:49 by jaehpark          #+#    #+#             */
/*   Updated: 2021/02/26 15:02:02 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_sign(t_tag *tag)
{
	char	*s;
	int		div;
	int		upp;

	if (!(s = (char *)malloc(sizeof(char) * (tag->size + 1))))
		return (NULL);
	s[tag->size] = '\0';
	div = 10;
	upp = 0;
	if (*tag->fmt == 'x' || *tag->fmt == 'X')
	{
		div = 16;
		upp = 7;
		if (*tag->fmt == 'x')
			upp += 32;
	}
	if (tag->nbr < 0)
		while (tag->size-- > 0)
		{
			if ((tag->nbr % div) * -1 >= 10)
					s[tag->size] = ((tag->nbr % div) * -1) + '0' + upp;
			else
				s[tag->size] = ((tag->nbr % div) * -1) + '0';
			tag->nbr /= div;
		}
	if (tag->nbr >= 0)
		while (tag->size-- > 0)
		{
			if (tag->nbr % div >= 10)
				s[tag->size] = (tag->nbr % div) + '0' + upp;
			else
				s[tag->size] = (tag->nbr % div) + '0';
			tag->nbr /= div;
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
	if (*tag->fmt == 'x' || *tag->fmt == 'X')
		div = 16;
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
	while (*tag->str != '\0')
	{
		tag->str++;
		tag->size++;
	}
}

void	sort_width_prec(t_tag *tag)
{
	if (*tag->fmt == '.')
		tag->dot = 1;
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
	else if (*tag->fmt == '0' && tag->width == 0)
		tag->zero = 1;
	else if (*tag->fmt == '*' || *tag->fmt == '.' || ft_isdigit(*tag->fmt))
		sort_width_prec(tag);
}

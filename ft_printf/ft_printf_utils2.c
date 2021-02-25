/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 08:20:49 by jaehpark          #+#    #+#             */
/*   Updated: 2021/02/26 08:20:52 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_sign(f_tag *tag)
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

void	digits_size(f_tag *tag)
{
	int	n;

	n = tag->nbr;
	tag->size = 1;
	if (n < 0)
		while (n <= -10)
		{
			n /= -10;
			tag->size++;
		}
	if (n >= 0)
		while (n >= 10)
		{
			n /= 10;
			tag->size++;
		}
}

void	sort_width_prec(f_tag *tag)
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

void	check_tag(f_tag *tag)
{
	if (*tag->fmt == '-')
		tag->minus = 1;
	else if (*tag->fmt == '0' && tag->width == 0)
		tag->zero = 1;
	else if (*tag->fmt == '*' || *tag->fmt == '.' || ft_isdigit(*tag->fmt))
		sort_width_prec(tag);
}

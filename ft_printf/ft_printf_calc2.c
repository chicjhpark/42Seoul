/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_calc_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 04:53:10 by jaehpark          #+#    #+#             */
/*   Updated: 2021/02/28 23:35:43 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_xtoa_sign(t_tag *tag)
{
	char	*s;
	int		upp;
	int		sign;

	if (!(s = (char *)malloc(sizeof(char) * (tag->size + 1))))
		return (NULL);
	s[tag->size] = '\0';
	upp = 7;
	sign = 1;
	if (tag->pnbr < 0)
		sign = -1;
	if (*tag->fmt == 'x' || *tag->fmt == 'p')
		upp += 32;
	while (tag->size-- > 0)
	{
		if ((tag->pnbr % 16) * sign >= 10)
			s[tag->size] = ((tag->pnbr % 16) * sign) + '0' + upp;
		else
			s[tag->size] = ((tag->pnbr % 16) * sign) + '0';
		tag->pnbr /= 16;
	}
	return (s);
}

void	dot_check(t_tag *tag)
{
	tag->dot = 1;
	tag->prec = 0;
}

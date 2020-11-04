/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 21:49:29 by jaehpark          #+#    #+#             */
/*   Updated: 2020/11/03 03:13:19 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*uc_dst;
	const unsigned char	*uc_src;
	size_t				i;

	uc_dst = dst;
	uc_src = src;
	i = 0;
	while (i < n)
	{
		uc_dst[i] = uc_src[i];
		i++;
	}
	return (dst);
}

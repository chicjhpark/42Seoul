/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 22:12:09 by jaehpark          #+#    #+#             */
/*   Updated: 2020/11/03 10:32:56 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
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
		if (uc_src[i] == c)
			return (&dst[i + 1]);
		i++;
	}
	return (NULL);
}

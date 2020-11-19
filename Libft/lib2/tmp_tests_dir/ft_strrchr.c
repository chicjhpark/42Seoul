/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 11:34:47 by jaehpark          #+#    #+#             */
/*   Updated: 2020/11/18 15:13:25 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	end;

	end = ft_strlen(s);
	if (!c)
		return ((char *)&s[end]);
	while (end--)
		if (s[end] == c)
			return ((char *)&s[end]);
	return (NULL);
}

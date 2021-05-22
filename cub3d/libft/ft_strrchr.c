/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 11:34:47 by jaehpark          #+#    #+#             */
/*   Updated: 2020/11/24 01:16:47 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	cc;
	int		end;

	cc = (char)c;
	end = ft_strlen(s);
	if (cc == '\0')
		return ((char *)&s[end]);
	while (end--)
		if (s[end] == cc)
			return ((char *)&s[end]);
	return (NULL);
}

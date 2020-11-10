/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 13:00:42 by jaehpark          #+#    #+#             */
/*   Updated: 2020/11/10 16:49:18 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	l1;
	size_t	l2;

	l1 = strlen(s1);
	l2 = strlen(s2);
	if (!(s3 = (char *)malloc(sizeof(char) * (l1 + l2 + 1))))
		return (NULL);
	l1 = 0;
	while (s1[l1])
	{
		s3[l1] = s1[l1];
		l1++;
	}
	l2 = 0;
	while (s2[l2])
	{
		s3[l1 + l2] = s2[l2];
		l2++;
	}
	s3[l1 + l2] = 0;
	return (s3);
}

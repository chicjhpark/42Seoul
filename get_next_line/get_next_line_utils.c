/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 00:28:59 by jaehpark          #+#    #+#             */
/*   Updated: 2020/12/30 01:53:25 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_strlen(char *s)
{
	ssize_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*s2;
	ssize_t	len;
	ssize_t	i;

	len = ft_strlen(s1);
	if (!(s2 = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	ssize_t	l1;
	ssize_t	l2;
	ssize_t	i;
	ssize_t	j;

	if (s1 == NULL)
		return (ft_strdup(s2));
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (!(s3 = (char *)malloc(sizeof(char) * (l1 + l2 + 1))))
		return (NULL);
	i = -1;
	while (++i < l1)
		s3[i] = s1[i];
	free(s1);
	j = -1;
	while (++j < l2)
		s3[i + j] = s2[j];
	s3[i + j] = '\0';
	return (s3);
}

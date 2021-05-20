/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 00:28:59 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/19 07:11:37 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

ssize_t	gnl_strlen(char *s)
{
	ssize_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*gnl_strdup(char *s1)
{
	char	*s2;
	ssize_t	len;
	ssize_t	i;

	len = gnl_strlen(s1);
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

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*s3;
	ssize_t	l1;
	ssize_t	l2;
	ssize_t	i;
	ssize_t	j;

	if (s1 == NULL)
		return (gnl_strdup(s2));
	l1 = gnl_strlen(s1);
	l2 = gnl_strlen(s2);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 16:08:29 by jaehpark          #+#    #+#             */
/*   Updated: 2020/11/12 18:46:49 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_str_count(char **s2, char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	s2 = (char **)malloc(sizeof(char *) * count + 1);
	return (s2);
}

static void	ft_free(char **s2, size_t j)
{
	size_t	i;

	i = 0;
	while (i <= j)
	{
		free(s2[i]);
		i++;
	}
	free(s2);
}

static char	**ft_chr_count(char **s2, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	j = 0;
	count = 0;
	while (s[i])
	{
		count = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			count++;
			i++;
		}
		if (!(s2[j] = (char *)malloc(sizeof(char) * count + 1)))
		{
			ft_free(s2, j - 1);
			return (NULL);
		}
		j++;
	}
	return (s2);
}

static char	**ft_strcpy(char **s2, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (s[i])
	{
		k = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			s2[j][k] = s[i];
			i++;
			k++;
		}
		s2[j][k] = '\0';
		j++;
	}
	s2[j][0] = '\0';
	return (s2);
}

char		**ft_split(char const *s, char c)
{
	char	**s2;

	if (!s)
		return (NULL);
	ft_str_count(s2, s, c);
	ft_chr_count(s2, s, c);
	ft_strcpy(s2, s, c);
	return (s2);
}

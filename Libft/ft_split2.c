/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 20:03:30 by jaehpark          #+#    #+#             */
/*   Updated: 2020/11/11 16:26:41 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


static size_t	ft_str_count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c && i != 0 && s[i - 1] != c)
			count++;
		i++;
	}
	return (count);
}

static size_t	ft_chr_count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
			count++;
		i++;
	}
	return (count);
}

char			**ft_split(char const *s, char c)
{
	char	**s2;
	char	*new;
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	temp;

	if (!s)
		return (NULL);
	len1 = ft_str_count(s, c);
	if (!(s2 == (char **)malloc(sizeof(char *) * (len1 + 1))))
		return (NULL);
	len2 = ft_chr_count(s, c);
	i = 0;
	while (i < len2)
	{
		if (!(s2[i] == (char *)malloc(sizeof(char) * (len2 + 1))))
			return (NULL);
		i++;
	}
	temp = i;
	i = 0;
	j = 0;
	k = 0;
	while (s[k])
	{
		if (s[j] != c)
			s2[i][j] = s[k];
		else
		{
			i++;
			j = 0;
		}
		j++;
		k++;
	}
	s2[i][j] = '\0';
	while (temp)
	{
		free(s2[temp]);
		temp--;
	}
	return (s2);
}

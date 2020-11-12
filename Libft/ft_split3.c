/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 14:07:55 by jaehpark          #+#    #+#             */
/*   Updated: 2020/11/12 18:35:12 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


static size_t	ft_str_count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	if (!c)
		return (1);
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (!s[i + 1] || (s[i] == c && s[i + 1] != c))
			count++;
		i++;
	}
	return (count);
}

static void		ft_free(char **s2, size_t j)
{
	size_t	i;

	i = 0;
	while (i <= j)
	{
		free(s2[j]);
		i++;
	}
}

static char		**ft_chr_count(char const *s, char c, char **s2)
{
	size_t	count;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
			count++;
		else if ((s[i] == c && i != 0 && s[i + 1] != c) || !s[i + 1])
		{
			if (!(s2[j] = (char *)malloc(sizeof(char) * count)))
			{
				ft_free(s2, j - 1);
				free(s2);
				return (NULL);
			}
			count = 0;
			j++;
		}
		i++;
	}
	return (s2);
}

static char		**ft_split_chr(char const *s, char c, char **s2)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[k] == c)
		k++;
	while (s[k])
	{
		if (s[k] != c)
		{
			s2[i][j] = s[k];
			j++;
		}
		else if ((s[k] == c && k != 0 && s[k + 1] != c) || !s[k + 1])
		{
			s2[i][j] = '\0';
			j = 0;
			i++;
		}
		k++;
	}
	s2[i][j] = '\0';
	return (s2);
}

char			**ft_split(char const *s, char c)
{
	char	**s2;
	size_t	count;

	if (!s)
		return (NULL);
	count = ft_str_count(s, c);
	if (!(s2 = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	ft_chr_count(s, c, s2);
	ft_split_chr(s, c, s2);
	return (s2);
}

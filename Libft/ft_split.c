/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 14:07:55 by jaehpark          #+#    #+#             */
/*   Updated: 2020/11/11 15:31:55 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static size_t	ft_str_count(char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c && i != 0 && s[i + 1] != c)
			count++;
		i++;
	}
	return (count);
}

static char		**ft_chr_count(char *s, char c, char **s2)
{
	size_t	count;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		count = 0;
		if (s[i] != c)
			count++;
		else if (s[i] == c && i != 0 && s[i + 1] != c)
		{
			if (!(s2[j] = (char *)malloc(sizeof(char) * count)))
				return (NULL);
			j++;
		}
		i++;
	}
	return (s2);
}

static void		ft_free(char **s2);
{
	size_t	i;

	i = 0;
	while (s2[i])
	{
		free(s2[i]);
		i++;
	}
}

char			**ft_split(char *s, char c)
{
	char	**s2;
	size_t	count;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s)
		return (NULL);
	count = ft_str_count(s, c);
	if (!(s2 = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	i = 0;
	k = 0;
	while (s[k])
	{
		j = 0;
		if (s[k] != c)
		{
			s2[i][j] = s[k];
			j++;
		}
		else
			i++;
		k++;
	}
	s2[i][j] = 0;
	ft_free(s2);
	return (s2);
}

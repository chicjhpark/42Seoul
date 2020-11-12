/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 21:13:26 by jaehpark          #+#    #+#             */
/*   Updated: 2020/11/12 23:51:33 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_count(int n)
{
	size_t	count;

	count = 0;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static size_t	ft_square(size_t count)
{
	size_t	square;

	square = 1;
	while (count-- > 1)
		square = square * 10;
	return (square);
}

char			*ft_itoa(int n)
{
	char	*temp;
	size_t	count;
	size_t	square;
	size_t	i;

	count = ft_count(n);
	if (!(temp = (char *)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	square = ft_square(count);
	i = 0;
	while (count--)
	{
		temp[i] = (n / square) + '0';
		n = n % square;
		square = square / 10;
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 21:13:26 by jaehpark          #+#    #+#             */
/*   Updated: 2020/11/14 01:08:42 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_count(int n)
{
	size_t	count;

	count = 0;
	if (n < 0)
		count++;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char		*ft_conver(int n, char *temp, size_t count, size_t sign)
{
	int		square;
	size_t	count2;
	size_t	i;

	square = 1;
	count2 = count;
	while (--count)
		square = square * 10;
	i = 0;
	if (sign)
	{
		temp[i] = '-';
		i++;
	}
	while (count2--)
	{
		temp[i] = (n / square) + '0';
		n = n % square;
		square = square / 10;
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char			*ft_itoa(int n)
{
	char	*temp;
	size_t	count;
	size_t	sign;

	sign = 0;
	if (n < 0)
	{
		n = n * -1;
		sign = 1;
	}
	count = ft_count(n);
	if (!(temp = (char *)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	ft_conver(n, temp, count, sign);
	return (temp);
}

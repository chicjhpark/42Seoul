/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 01:22:19 by jaehpark          #+#    #+#             */
/*   Updated: 2020/11/15 03:03:10 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_convert(int n, char *str, size_t count)
{
	if (n < 0)
	{
		str[0] = '-';
		count++;
	}
	str[count] = '\0';
	if (n < 0)
		while (--count)
		{
			str[count] = ((n % 10) * -1) + '0';
			n = n / 10;
		}
	else
	{
		while (count--)
		{
			str[count] = (n % 10) + '0';
			n = n / 10;
		}
	}
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		temp;
	size_t	count;
	size_t	sign;

	if (!n)
		return (NULL);
	sign = 0;
	if (n <= 0)
		sign = 1;
	temp = n;
	count = 0;
	while (temp)
	{
		temp = temp / 10;
		count++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (sign + count + 1))))
		return (NULL);
	str = ft_convert(n, str, count);
	return (str);
}

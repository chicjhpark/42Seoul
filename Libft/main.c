/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:38:59 by jaehpark          #+#    #+#             */
/*   Updated: 2020/11/12 21:04:25 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int		main(void)
{
	const char	s[100] = "   I'm optimus prim    e  s    ";
	char		**c;
	size_t		i;

	i = 0;
	c = ft_split(s, 0);
	while (c[i])
	{
		printf("%s\n", c[i]);
		i++;
	}
	return (0);
}

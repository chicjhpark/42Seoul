/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:38:59 by jaehpark          #+#    #+#             */
/*   Updated: 2020/11/12 19:27:13 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int		main(void)
{
	const char	s[100] = "   I'm optimus prime s";
	char		**c;
	size_t		i;

	i = 0;
	c = ft_split(s, ' ');
	while (c[i])
	{
		printf("%s\n", c[i]);
		i++;
	}
	return (0);
}

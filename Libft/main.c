/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:38:59 by jaehpark          #+#    #+#             */
/*   Updated: 2020/11/12 18:46:54 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int		main(void)
{
	char	a[100] = "    I'm optimus p prime";
	char	**s;
	size_t	i;

	i = 0;
	s = ft_split(a , 100);
	while (s[i])
	{
		printf("%s\n", s[i]);
		i++;
	}
	return (0);
}

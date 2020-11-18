/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:38:59 by jaehpark          #+#    #+#             */
/*   Updated: 2020/11/18 17:33:17 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		main(void)
{
	char	s1[10] = "a";
	char	s2[10] = "a";
//	size_t	s11;
	size_t	s22;

	//s11 = strlcat(s1, "lorem", 15);
	s22 = ft_strlcat(s2, "lorem", 15);
	printf("%s\n", s1);
	printf("%s\n", s2);
//	printf("%zu\n", s11);
	printf("%zu\n", s22);
	return (0);
}

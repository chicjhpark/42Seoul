/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:38:59 by jaehpark          #+#    #+#             */
/*   Updated: 2020/11/08 15:14:48 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int		main(void)
{
	char	s1[] = "cbhaelloba";
	char	set[] = "abc";
	char	*result;

	result = ft_strtrim("cbhaelloba", "abc");
	printf("%s\n", result);
	return (0);
}

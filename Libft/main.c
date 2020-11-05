/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark </var/mail/jaehpark>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 08:14:24 by jaehpark          #+#    #+#             */
/*   Updated: 2020/11/04 12:12:14 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int		main(void)
{
	char	*i;

	i = ft_substr("i am optimus prime", 5, 20);
	write(0, i, 20);
	write(0, "\n", 1);
	puts(i);
	printf("%s\n", i); 
	return (0);
}

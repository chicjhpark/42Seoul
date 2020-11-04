/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 14:45:38 by jaehpark          #+#    #+#             */
/*   Updated: 2020/11/03 14:58:52 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*uc_s1;
	const unsigned char	*uc_s2;
	size_t				i;

	uc_s1 = s1;
	uc_s2 = s2;
	i = 0;
	while (i < n)
	{
		if ((uc_s1[i] > uc_s2[i]) || (uc_s1[i] && !uc_s2[i]))
			return (1);
		else if ((uc_s1[i] < uc_s2[i]) || (!uc_s1[i] && uc_s2[i]))
			return (-1);
		i++;
	}
	return (0);
}

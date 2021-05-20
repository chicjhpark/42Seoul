/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 23:09:29 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/19 00:24:26 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    free_array(char **arr)
{
    int     i;

    i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

int		check_extension(const char *s, const char *ext)
{
	int		i;
	int		j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i + j] == ext[j] && s[i] && ext[j])
			j++;
		if (s[i + j] == '\0' && ext[j] == '\0')
			return (TRUE);
		i++;
	}
	return (FALSE);
}
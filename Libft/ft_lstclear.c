/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark </var/mail/jaehpark>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 22:27:06 by jaehpark          #+#    #+#             */
/*   Updated: 2020/11/19 23:58:51 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;
	size_t	i;

	i = 0;
	while (lst[i])
	{
		del(lst[i]->content);
		free(lst[i]);
		next = lst[i]->next;
		lst[i] = next;
	}
	lst[i] = NULL;
}

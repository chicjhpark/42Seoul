/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 11:39:20 by jaehpark          #+#    #+#             */
/*   Updated: 2020/12/12 18:31:19 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int	    get_next_line(int fd, char **line);
ssize_t ft_strlen(char *s);
char    *ft_strdup(char *s1);
char    *ft_strjoin(char *s1, char *s2);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 11:39:20 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/19 06:47:01 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define OPEN_MAX 256
# define BUFFER_SIZE 256

int		    get_next_line(int fd, char **line);
ssize_t	    gnl_strlen(char *s);
char	    *gnl_strdup(char *s1);
char	    *gnl_strjoin(char *s1, char *s2);

#endif

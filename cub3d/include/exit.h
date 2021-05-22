/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 21:09:21 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/22 21:05:41 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H
# define EXIT_H

# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include "init.h"

void	    free_set(t_set *set);
void	    exit_msg(const char *msg);
int		    exit_success(t_set *set);
void        free_array(char **arr);



#endif
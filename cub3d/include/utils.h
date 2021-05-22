/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 21:01:44 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/22 20:08:45 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cub3d.h"
# include "init.h"

void	    free_set(t_set *set);
void	    exit_msg(const char *msg);
int		    exit_success(t_set *set);
int		    check_extension(const char *s, const char *ext);
int		    check_num(char *num);
int	        ft_strcmp(const char *s1, const char *s2);
void	    clear_frame(t_img *img, int color);

#endif
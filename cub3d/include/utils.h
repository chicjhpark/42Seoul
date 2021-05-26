/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 21:01:44 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/26 23:21:10 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cub3d.h"

void		free_set(t_set *set);
void		exit_msg(const char *msg);
int			exit_success(t_set *set);
int			check_extension(const char *s, const char *ext);
int			check_num(char *num);
int			ft_strcmp(const char *s1, const char *s2);
void		clear_frame(t_img *img, int color);
void		exit_msg(const char *msg);
int			exit_success(t_set *set);
void		free_array(char **arr);
void		free_set(t_set *set);
void			save_bmp(int x, int y);
void			generate_image(unsigned char *image, int y, int x, char *file_name);
unsigned char	*create_file_header(int y, int stride);
unsigned char	*create_info_header(int y, int x);

#endif

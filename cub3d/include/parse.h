/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 20:48:16 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/24 21:03:30 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "cub3d.h"

void		parse_content(t_set *set, int fd);
void		parse_map(t_set *set, int fd);
void		check_map(t_set *set, char **map);
void		parse_resolution(t_set *set, char **data);
int			check_rgb(const int rgb);
void		parse_rgb(t_set *set, char **rgb, const char type);
void		parse_color(t_set *set, char **data);
void		parse_texture(t_set *set, char **data);
int			check_dir(t_set *set, char map_x, char *dir);

#endif

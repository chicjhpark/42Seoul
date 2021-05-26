/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:18:13 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/26 19:33:38 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPDATE_H
# define UPDATE_H

# include "cub3d.h"

void	update(t_set *set);
void	update_player(t_set *set, t_player *player);
void	update_ray(t_set *set, t_ray *ray, float ang, int i);
void	select_closest_distance(t_set *set, t_data *data, float ang, int i);
void	vert_intersection(t_set *set, t_data *data);
void	init_vert_data(t_set *set, t_player *player, t_data *data, float ang);
void	horiz_intersection(t_set *set, t_data *data);
void	init_horiz_data(t_set *set, t_player *player, t_data *data, float ang);
void	init_data(t_data *data, float ang);
float	distance_between_point(float x1, float y1, float x2, float y2);
float	normalize_ang(float ang);
int		check_collision(t_set *set, float x, float y);

#endif

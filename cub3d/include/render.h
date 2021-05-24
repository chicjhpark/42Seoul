/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:28:23 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/24 22:20:13 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include <math.h>
# include <float.h>
# include "color.h"
# include "init.h"

# define F_MAX			FLT_MAX
# define F_MIN			FLT_MIN

void	render_player(t_img *img, t_player *player);
void	render_player_line(t_img *img, t_player *player);
void	render_map(t_set *set);
void	render_grid(t_set *set, int x1, int y1, int color);
void	render_ray(t_set *set, t_img *img, t_player *player, t_ray *ray);
void	select_closest_distance(t_player *player, t_ray *ray,
								t_data *data, float ang, int i);
void	vert_intersection(t_set *set, t_data *data);
void	init_vert_data(t_player *player, t_data *data, float ang);
void	horiz_intersection(t_set *set, t_data *data);
void	init_horiz_data(t_player *player, t_data *data, float ang);
void	init_data(t_data *data, float ang);
float	distance_between_point(float x1, float y1, float x2, float y2);
float	normalize_ang(float ang);
int		check_collision(t_set *set, float x, float y);
void	render_wall(t_set *set, t_img *img, t_player player, t_ray *ray);
void	render_sprite(t_set *set, t_player *player, t_ray *ray, t_sprite *sprite_tex);
void	render_map_sprite(t_set *set, t_img *img, t_sprite *sprite_tex);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:02:33 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/23 00:16:59 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "init.h"

typedef struct		s_data
{
	int		down;
	int		up;
	int		right;
	int		left;
	float	x_block;
	float	y_block;
	float	x_step;
	float	y_step;
	int		h_hit;
	float	h_hit_x;
	float	h_hit_y;
	char	h_content;
	float	h_touch_x;
	float	h_touch_y;
	float	h_distance;
	int		v_hit;
	float	v_hit_x;
	float	v_hit_y;
	char	v_content;
	float	v_touch_x;
	float	v_touch_y;
	float	v_distance;
}					t_data;

typedef	struct		s_ray
{
	float		ang;
	float		hit_x;
	float		hit_y;
	float		distance;
	int			hit_vert;
	int			up;
	int			down;
	int			left;
	int			right;
	int			hit_content;
	t_data		data;
}					t_ray;

#endif
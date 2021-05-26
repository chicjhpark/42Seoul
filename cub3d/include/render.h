/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:28:23 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/26 20:35:25 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "cub3d.h"

# define F_MAX			FLT_MAX
# define F_MIN			FLT_MIN

void	render_player(t_img *img, t_player *player);
void	render_player_line(t_img *img, t_player *player);
void	render_map(t_set *set);
void	render_grid(t_set *set, int x1, int y1, int color);
void	render_ray(t_set *set, t_img *img, t_player *player, t_ray *ray);
void	render_wall(t_set *set, t_img *img, t_ray *ray, t_wall *wall);
void	render_sprites(t_set *set, t_player *player, t_sprite *sprites);
void	render_map_sprites(t_set *set, t_img *img, t_sprite *sprites);

#endif

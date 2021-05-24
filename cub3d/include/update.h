/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:18:13 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/24 20:45:35 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPDATE_H
# define UPDATE_H

# include "cub3d.h"
# include "init.h"

void	update(t_set *set);
void	update_player(t_set *set, t_player *player);
void	update_ray(t_set *set, t_player *player, t_ray *ray, float ang, int i);

#endif

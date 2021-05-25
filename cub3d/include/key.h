/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 18:51:04 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/25 16:22:19 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
# define KEY_H

# include "cub3d.h"

# define KEY_PRESS				2
# define KEY_RELEASE			3
# define WINDOW_CLOSE_BUTTON	17

# define KEY_ESC				53
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2
# define KEY_W                  13
# define KEY_LEFT				123
# define KEY_RIGHT				124
# define KEY_BACK				125
# define KEY_FRONT				126

int		key_press_hook(int key, t_set *set);
int		key_release_hook(int key, t_set *set);
int		close_hook(t_set *set);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:24:58 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/25 17:18:39 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key.h"

int		close_hook(t_set *set)
{
	return (exit_success(set));
}

int		key_press_hook(int key, t_set *set)
{
	if (key == KEY_ESC)
		close_hook(set);
	else if (key == KEY_W)
		set->player.move_dir = 1;
	else if (key == KEY_A)
		set->player.move_side = -1;
	else if (key == KEY_S)
		set->player.move_dir = -1;
	else if (key == KEY_D)
		set->player.move_side = 1;
	else if (key == KEY_LEFT)
		set->player.rot_dir = -1;
	else if (key == KEY_RIGHT)
		set->player.rot_dir = 1;
	return (TRUE);
}

int		key_release_hook(int key, t_set *set)
{
	if (key == KEY_W)
		set->player.move_dir = 0;
	else if (key == KEY_A)
		set->player.move_side = 0;
	else if (key == KEY_S)
		set->player.move_dir = 0;
	else if (key == KEY_D)
		set->player.move_side = 0;
	else if (key == KEY_LEFT)
		set->player.rot_dir = 0;
	else if (key == KEY_RIGHT)
		set->player.rot_dir = 0;
	return (TRUE);
}

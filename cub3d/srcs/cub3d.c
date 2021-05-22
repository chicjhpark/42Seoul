/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 20:24:28 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/23 00:44:57 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		render_loop(t_set *set)
{
	update(set);
	mlx_clear_window(set->mlx, set->win);
	clear_frame(&set->img, BLACK);
	render_walls(&set->img, set->player, set->ray, set->wall_tex);
	mlx_put_image_to_window(set->mlx, set->win, set->img.img, 0, 0);
	render_map(set);
	render_ray(set, &set->img, &set->player, set->ray);
	render_player(&set->img, &set->player);
	mlx_put_image_to_window(set->mlx, set->win, set->img.img, 0, 0);
	return TRUE;
}

int		main(int argc, char **argv)
{
	t_set	set;
	int		fd;
	
	if (argc < 2)
		exit_msg("Missing file.");
	if (check_extension(argv[1], ".cub") == FALSE)
		exit_msg("Invalid extension.");
	if ((fd = open(argv[1], O_RDONLY)) == FALSE)
		exit_msg("Failed opening.");
	init_default(&set);
	parse_content(&set, fd);
	init_set(&set);
	//if (argc > 2 && ft_strcmp(argv[2], "--save") == TRUE)
	//	save_bmp(&set);
	mlx_hook(set.win, KEY_PRESS, 0, &key_press_hook, &set);
	mlx_hook(set.win, KEY_RELEASE, 0, &key_release_hook, &set);
	mlx_hook(set.win, WINDOW_CLOSE_BUTTON, 0, &close_hook, &set);
	mlx_loop_hook(set.mlx, render_loop, &set);
	mlx_loop(set.mlx);
	return (exit_success(&set));
}
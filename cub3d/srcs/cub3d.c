/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 20:24:28 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/27 01:12:41 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		render_loop(t_set *set)
{
	update(set);
	mlx_clear_window(set->mlx, set->win);
	render_wall(set, &set->img, set->ray, &set->wall);
	render_sprites(set, &set->player, set->sprites);
	mlx_put_image_to_window(set->mlx, set->win, set->img.img, 0, 0);
	return (TRUE);
}

int		main(int argc, char **argv)
{
	t_set	set;
	int		fd;

	if (argc < 2 || argc > 3)
		exit_msg("Missing file or Invalid argument.");
	if (check_extension(argv[1], ".cub") == FALSE)
		exit_msg("Invalid extension.");
	if ((fd = open(argv[1], O_RDONLY)) == FALSE)
		exit_msg("Failed opening.");
	init_default(&set);
	parse_content(&set, fd);
	init_set(&set);
	if (argc > 2)
	{
		if (ft_strcmp(argv[2], "--save") == TRUE)
			save_bmp(&set);
		else
			exit_msg("Invalid argument.");
	}
	mlx_hook(set.win, KEY_PRESS, 0, &key_press_hook, &set);
	mlx_hook(set.win, KEY_RELEASE, 0, &key_release_hook, &set);
	mlx_hook(set.win, WINDOW_CLOSE_BUTTON, 0, &close_hook, &set);
	mlx_loop_hook(set.mlx, render_loop, &set);
	mlx_loop(set.mlx);
	return (TRUE);
}

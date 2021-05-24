/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 22:18:33 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/24 21:01:46 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include <math.h>
# include <libft.h>
# include "player.h"
# include "ray.h"

# define TRUE			0
# define FALSE			-1
# define ERROR			-2

# define GRID_SIZE		64
# define TEX_WIDTH		64
# define TEX_HEIGHT		64

# define MINIMAP		0.2

typedef	struct		s_img
{
	void		*img;
	int			x;
	int			y;
	int			*data;
	int			bpp;
	int			size_l;
	int			endian;
}					t_img;

typedef struct		s_color
{
	int		r;
	int		g;
	int		b;
}					t_color;

typedef struct		s_sprite
{
	float		x;
	float		y;
	float		distance;
	float		ang;
	int			visible;
	int			tex;
}					t_sprite;

typedef struct		s_set
{
	void			*mlx;
	int				win_x;
	int				win_y;
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	char			*sprite;
	t_color			floor;
	t_color			ceil;
	int				type[8];
	char			**map;
	int				map_x;
	int				map_y;
	char			dir;
	void			*win;
	t_img			img;
	t_player		player;
	int				rays;
	t_ray			*ray;
	int				*tex[5];
	int				sprite_num;
	t_sprite		*sprite_tex;
	int				tex_x;
	int				tex_y;
	int				grid_x;
	int				grid_y;
	int				fov;
}					t_set;

void		init_default(t_set *set);
void		init_win(t_set *set);
void		init_img(t_set *set, t_img *img);
void		init_ray(t_set *set, t_ray **ray);
void		init_set(t_set *set);
void		init_tex(t_set *set);
void	    free_set(t_set *set);
void	    exit_msg(const char *msg);
int		    exit_success(t_set *set);
void        free_array(char **arr);

#endif

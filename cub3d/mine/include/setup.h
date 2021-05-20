/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 22:18:33 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/20 02:05:46 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP_H
# define SETUP_H

# include "cub3d.h"
# include "color.h"

# define TRUE			0
# define FALSE			-1
# define ERROR			-2

# define GRID_SIZE		64

# define MINIMAP        0.2

# define F_MAX			FLT_MAX // WARNING
# define F_MIN			FLT_MIN // WARNING

# define PROJ_DIST		((WIDTH / 2) / tan(FOV / 2))
# define FOV			60 * (M_PI / 180)

# define u_int			unsigned int

typedef struct		s_map
{
	void			*content;
	struct s_map	*next;
}					t_map;

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
	void			*win;
}					t_set;

#endif

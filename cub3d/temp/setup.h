/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehpark <jaehpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 18:51:30 by jaehpark          #+#    #+#             */
/*   Updated: 2021/05/17 01:35:43 by jaehpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALUE_H
# define VALUE_H

# define TRUE					1
# define FALSE					0

# define ROW					11
# define COL					15
# define GRID_SIZE				64

# define MINIMAP                0.2

# define WIDTH					COL * GRID_SIZE
# define HEIGHT					ROW * GRID_SIZE

# define TEX_WIDTH              64
# define TEX_HEIGHT             64

# define TWO_PI                 M_PI * 2;
# define rad(d)                 (d) * (M_PI / 180)
# define deg(d)					(d) * (180 / M_PI)

# define F_MAX					FLT_MAX // WARNING
# define F_MIN					FLT_MIN // WARNING

# define PROJ_DIST              ((WIDTH / 2) / tan(FOV / 2))
# define FOV					60 * (M_PI / 180)

# define RAYS					WIDTH

#endif

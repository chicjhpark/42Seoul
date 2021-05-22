/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   color.h											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jaehpark <jaehpark@student.42seoul.kr>	 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/05/16 18:50:25 by jaehpark		  #+#	#+#			 */
/*   Updated: 2021/05/16 21:25:50 by jaehpark		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "cub3d.h"

# define BLACK				0xAA000000
# define WHITE				0xAAFFFFFF
# define RED				0xAAFF0000
# define GREEN				0xAA0FF000
# define BLUE				0xAA0000FF
# define YELLOW				0xAAFFFF00
# define GRASS				0xAA008000
# define SKY				0xAA87CEEB
# define MIDNIGHT			0xAA191970
# define DIMGRAY			0xAA696969
# define SHADE				0x01000000

# define BLOCK_COLOR		WHITE
# define GRID_COLOR			BLACK
# define GRID_LINE_COLOR	GREEN
# define PLAYER_COLOR		YELLOW
# define RAY_COLOR			RED
# define FLOOR_COLOR		GRASS
# define CEILING_COLOR		SKY

#endif

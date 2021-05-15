#ifndef CUB3D_H
# define CUB3D_H

# include "./mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <stdint.h>
# include <float.h> // WARNING !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

# define TRUE					1
# define FALSE					0

# define TWO_PI					M_PI * 2;

# define rad(d)					(d) * (M_PI / 180)
# define deg(d)					(d) * (180 / M_PI)

# define F_MAX					FLT_MAX // WARNING !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
# define F_MIN					FLT_MIN // WARNING !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

# define MINIMAP_SCALE_SIZE		0.2
# define M						MINIMAP_SCALE_SIZE

# define ROW					11
# define COL					15
# define GRID_SIZE				64

# define WIDTH					COL * GRID_SIZE // 960
# define HEIGHT					ROW * GRID_SIZE // 704

# define TEX_WIDTH              64
# define TEX_HEIGHT             64

# define FOV					60 * (M_PI / 180)

# define RAYS					WIDTH

# define BLACK                  0xAA000000
# define WHITE                  0xAAFFFFFF
# define RED                    0xAAFF0000
# define GREEN                  0xAA0FF000
# define BLUE                   0xAA0000FF
# define YELLOW                 0xAAFFFF00
# define GRASS                  0x00008000
# define SKY                    0x0087CEEB
# define MIDNIGHT               0x00191970
# define DIMGRAY                0x00696969

# define BLOCK_COLOR            WHITE
# define GRID_COLOR             BLACK
# define GRID_LINE_COLOR        GREEN
# define PLAYER_COLOR           YELLOW
# define RAY_COLOR              RED
# define FLOOR_COLOR            GRASS
# define CEILING_COLOR          SKY

# define KEY_PRESS				2
# define KEY_RELEASE			3
# define WINDOW_CLOSE_BUTTON	17

# define KEY_ESC				53

# define KEY_A					0
# define KEY_S					1
# define KEY_D					2
# define KEY_W					13
# define KEY_LEFT				123
# define KEY_RIGHT				124
# define KEY_BACK				125
# define KEY_FRONT				126

#endif

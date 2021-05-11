#ifndef CUB3D_H
# define CUB3D_H

# include "./mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

# define TRUE					0
# define FALSE					1

# define TWO_PI					6.28318530717958647692

# define MINIMAP_SCALE_SIZE		1.0
# define M						MINIMAP_SCALE_SIZE

# define ROW					11
# define COL					15
# define GRID_SIZE				64

# define WIDTH					COL * GRID_SIZE // 960
# define HEIGHT					ROW * GRID_SIZE // 704

# define FOV					60 * (M_PI / 180)

# define FPS					30
# define FRAME_TIME				1000 / FPS

# define RAYS					WIDTH

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

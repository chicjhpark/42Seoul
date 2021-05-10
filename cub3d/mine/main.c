#include "cub3d.h"

typedef struct		s_img
{
	void		*img;
	int			*data;
	int			bpp;
	int			size_l;
	int			endian;
}					t_img;

typedef struct		s_player
{
	float		x;
	float		y;
	float		size;
	float		rot_dir;
	float		move_dir;
	float		rot_ang;
	float		move_spd;
	float		rot_spd;
}					t_player;

typedef struct		s_set
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_player	player;
	int			map[ROW][COL];
}					t_set;

void	get_map(t_set *set)
{
	int		map[ROW][COL] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
		{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	memcpy(set->map, map, sizeof(int) * ROW * COL);
}

void	init_win(t_set *set)
{
	set->mlx = mlx_init();
	set->win = mlx_new_window(set->mlx, WIDTH, HEIGHT, "Cub3D");
}

void	init_img(t_set *set, t_img *img)
{
	img->img = mlx_new_image(set->mlx, WIDTH, HEIGHT);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
}

void	init_player(t_player *player)
{
	player->x = WIDTH / 2;
	player->y = HEIGHT / 2;
	player->size = 13;
	player->rot_dir = 0;
	player->move_dir = 0;
	player->rot_ang = M_PI * 1.5;
	player->move_spd = 2;
	player->rot_spd = 2 * (M_PI / 180);
}

void	render_grid(t_img *img, int x, int y, int color) // 타일을 그린다.
{
	int		px;
	int		py;
	int		line_color;

	line_color = 0x000000;
	py = 0;
	while (py < GRID_SIZE)
	{
		px = 0;
		while (px < GRID_SIZE)
		{
			if (py == GRID_SIZE - 1 || px == GRID_SIZE - 1)
				img->data[WIDTH * (y + py) + (x + px)] = line_color;
			else
				img->data[WIDTH * (y + py) + (x + px)] = color;
			px++;
		}
		py++;
	}
}

void	render_map(t_set *set) // 맵을 그린다.
{
	int		x;
	int		y;

	get_map(set);
	y = 0;
	while (y < ROW)
	{
		x = 0;
		while (x < COL)
		{
			if (set->map[y][x] == 1)
				render_grid(&set->img, GRID_SIZE * x, GRID_SIZE * y, 0x000000);
			else
				render_grid(&set->img, GRID_SIZE * x, GRID_SIZE * y, 0xFFFFFF);
			x++;
		}
		y++;
	}
}

int		wall_collision(t_set *set, float x, float y)
{
	int		map_x;
	int		map_y;
	
	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
		return (0);
	map_x = floor(x / GRID_SIZE);
	map_y = floor(y / GRID_SIZE);
	if (set->map[map_y][map_x] != 0)
		return (0);
	return (-1);
}

void	update_player(t_set *set, t_player *player)
{
	int		move;
	float	new_x;
	float	new_y;

	move = player->move_dir * player->move_spd;
	player->rot_ang += player->rot_dir * player->rot_spd;
	new_x = player->x + cos(player->rot_ang) * move;
	new_y = player->y + sin(player->rot_ang) * move;

	if (wall_collision(set, new_x, new_y) != 0) // 벽과 충돌하면 참(0)이다.
	{
		player->x = new_x;
		player->y = new_y;
	}
}

void	render_player_ray(t_img *img, t_player *player)
{
	int		px;
	int		py;
	int		ray_len;

	ray_len = 0;
	while (ray_len < 40)
	{
		px = player->x + cos(player->rot_ang) * ray_len;
		py = player->y + sin(player->rot_ang) * ray_len;
		img->data[WIDTH * py + px] = 0xFF0000;
		ray_len++;
	}
}

void	render_player(t_img *img, t_player *player)
{
	int		x;
	int		y;
	int		px;
	int		py;

	y = 0;
	while (y < player->size)
	{
		x = 0;
		while (x < player->size)
		{
			px = player->x + x - (player->size - 1) / 2;
			py = player->y + y - (player->size - 1) / 2;
			img->data[WIDTH * py + px] = 0xFF0000;
			x++;
		}
		y++;
	}
	render_player_ray(img, player);
}

int		key_press_hook(int key, t_player *player) // 입력된 키에 따라 해당되는 값을 적용한다.
{
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_W)
		player->move_dir = 1;
	else if (key == KEY_A)
		player->rot_dir = -1;
	else if (key == KEY_S)
		player->move_dir = -1;
	else if (key == KEY_D)
		player->rot_dir = 1;
	printf("KEY PRESS : %d\n", key);
	return (0);
}

int		key_release_hook(int key, t_player *player)
{
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_W)
		player->move_dir = 0;
	else if (key == KEY_A)
		player->rot_dir = 0;
	else if (key == KEY_S)
		player->move_dir = 0;
	else if (key == KEY_D)
		player->rot_dir = 0;
	printf("KEY RELEASE : %d\n", key);
	return (0);
}

int		close_hook()
{
	exit(0);
}

void	init_set(t_set *set) // 모든 객체를 초기화한다.
{
	init_win(set);
	init_img(set, &set->img);
	init_player(&set->player);
}

void	update(t_set *set) // 다음 프레임을 그리기 전에 모든 객체를 갱신한다.
{
	update_player(set, &set->player); // 회전 방향과 움직이는 방향에 따라 플레이어의 위치를 갱신한다.
}

int		render_loop(t_set *set) // 모든 객체를 프레임별로 그린다.
{
	update(set);
	render_map(set);
	render_player(&set->img, &set->player);

	mlx_put_image_to_window(set->mlx, set->win, set->img.img, 0, 0);

	return (0);
}

int		main(void)
{
	t_set	set;

	init_set(&set); // 모든 객체를 초기화한다.

	mlx_hook(set.win, KEY_PRESS, 0, &key_press_hook, &set.player);
	mlx_hook(set.win, KEY_RELEASE, 0, &key_release_hook, &set.player);
	mlx_hook(set.win, WINDOW_CLOSE_BUTTON, 0, &close_hook, 0);
	mlx_loop_hook(set.mlx, render_loop, &set);

	mlx_loop(set.mlx);
	return (0);
}

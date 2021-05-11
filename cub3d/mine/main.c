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

/*typedef	struct		s_ray
{
	float		ray_ang;
	float		hit_x;
	float		hit_y;
	float		distance;
	int			hit_vert;
	int			ray_up;
	int			ray_down;
	int			ray_left;
	int			ray_right;
	int			hit_content;
}					t_ray[RAYS];*/

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
	player->size = 13 * M;
	player->rot_dir = 0;
	player->move_dir = 0;
	player->rot_ang = M_PI * 1.5;
	player->move_spd = 3;
	player->rot_spd = 3 * (M_PI / 180);
}

void	render_grid(t_img *img, int x, int y, int color) // 타일을 그린다.
{
	int		px;
	int		py;
	int		line_color;

	line_color = 0x000000;
	py = 0;
	while (py < GRID_SIZE * M)
	{
		px = 0;
		while (px < GRID_SIZE * M)
		{
			if (py == M * GRID_SIZE - 1 || px == M * GRID_SIZE - 1)
				img->data[WIDTH * (y + py) + x + px] = line_color;
			else
				img->data[WIDTH * (y + py) + x + px] = color;
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
				render_grid(&set->img, M * GRID_SIZE * x, M * GRID_SIZE * y, 0x0000FF);
			else
				render_grid(&set->img, M * GRID_SIZE * x, M * GRID_SIZE * y, 0xFFFFFF);
			x++;
		}
		y++;
	}
}

int		wall_collision(t_set *set, float x, float y) // 벽과 충돌했는지 검사한다. 충돌시에는 참(0)을 반환한다.
{
	int		map_x;
	int		map_y;
	
	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
		return TRUE;
	map_x = floor(x / GRID_SIZE);
	map_y = floor(y / GRID_SIZE);
	if (set->map[map_y][map_x] != 0)
		return TRUE;
	return FALSE;
}

void	update_player(t_set *set, t_player *player) // 플레이어의 움직이는 방향과 회전 방향에 따라 갱신한다.
{
	int		move;
	float	new_x;
	float	new_y;

	move = player->move_dir * player->move_spd;
	player->rot_ang += player->rot_dir * player->rot_spd;
	new_x = player->x + cos(player->rot_ang) * move;
	new_y = player->y + sin(player->rot_ang) * move;
	if (wall_collision(set, new_x, new_y) == FALSE) // 벽과 충돌하지 않은 경우이다.
	{
		player->x = new_x;
		player->y = new_y;
	}
}

void	render_player_ray_line(t_img *img, t_player *player) // 플레이어의 시야 광선 라인 한줄을 그린다.
{
	int		px;
	int		py;
	int		ray_len;

	ray_len = 0;
	while (ray_len < 40)
	{
		px = M * (player->x - M + cos(player->rot_ang) * ray_len);
		py = M * (player->y - M + sin(player->rot_ang) * ray_len);
		img->data[WIDTH * py + px] = 0xFF0000;
		ray_len++;
	}
}

void	render_player(t_img *img, t_player *player) // 플레이어를 그린다.
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
			px = M * (player->x + x - (player->size - 1) / 2 - M);
			py = M * (player->y + y - (player->size - 1) / 2 - M);
			img->data[WIDTH * py + px] = 0xFF0000;
			x++;
		}
		y++;
	}
	render_player_ray_line(img, player);
}

void	update_ray() // 시야 방향에 따라 광선을 갱신한다.
{
}

void	update_rays(t_player *player) // 시야 방향에 따라 광선들을 갱신한다.
{
	int		col_i; // 열의 인덱스
	float	ray_ang;

	ray_ang = player->rot_ang - (FOV / 2); // FOV의 절반을 뺀 첫번째 광선이다.

	col_i = 0;
	while (col_i < RAYS)
	{
		//update_ray(ray_ang, col_i);
		ray_ang += FOV / RAYS;
		col_i++;
	}
}

void	render_rays()
{
}

int		key_press_hook(int key, t_player *player) // 누른 키에 따라 해당되는 값을 적용한다.
{
	if (key == KEY_ESC)
		exit (0);
	else if (key == KEY_W)
		player->move_dir = 1;
	else if (key == KEY_A)
		player->rot_dir = -1;
	else if (key == KEY_S)
		player->move_dir = -1;
	else if (key == KEY_D)
		player->rot_dir = 1;
	printf("KEY PRESS : %d\n", key);
	return TRUE;
}

int		key_release_hook(int key, t_player *player) // 놓은 키에 따라 해당되는 값을 적용한다.
{
	if (key == KEY_ESC)
		exit (0);
	else if (key == KEY_W)
		player->move_dir = 0;
	else if (key == KEY_A)
		player->rot_dir = 0;
	else if (key == KEY_S)
		player->move_dir = 0;
	else if (key == KEY_D)
		player->rot_dir = 0;
	printf("KEY RELEASE : %d\n", key);
	return TRUE;
}

int		close_hook() // 창 닫기 버튼을 누르면 작동한다.
{
	exit (0);
}

void	init_set(t_set *set) // 모든 객체를 초기화한다.
{
	init_win(set);
	init_img(set, &set->img);
	init_player(&set->player);
}

void	update(t_set *set) // 다음 프레임을 그리기 전에 모든 객체를 갱신한다.
{
	update_player(set, &set->player);
	update_rays(&set->player);
}

int		render_loop(t_set *set) // 모든 객체를 프레임별로 그린다.
{
	update(set);
	render_map(set);
	render_player(&set->img, &set->player);
	//render_rays(&set->img, &set->player);

	mlx_put_image_to_window(set->mlx, set->win, set->img.img, 0, 0);

	return TRUE;
}

int		main(void)
{
	t_set	set;

	init_set(&set);

	mlx_hook(set.win, KEY_PRESS, 0, &key_press_hook, &set.player);
	mlx_hook(set.win, KEY_RELEASE, 0, &key_release_hook, &set.player);
	mlx_hook(set.win, WINDOW_CLOSE_BUTTON, 0, &close_hook, 0);
	mlx_loop_hook(set.mlx, render_loop, &set);

	mlx_loop(set.mlx);
	return TRUE;
}

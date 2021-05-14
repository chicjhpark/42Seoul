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

typedef struct		s_data
{
	int		down;
	int		up;
	int		right;
	int		left;
	float	x_block;
	float	y_block;
	float	x_step;
	float	y_step;
	int		h_hit;
	float	h_hit_x;
	float	h_hit_y;
	int		h_content;
	float	h_touch_x;
	float	h_touch_y;
	float	h_distance;
	int		v_hit;
	float	v_hit_x;
	float	v_hit_y;
	int		v_content;
	float	v_touch_x;
	float	v_touch_y;
	float	v_distance;
}					t_data;

typedef	struct		s_ray
{
	float		ang;
	float		hit_x;
	float		hit_y;
	float		distance;
	int			hit_vert;
	int			up;
	int			down;
	int			left;
	int			right;
	int			hit_content;
	t_data		data;
}					t_ray;

typedef struct		s_set
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_player	player;
	t_ray		*ray;
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
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1},
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



void	render_grid(t_img *img, int x1, int y1, int color) // 타일을 그린다.
{
	int		x2;
	int		y2;
	int		line_color;

	line_color = 0x000000;
	y2 = 0;
	while (y2 < M * GRID_SIZE)
	{
		x2 = 0;
		while (x2 < M * GRID_SIZE)
		{
			if (y2 == 0 || x2 == 0 || y2 == M * GRID_SIZE - M || x2 == M * GRID_SIZE - M)
				img->data[WIDTH * (y1 + y2) + x1 + x2] = line_color;
			else
				img->data[WIDTH * (y1 + y2) + x1 + x2] = color;
			x2++;
		}
		y2++;
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

void	init_player(t_player *player)
{
	player->x = WIDTH / 2;
	player->y = HEIGHT / 2;
	player->size = M * 8;
	player->rot_dir = 0;
	player->move_dir = 0;
	player->rot_ang = rad(90);
	player->move_spd = 3;
	player->rot_spd = rad(3);
}

int		check_collision(t_set *set, float x, float y) // 벽과 충돌했는지 검사한다. 충돌시에는 참(0)을 반환한다.
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
	if (check_collision(set, new_x, new_y) == FALSE) // 벽과 충돌하지 않은 경우이다.
	{
		player->x = new_x;
		player->y = new_y;
	}
}

void	render_player_line(t_img *img, t_player *player) // 플레이어의 시야 방향을 나타내는 줄 하나를 그린다.
{
	int		x;
	int		y;
	int		len;

	len = 0;
	while (len < 40)
	{
		x = M * (player->x + cos(player->rot_ang) * len);
		y = M * (player->y + sin(player->rot_ang) * len);
		img->data[WIDTH * y + x] = 0xFF0000;
		len++;
	}
}

void	render_player(t_img *img, t_player *player) // 플레이어를 그린다.
{
	int		x;
	int		y;
	int		size;
	int		ang;

	ang = 0;
	while (ang < 360)
	{
		size = 0;
		while (size < player->size)
		{
			x = M * (player->x + cos(rad(ang)) * size);
			y = M * (player->y + sin(rad(ang)) * size);
			img->data[WIDTH * y + x] = 0xFF0000;
			size++;
		}
		ang++;
	}
	render_player_line(img, player);
}

int		init_ray(t_ray **ray)
{
	if (!(*ray = (t_ray *)malloc(sizeof(t_ray) * (RAYS + 1))))
		return FALSE;
	return TRUE;
}

float	normalize_ang(float ang) // 시야의 각도가 0도보다 작거나 360도보다 클 때 각도를 초기화시킨다.
{
	ang = remainder(ang, M_PI * 2);
	if (ang < 0)
		ang += M_PI * 2;
	return (ang);
}

float	distance_between_point(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	init_data(t_data *data, float ang)
{
	data->down = ang > 0 && ang < M_PI;
	data->up = !data->down;
	data->right = ang < 0.5 * M_PI || ang > 1.5 * M_PI;
	data->left = !data->right;
	data->h_hit = FALSE;
	data->h_hit_x = 0;
	data->h_hit_y = 0;
	data->h_content = 0;
	data->v_hit = FALSE;
	data->v_hit_x = 0;
	data->v_hit_y = 0;
	data->v_content = 0;
}

void	init_horiz_data(t_player *player, t_data *data, float ang)
{
	data->y_block = floor(player->y / GRID_SIZE) * GRID_SIZE;
	data->y_block += data->down ? GRID_SIZE : 0;
	data->x_block = player->x + (data->y_block - player->y) / tan(ang);
	data->y_step = GRID_SIZE;
	data->y_step *= data->up ? -1 : 1;
	data->x_step = GRID_SIZE / tan(ang);
	data->x_step *= (data->left && data->x_step > 0) ? -1 : 1;
	data->x_step *= (data->right && data->x_step < 0) ? -1 : 1;
	data->h_touch_x = data->x_block;
	data->h_touch_y = data->y_block;
}

void	horiz_intersection(t_set *set, t_data *data)
{
	while (data->h_touch_x >= 0 && data->h_touch_x <= WIDTH && data->h_touch_y >= 0 && data->h_touch_y <= HEIGHT)
	{
		float	x_check;
		float	y_check;

		x_check = data->h_touch_x;
		y_check = data->h_touch_y + (data->up ? -1 : 0);

		if (check_collision(set, x_check, y_check) == TRUE)
		{
			data->h_hit_x = data->h_touch_x;
			data->h_hit_y = data->h_touch_y;
			data->h_content = set->map[(int)floor(y_check / GRID_SIZE)][(int)floor(x_check / GRID_SIZE)];
			data->h_hit = TRUE;
			break;
		}
		else
		{
			data->h_touch_x += data->x_step;
			data->h_touch_y += data->y_step;
		}
	}
}

void	init_vert_data(t_player *player, t_data *data, float ang)
{
	data->x_block = floor(player->x / GRID_SIZE) * GRID_SIZE;
	data->x_block += data->right ? GRID_SIZE : 0;
	data->y_block = player->y + (data->x_block - player->x) * tan(ang);
	data->x_step = GRID_SIZE;
	data->x_step *= data->left ? -1 : 1;
	data->y_step = GRID_SIZE * tan(ang);
	data->y_step *= (data->up && data->y_step > 0) ? -1 : 1;
	data->y_step *= (data->down && data->y_step < 0) ? -1 : 1;
	data->v_touch_x = data->x_block;
	data->v_touch_y = data->y_block;
}

void	vert_intersection(t_set *set, t_data *data)
{
	while (data->v_touch_x >= 0 && data->v_touch_x <= WIDTH && data->v_touch_y >= 0 && data->v_touch_y <= HEIGHT)
	{
		float	x_check;
		float	y_check;

		x_check = data->v_touch_x + (data->left ? -1 : 0);
		y_check = data->v_touch_y;

		if (check_collision(set, x_check, y_check) == TRUE)
		{
			data->v_hit_x = data->v_touch_x;
			data->v_hit_y = data->v_touch_y;
			data->v_content = set->map[(int)floor(y_check / GRID_SIZE)][(int)floor(x_check / GRID_SIZE)];
			data->v_hit = TRUE;
			break;
		}
		else
		{
			data->v_touch_x += data->x_step;
			data->v_touch_y += data->y_step;
		}
	}
}

void	select_closest_distance(t_player *player, t_ray *ray, t_data *data, float ang, int i)
{
	data->h_distance = data->h_hit ? distance_between_point(player->x, player->y, data->h_hit_x, data->h_hit_y) : FLT_MAX;
	data->v_distance = data->v_hit ? distance_between_point(player->x, player->y, data->v_hit_x, data->v_hit_y) : FLT_MAX;
	if (data->v_distance < data->h_distance)
	{
		ray[i].distance = data->v_distance;
		ray[i].hit_x = data->v_hit_x;
		ray[i].hit_y = data->v_hit_y;
		ray[i].hit_content = data->v_content;
		ray[i].hit_vert = TRUE;
	}
	else
	{
		ray[i].distance = data->h_distance;
		ray[i].hit_x = data->h_hit_x;
		ray[i].hit_y = data->h_hit_y;
		ray[i].hit_content = data->h_content;
		ray[i].hit_vert = FALSE;
	}
	ray[i].ang = ang;
	ray[i].down = data->down;
	ray[i].up = data->up;
	ray[i].left = data->left;
	ray[i].right = data->right;
}

void	update_ray(t_set *set, t_player *player, t_ray *ray, float ang, int i)
{
	ang = normalize_ang(ang);
	init_data(&ray->data, ang);
	init_horiz_data(player, &ray->data, ang);
	horiz_intersection(set, &ray->data);
	init_vert_data(player, &ray->data, ang);
	vert_intersection(set, &ray->data);
	select_closest_distance(player, ray, &ray->data, ang, i);
}

void	update_rays(t_set *set, t_player *player, t_ray *ray) // 시야 방향에 따라 광선들을 갱신한다.
{
	float	ang;
	int		i;

	ang = player->rot_ang - (FOV / 2);
	i = 0;
	while (i < RAYS)
	{
		update_ray(set, player, ray, ang, i);
		ang += FOV / (RAYS - 1);
		i++;
	}
}

void	render_ray(t_img *img, t_player *player, t_ray *ray) // 광선들을 그린다.
{
	int		x;
	int		y;
	int		i;
	int		j;

	i = 0;
	while (i < RAYS)
	{
		j = 0;
		while (j <= ray[i].distance)
		{
			x = M * (player->x + cos(ray[i].ang) * j);
			y = M * (player->y + sin(ray[i].ang) * j);
			img->data[WIDTH * y + x] = 0xFF0000;
			j++;
		}
		i++;
	}
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
	return TRUE;
}

int		close_hook(t_ray **ray) // 창 닫기 버튼을 누르면 작동한다.
{
	free(*ray);
	exit (0);
}

void	init_set(t_set *set) // 모든 객체를 초기화한다.
{
	init_win(set);
	init_img(set, &set->img);
	init_player(&set->player);
	init_ray(&set->ray);
}

void	update(t_set *set) // 다음 프레임을 그리기 전에 모든 객체를 갱신한다.
{
	update_player(set, &set->player);
	update_rays(set, &set->player, set->ray);
}

int		render_loop(t_set *set) // 모든 객체를 프레임별로 그린다.
{
	update(set);
	render_map(set);
	render_ray(&set->img, &set->player, set->ray);
	render_player(&set->img, &set->player);
	mlx_put_image_to_window(set->mlx, set->win, set->img.img, 0, 0);
	return TRUE;
}

int		main(void)
{
	t_set	set;

	init_set(&set);
	mlx_hook(set.win, KEY_PRESS, 0, &key_press_hook, &set.player);
	mlx_hook(set.win, KEY_RELEASE, 0, &key_release_hook, &set.player);
	mlx_hook(set.win, WINDOW_CLOSE_BUTTON, 0, &close_hook, &set.ray);
	mlx_loop_hook(set.mlx, render_loop, &set);
	mlx_loop(set.mlx);
	return TRUE;
}

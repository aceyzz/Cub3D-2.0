/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 09:20:04 by cedmulle          #+#    #+#             */
/*   Updated: 2024/05/19 14:43:38 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# define FOV 50
# define COLLISION 0.3

# define K_W 13
# define K_A 0
# define K_S 1
# define K_D 2
# define K_LEFT 123
# define K_RIGHT 124
# define K_ESC 53
# define K_SHFT 257
# define K_SPACE 49

# define TSIZE 512
# define SQUARE_MINIMAP 40

# define MOVE_SPEED 0.07
# define RUN_SPEED 0.09
# define ROTA_SPEED 0.08

typedef struct s_tex	t_tex;
typedef struct s_data	t_data;
typedef enum e_type		t_type;

typedef struct s_mlx
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*addr;
	int					bpp;
	int					len;
	int					end;
}						t_mlx;

typedef struct s_keys
{
	bool				w;
	bool				a;
	bool				s;
	bool				d;
	bool				left;
	bool				right;
	bool				shift;
}						t_keys;

typedef struct s_ray
{
	double				cam_x;
	double				pos_x;
	double				pos_y;
	double				dir_x;
	double				dir_y;
	double				delta_x;
	double				delta_y;
	double				side_x;
	double				side_y;
	double				perp_wall_dist;
	int					hit;
	int					map_x;
	int					map_y;
	int					step_x;
	int					step_y;
	int					side;
	int					line_height;
	int					draw_start;
	int					draw_end;
}						t_ray;

typedef struct s_plyr
{
	double				pos_x;
	double				pos_y;
	double				pos_z;
	double				middle_screen;
	double				dir_x;
	double				dir_y;
	double				plane_x;
	double				plane_y;
	double				move_speed;
	double				rota_speed;
	bool				jumping;
	double				velocity;
}						t_plyr;

typedef struct s_calc
{
	int					x;
	int					y;
	int					y_rev;
	double				dst_wall;
	double				dst_floor;
}						t_calc;

typedef struct s_flcl
{
	double				dir_x_a;
	double				dir_y_a;
	double				dir_x_b;
	double				dir_y_b;
	double				dir_row;
	double				step_x;
	double				step_y;
	double				floor_x;
	double				floor_y;
	double				dist_wall;
}						t_flcl;

typedef struct s_mini
{
	double				pos_x;
	double				pos_y;
}						t_mini;

// MLX
/* init.c */
void					init_mlx(t_data *data);
void					init_imgs(t_data *data);

/// MOVE_ROTA
/* keys.c */
int						keyrelease(int keys, t_data *data);
int						keypress(int keys, t_data *data);

// LOGIC
/* main_moves.c */
void					update_moves(t_data *data);
/* moves.c */
void					move_front(t_data *data);
void					move_back(t_data *data);
void					move_right(t_data *data);
void					move_left(t_data *data);
/* rotate.c */
void					rota_left(t_data *data);
void					rota_right(t_data *data);
/* moves_utils.c */
void					normalize_speed(double *x, double *y);
bool					collision(char **map, double new_x, double new_y);
double					cal_new_pos(double pos, double move_speed,
							double new_pos);

// RAYCAST
/* main_game.c */
int						main_game(t_data *data);
/* init_raycaster.c */
void					init_raycaster(t_data *data);
/* raycaster.c */
void					set_step(t_data *data, t_ray *ray);
void					calc_wall_height(t_data *data, t_ray *ray);
void					init_ray(t_data *data, t_ray *ray, int x);

// DRAW
/* draw_rays.c */
t_tex					*get_texture(t_data *data, t_type orientation);
void					draw_wall(t_data *data, t_ray *ray, int x);
/* draw_fc.c */
void					draw_fc(t_data *data, t_ray *ray, int x);
/* draw_utils.c */
void					my_pixel_put(t_mlx *mlx, int x, int y, int color);
unsigned int			rgb_to_hexa(int rgb[3]);

// BONUS
/* mouse.c */
void					handle_mouse(t_data *data);
void					start_sound(void);
void					stop_sound(void);

#endif

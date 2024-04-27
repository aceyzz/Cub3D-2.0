/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 09:20:04 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/27 12:00:20 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# define FOV 60

# define K_W 13
# define K_A 0
# define K_S 1
# define K_D 2
# define K_LEFT 123
# define K_RIGHT 124
# define K_ESC 53

# define MOVE_SPEED 0.05
# define ROTA_SPEED 0.05

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		end;
}			t_mlx;

typedef struct s_keys
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	left;
	bool	right;
}			t_keys;

typedef struct s_ray
{
	double	cam_x;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	delta_x;
	double	delta_y;
	double	side_x;
	double	side_y;
	double	perp_wall_dist;
	int		hit;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}			t_ray;

typedef struct s_plyr
{
	double	pos_x;
	double	pos_y;
	double	pos_z;
	double	middle_screen;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rota_speed;
}			t_plyr;

/************************* MLX *******************/
void		init_mlx(t_data *data);


/********************* MOVE_ROTA *****************/
// KEYS.C
int			keyrelease(int keys, t_data *data);
int			keypress(int keys, t_data *data);

/********************** RAYCAST ******************/
// MAIN_GAME.C
int			main_game(t_data *data);
// INIT.C
void		init_raycaster(t_data *data);

#endif

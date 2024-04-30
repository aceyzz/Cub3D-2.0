/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:51:44 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/30 14:18:13 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static unsigned int	get_tex_color_fc(t_data *data, int x, int y, t_type type)
{
	t_tex			*tex;
	unsigned int	color;

	if (type == FLOOR)
		tex = get_texture(data, FLOOR);
	else
		tex = get_texture(data, CEIL);
	color = *(unsigned int *)(tex->addr + (y * tex->len + x * (tex->bpp / 8)));
	return (color);
}

static void	parse_n_draw_floor(t_data *data, int x, int y)
{
	t_flcl	fc;
	t_calc	c;
	double	p;

	fc.dir_x_a = data->player->dir_x - data->player->plane_x;
	fc.dir_y_a = data->player->dir_y - data->player->plane_y;
	fc.dir_x_b = data->player->dir_x + data->player->plane_x;
	fc.dir_y_b = data->player->dir_y + data->player->plane_y;
	p = y - data->player->middle_screen;
	fc.dist_wall = data->player->middle_screen / p;
	fc.step_x = fc.dist_wall * (fc.dir_x_b - fc.dir_x_a) / X_RES;
	fc.step_y = fc.dist_wall * (fc.dir_y_b - fc.dir_y_a) / X_RES;
	fc.floor_x = data->player->pos_x + fc.dist_wall * fc.dir_x_a;
	fc.floor_y = data->player->pos_y + fc.dist_wall * fc.dir_y_a;
	fc.floor_x += fc.step_x * x;
	fc.floor_y += fc.step_y * x;
	c.x = (int)(fc.floor_x * TSIZE) % TSIZE;
	c.y = (int)(fc.floor_y * TSIZE) % TSIZE;
	my_pixel_put(data->mlx, x, y, get_tex_color_fc(data, c.x, c.y, FLOOR));
}

static void	parse_n_draw_sky(t_data *data, int x, int y)
{
	t_flcl	fc;
	t_calc	calc;
	double	p;

	fc.dir_x_a = data->player->dir_x - data->player->plane_x;
	fc.dir_y_a = data->player->dir_y - data->player->plane_y;
	fc.dir_x_b = data->player->dir_x + data->player->plane_x;
	fc.dir_y_b = data->player->dir_y + data->player->plane_y;
	p = data->player->middle_screen - y;
	fc.dist_wall = data->player->middle_screen / p;
	fc.step_x = fc.dist_wall * (fc.dir_x_b - fc.dir_x_a) / X_RES;
	fc.step_y = fc.dist_wall * (fc.dir_y_b - fc.dir_y_a) / X_RES;
	fc.floor_x = data->player->pos_x + fc.dist_wall * fc.dir_x_a;
	fc.floor_y = data->player->pos_y + fc.dist_wall * fc.dir_y_a;
	fc.floor_x += fc.step_x * x;
	fc.floor_y += fc.step_y * x;
	calc.x = (int)(fc.floor_x * TSIZE) % TSIZE;
	calc.y = (int)(fc.floor_y * TSIZE) % TSIZE;
	my_pixel_put(data->mlx, x, y, get_tex_color_fc(data, calc.x, calc.y, CEIL));
}

void	draw_fc(t_data *data, t_ray *ray, int x)
{
	int		y;
	t_tex	*floor;
	t_tex	*sky;

	y = -1;
	floor = get_texture(data, FLOOR);
	sky = get_texture(data, CEIL);
	while (++y < ray->draw_start)
	{
		if (sky->is_rgb == true)
			my_pixel_put(data->mlx, x, y, rgb_to_hexa(sky->rgb));
		else
			parse_n_draw_sky(data, x, y);
	}
	y = ray->draw_end - 1;
	while (++y < Y_RES)
	{
		if (floor->is_rgb == true)
			my_pixel_put(data->mlx, x, y, rgb_to_hexa(floor->rgb));
		else
			parse_n_draw_floor(data, x, y);
	}
}

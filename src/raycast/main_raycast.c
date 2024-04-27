/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:37:36 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/27 23:19:52 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	perform_dda(t_data *data, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_x < ray->side_y)
		{
			ray->side_x += ray->delta_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_y += ray->delta_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (data->map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - data->player->pos_x
				+ (1 - ray->step_x) / 2) / ray->dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - data->player->pos_y
				+ (1 - ray->step_y) / 2) / ray->dir_y;
}

static void	calculate_wall(t_data *data, t_ray *ray)
{
	ray->line_height = (int)(Y_RES / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + data->player->middle_screen;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + data->player->middle_screen;
	if (ray->draw_end >= Y_RES)
		ray->draw_end = Y_RES - 1;
}

void	raycasting(t_data *data)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < X_RES)
	{
		init_ray(data, &ray, x);
		set_step(&ray);
		set_draw_range(data, &ray);
		perform_dda(data, &ray);
		calculate_wall(data, &ray);
		draw_wall(data, &ray, x);
		draw_floor_sky(data, &ray, x);
		x++;
	}
}

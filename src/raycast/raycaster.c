/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:12:28 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/30 13:24:24 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	init_ray(t_data *data, t_ray *ray, int x)
{
	ray->cam_x = 2 * x / (double)X_RES - 1;
	ray->pos_x = data->player->pos_x;
	ray->pos_y = data->player->pos_y;
	ray->dir_x = data->player->dir_x + data->player->plane_x * ray->cam_x;
	ray->dir_y = data->player->dir_y + data->player->plane_y * ray->cam_x;
	ray->map_x = (int)data->player->pos_x;
	ray->map_y = (int)data->player->pos_y;
	ray->delta_x = fabs(1 / ray->dir_x);
	ray->delta_y = fabs(1 / ray->dir_y);
	ray->side_x = 0;
	ray->side_y = 0;
	ray->perp_wall_dist = 0;
	ray->hit = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->side = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
}

void	calc_wall_height(t_data *data, t_ray *ray)
{
	ray->line_height = (int)(Y_RES / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + data->player->middle_screen;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + data->player->middle_screen;
	if (ray->draw_end >= Y_RES)
		ray->draw_end = Y_RES - 1;
}

static void	set_draw_range(t_data *data, t_ray *ray)
{
	ray->draw_start = -ray->line_height / 2 + data->player->middle_screen;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + data->player->middle_screen;
	if (ray->draw_end >= Y_RES)
		ray->draw_end = Y_RES - 1;
}

void	set_step(t_data *data, t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_x = (data->player->pos_x - ray->map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_x = (ray->map_x + 1.0 - data->player->pos_x) * ray->delta_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_y = (data->player->pos_y - ray->map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_y = (ray->map_y + 1.0 - data->player->pos_y) * ray->delta_y;
	}
	set_draw_range(data, ray);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:22:35 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/30 22:53:53 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

// ADD MINIMAP & SOUNDS
static void	main_bonus(t_data *data)
{
	handle_mouse(data);
}

static void	dda(t_data *data, t_ray *ray)
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
		ray->perp_wall_dist = (ray->map_x - data->player->pos_x + (1
					- ray->step_x) / 2) / ray->dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - data->player->pos_y + (1
					- ray->step_y) / 2) / ray->dir_y;
}

static void	raycasting(t_data *data)
{
	t_ray	ray;
	int		x;

	x = -1;
	while (++x < X_RES)
	{
		init_ray(data, &ray, x);
		set_step(data, &ray);
		dda(data, &ray);
		calc_wall_height(data, &ray);
		draw_wall(data, &ray, x);
		draw_fc(data, &ray, x);
	}
}

int	main_game(t_data *data)
{
	update_moves(data);
	raycasting(data);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->mlx->img, 0,
		0);
	if (BONUS == 1)
		main_bonus(data);
	return (0);
}

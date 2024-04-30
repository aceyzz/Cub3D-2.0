/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:35:17 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/30 13:07:53 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	rota_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rota_speed;

	rota_speed = data->player->rota_speed;
	old_dir_x = data->player->dir_x;
	data->player->dir_x = data->player->dir_x * cos(-rota_speed)
		- data->player->dir_y * sin(-rota_speed);
	data->player->dir_y = old_dir_x * sin(-rota_speed) + data->player->dir_y
		* cos(-rota_speed);
	old_plane_x = data->player->plane_x;
	data->player->plane_x = data->player->plane_x * cos(-rota_speed)
		- data->player->plane_y * sin(-rota_speed);
	data->player->plane_y = old_plane_x * sin(-rota_speed)
		+ data->player->plane_y * cos(-rota_speed);
}

void	rota_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rota_speed;

	rota_speed = data->player->rota_speed;
	old_dir_x = data->player->dir_x;
	data->player->dir_x = data->player->dir_x * cos(rota_speed)
		- data->player->dir_y * sin(rota_speed);
	data->player->dir_y = old_dir_x * sin(rota_speed) + data->player->dir_y
		* cos(rota_speed);
	old_plane_x = data->player->plane_x;
	data->player->plane_x = data->player->plane_x * cos(rota_speed)
		- data->player->plane_y * sin(rota_speed);
	data->player->plane_y = old_plane_x * sin(rota_speed)
		+ data->player->plane_y * cos(rota_speed);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:35:17 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/27 23:17:59 by cedmulle         ###   ########.fr       */
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
	old_plane_x = data->player->plane_x;
	data->player->dir_x = cal_new_dir(data->player->dir_x,
			data->player->dir_y, -rota_speed, '-');
	data->player->dir_y = cal_new_dir(old_dir_x,
			data->player->dir_y, -rota_speed, '+');
	data->player->plane_x = cal_new_dir(data->player->plane_x,
			data->player->plane_y, -rota_speed, '-');
	data->player->plane_y = cal_new_dir(old_plane_x,
			data->player->plane_y, -rota_speed, '+');
}

void	rota_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rota_speed;

	rota_speed = data->player->rota_speed;
	old_dir_x = data->player->dir_x;
	old_plane_x = data->player->plane_x;
	data->player->dir_x = cal_new_dir(data->player->dir_x,
			data->player->dir_y, rota_speed, '-');
	data->player->dir_y = cal_new_dir(old_dir_x,
			data->player->dir_y, rota_speed, '+');
	data->player->plane_x = cal_new_dir(data->player->plane_x,
			data->player->plane_y, rota_speed, '-');
	data->player->plane_y = cal_new_dir(old_plane_x,
			data->player->plane_y, rota_speed, '+');
}

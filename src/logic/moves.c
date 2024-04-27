/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:39:44 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/27 23:11:58 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	move_front(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player->dir_x;
	new_y = data->player->dir_y;
	normalize_speed(&new_x, &new_y);
	new_x = cal_new_pos(data->player->pos_x, data->player->move_speed, new_x);
	new_y = cal_new_pos(data->player->pos_y, data->player->move_speed, new_y);
	if (!collision(data->map, new_x + (data->player->dir_x * COLLISION),
			new_y + (data->player->dir_y * COLLISION)))
	{
		data->player->pos_x = new_x;
		data->player->pos_y = new_y;
	}
}

void	move_back(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = -data->player->dir_x;
	new_y = -data->player->dir_y;
	normalize_speed(&new_x, &new_y);
	new_x = cal_new_pos(data->player->pos_x, data->player->move_speed, new_x);
	new_y = cal_new_pos(data->player->pos_y, data->player->move_speed, new_y);
	if (!collision(data->map, new_x - (data->player->dir_x * COLLISION),
			new_y - (data->player->dir_y * COLLISION)))
	{
		data->player->pos_x = new_x;
		data->player->pos_y = new_y;
	}
}

void	move_right(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player->plane_x;
	new_y = data->player->plane_y;
	normalize_speed(&new_x, &new_y);
	new_x = cal_new_pos(data->player->pos_x, data->player->move_speed, new_x);
	new_y = cal_new_pos(data->player->pos_y, data->player->move_speed, new_y);
	if (!collision(data->map, new_x + (data->player->plane_x * COLLISION),
			new_y + (data->player->plane_y * COLLISION)))
	{
		data->player->pos_x = new_x;
		data->player->pos_y = new_y;
	}
}

void	move_left(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = -data->player->plane_x;
	new_y = -data->player->plane_y;
	normalize_speed(&new_x, &new_y);
	new_x = cal_new_pos(data->player->pos_x, data->player->move_speed, new_x);
	new_y = cal_new_pos(data->player->pos_y, data->player->move_speed, new_y);
	if (!collision(data->map, new_x - (data->player->plane_x * COLLISION),
			new_y - (data->player->plane_y * COLLISION)))
	{
		data->player->pos_x = new_x;
		data->player->pos_y = new_y;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycaster.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:38:22 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/27 23:13:14 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	init_player_ns(t_data *data)
{
	if (data->orientation == NORTH)
	{
		data->player->dir_x = 0;
		data->player->dir_y = -1;
		data->player->plane_x = 0.66;
		data->player->plane_y = 0;
	}
	else
	{
		data->player->dir_x = 0;
		data->player->dir_y = 1;
		data->player->plane_x = -0.66;
		data->player->plane_y = 0;
	}
}

static void	init_player_ew(t_data *data)
{
	if (data->orientation == WEST)
	{
		data->player->dir_x = -1;
		data->player->dir_y = 0;
		data->player->plane_x = 0;
		data->player->plane_y = -0.66;
	}
	else
	{
		data->player->dir_x = 1;
		data->player->dir_y = 0;
		data->player->plane_x = 0;
		data->player->plane_y = 0.66;
	}
}

static void	init_player(t_data *data)
{
	data->player = malloc(sizeof(t_plyr));
	if (!data->player)
		error_exit("Malloc error", "init_player", data);
	data->player->pos_x = data->pos_x + 0.5;
	data->player->pos_y = data->pos_y + 0.5;
	data->player->pos_z = 0;
	if (data->orientation == NORTH || data->orientation == SOUTH)
		init_player_ns(data);
	else
		init_player_ew(data);
	data->player->middle_screen = Y_RES / 2;
	data->player->move_speed = MOVE_SPEED;
	data->player->rota_speed = ROTA_SPEED;
}

static void	init_keys(t_data *data)
{
	data->keys = malloc(sizeof(t_keys));
	if (!data->keys)
		error_exit("Malloc error", "init_keys", data);
	data->keys->w = false;
	data->keys->a = false;
	data->keys->s = false;
	data->keys->d = false;
	data->keys->left = false;
	data->keys->right = false;
	data->keys->shift = false;
}

void	init_raycaster(t_data *data)
{
	init_player(data);
	init_keys(data);
	init_player(data);
}

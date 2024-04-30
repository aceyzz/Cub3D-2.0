/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:08:00 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/30 14:17:13 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	keyrelease(int keys, t_data *data)
{
	if (keys == K_W)
		data->keys->w = false;
	if (keys == K_A)
		data->keys->a = false;
	if (keys == K_S)
		data->keys->s = false;
	if (keys == K_D)
		data->keys->d = false;
	if (keys == K_LEFT)
		data->keys->left = false;
	if (keys == K_RIGHT)
		data->keys->right = false;
	if (BONUS == 1 && keys == K_SHFT)
		data->player->move_speed = MOVE_SPEED;
	return (0);
}

int	keypress(int keys, t_data *data)
{
	if (keys == K_ESC)
		exit_game(data);
	if (keys == K_W)
		data->keys->w = true;
	if (keys == K_A)
		data->keys->a = true;
	if (keys == K_S)
		data->keys->s = true;
	if (keys == K_D)
		data->keys->d = true;
	if (keys == K_LEFT)
		data->keys->left = true;
	if (keys == K_RIGHT)
		data->keys->right = true;
	if (BONUS == 1 && keys == K_SHFT)
		data->player->move_speed = RUN_SPEED;
	return (0);
}

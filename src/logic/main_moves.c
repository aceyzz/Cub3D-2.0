/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:29:23 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/27 13:47:30 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	update_moves(t_data *data)
{
	if (data->keys->w)
		move_front(data);
	if (data->keys->s)
		move_back(data);
	if (data->keys->a)
		move_left(data);
	if (data->keys->d)
		move_right(data);
	if (data->keys->left)
		rota_left(data);
	if (data->keys->right)
		rota_right(data);
	if (data->keys->shift)
		data->player->move_speed = RUN_SPEED;
	else
		data->player->move_speed = MOVE_SPEED;
}

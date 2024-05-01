/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:16:06 by cedmulle          #+#    #+#             */
/*   Updated: 2024/05/01 17:24:46 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	handle_mouse(t_data *data)
{
	int	dx;
	int	dy;

	mlx_mouse_get_pos(data->mlx->win, &dx, &dy);
	if (dx < X_RES / 2 - 10)
		rota_left(data);
	else if (dx > X_RES / 2 + 10)
		rota_right(data);
	if (dy < Y_RES / 2 - 10 || dy > Y_RES / 2 + 10 || dx < X_RES / 2 - 10
		|| dx > X_RES / 2 + 10)
		mlx_mouse_move(data->mlx->win, X_RES / 2, Y_RES / 2);
}

void	start_sound()
{
	system("afplay ./sounds/soundtrack.mp3 & > /dev/null 2>&1");
}

void	stop_sound()
{
	system("killall afplay > /dev/null 2>&1");
}

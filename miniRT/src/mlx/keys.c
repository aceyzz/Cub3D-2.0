/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:22:02 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/25 17:52:21 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
	En fonction des variables utilisées pour la position et la direction
	de la camera, implémenter les fonctions de déplacement et de rotation
*/
int	keypress(int key, t_data *data)
{
	if (key == KEY_ESC)
	{
		printf("%s%d:\t%s\n", REDD, key, get_key_name(key));
		valid_exit(data);
	}
	if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
	{
		printf("%s%d:\t", BLUE, key);
	// 	handle_move(key, data);
	}
	if (key == KEY_LEFT || key == KEY_RIGHT || key == KEY_UP || key == KEY_DOWN)
	{
		printf("%s%d:\t", GRNN, key);
	// 	handle_rota(key, data);
	}
	printf("%s\n", get_key_name(key));
	return (0);
}

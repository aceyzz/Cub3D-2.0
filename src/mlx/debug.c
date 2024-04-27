/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:24:23 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/25 17:36:38 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

char	*get_key_name(int key)
{
	if (key == KEY_ESC)
		return (REDD "ESCAPE: exit" RST);
	if (key == KEY_W)
		return (BLUE "W: move forward" RST);
	if (key == KEY_S)
		return (BLUE "S move back" RST);
	if (key == KEY_A)
		return (BLUE "A: move left" RST);
	if (key == KEY_D)
		return (BLUE "D move right" RST);
	if (key == KEY_LEFT)
		return (GRNN "LEFT: rota left" RST);
	if (key == KEY_RIGHT)
		return (GRNN "RIGHT: rota right" RST);
	if (key == KEY_UP)
		return (GRNN "UP: rota up" RST);
	if (key == KEY_DOWN)
		return (GRNN "DOWN: rota down" RST);
	return (GRY2 "N/A: pas utile" RST);
}

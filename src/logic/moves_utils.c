/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:47:02 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/30 13:02:13 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	normalize_speed(double *x, double *y)
{
	double	len;

	len = sqrt(*x * *x + *y * *y);
	if (len > 0)
	{
		*x /= len;
		*y /= len;
	}
}

bool	collision(char **map, double new_x, double new_y)
{
	int		x;
	int		y;

	x = (int)(new_x);
	y = (int)(new_y);
	if (map[y][x] == '1')
		return (true);
	return (false);
}

double	cal_new_pos(double pos, double move_speed, double new_pos)
{
	return (pos + move_speed * new_pos);
}

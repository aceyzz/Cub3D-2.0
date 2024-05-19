/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:19:21 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/30 12:27:13 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

unsigned int	rgb_to_hexa(int rgb[3])
{
	return (((rgb[0] & 0xFF) << 16) + ((rgb[1] & 0xFF) << 8) + (rgb[2] & 0xFF));
}

void	my_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= X_RES || y < 0 || y >= Y_RES)
		return ;
	dst = mlx->addr + (y * mlx->len + x * (mlx->bpp / 8));
	*(unsigned int *)dst = color;
}

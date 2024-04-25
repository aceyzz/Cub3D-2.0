/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:29:19 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/25 17:40:57 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
	exemples de couleurs en hexadécimal a utiliser avec my_mlx_pixel_put:

    Noir:		0x000000
    Blanc:		0xFFFFFF
    Rouge:		0xFF0000
    Vert:		0x008000
    Bleu:		0x0000FF
    Jaune:		0xFFFF00
    Cyan:		0x00FFFF
    Magenta:	0xFF00FF
    Argent:		0xC0C0C0
    Gris: 		0x808080
    Maroon:		0x800000
    Olive:		0x808000
    Vert foncé:	0x008080
    Pourpre:	0x800080
    Teal:		0x008080
    Navy: 		0x000080

*/
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->len + x * (mlx->bpp / 8));
	*(unsigned int *)dst = color;
}

int	update_image(t_data *data)
{
	t_mlx	*mlx;

	mlx = data->mlx;
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}

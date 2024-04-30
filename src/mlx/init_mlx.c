/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 10:01:08 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/30 17:30:40 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	init_imgs(t_data *data)
{
	t_tex	*tmp;

	tmp = data->tex;
	while (tmp)
	{
		if (tmp->is_rgb == false)
		{
			tmp->img = mlx_xpm_file_to_image(data->mlx->mlx, tmp->path,
					&tmp->len, &tmp->len);
			tmp->addr = mlx_get_data_addr(tmp->img, &tmp->bpp, &tmp->len,
					&tmp->end);
		}
		tmp = tmp->next;
	}
}

void	init_mlx(t_data *data)
{
	data->mlx = malloc(sizeof(t_mlx));
	data->mlx->mlx = mlx_init();
	data->mlx->win = mlx_new_window(data->mlx->mlx, X_RES, Y_RES, "cub3D");
	data->mlx->img = mlx_new_image(data->mlx->mlx, X_RES, Y_RES);
	data->mlx->addr = mlx_get_data_addr(data->mlx->img, &data->mlx->bpp,
			&data->mlx->len, &data->mlx->end);
}

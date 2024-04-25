/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:03:47 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/25 17:22:14 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_mlx(t_mlx *mlx)
{
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->img)
		mlx_destroy_image(mlx->mlx, mlx->img);
	free(mlx);
}

int	close_win(t_data *data)
{
	valid_exit(data);
	return (0);
}

void	init_mlx(t_data *data)
{
	char	*win_name;

	win_name = "miniRT 1.0";
	data->mlx = malloc(sizeof(t_mlx));
	if (!data->mlx)
		err_exit_free("Malloc failed", data);
	data->mlx->mlx = mlx_init();
	if (!data->mlx->mlx)
		err_exit_free("Mlx init failed", data);
	data->mlx->win = mlx_new_window(data->mlx->mlx, X_RES, Y_RES, win_name);
	if (!data->mlx->win)
		err_exit_free("Window creation failed", data);
	data->mlx->img = mlx_new_image(data->mlx->mlx, X_RES, Y_RES);
	if (!data->mlx->img)
		err_exit_free("Image creation failed", data);
	data->mlx->addr = mlx_get_data_addr(data->mlx->img, &data->mlx->bpp,
			&data->mlx->len, &data->mlx->endian);
	if (!data->mlx->addr)
		err_exit_free("Image address failed", data);
}

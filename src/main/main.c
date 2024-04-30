/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 08:59:51 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/30 14:29:08 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (printf("Error\nInvalid number of arguments\n"));
	// ft_parsing(&data, argv[1]);
	init_mlx(&data);
	init_raycaster(&data);
	mlx_mouse_move(data.mlx->win, X_RES / 2, Y_RES / 2);
	mlx_hook(data.mlx->win, 2, 1L << 0, &keypress, &data);
	mlx_hook(data.mlx->win, 3, 1L << 1, &keyrelease, &data);
	mlx_hook(data.mlx->win, 17, 1L << 17, exit_game, &data);
	mlx_loop_hook(data.mlx->mlx, main_game, &data);
	mlx_loop(data.mlx->mlx);
	exit_game(&data);
	return (0);
}

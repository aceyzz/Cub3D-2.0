/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 08:59:51 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/27 11:58:09 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int argc, char **argv)
{
	t_data	data;

	// check_args(argc, argv);// Chris -> check si argument c'est bon
	// parse_data(&data, argv[1]);// Chris -> parse les données + checks
	init_mlx(&data);// ced
	init_raycaster(&data);// ced
	mlx_mouse_move(data.mlx->win, X_RES / 2, Y_RES / 2);
	mlx_hook(data.mlx->win, 2, 1L << 0, &keypress, &data);
	mlx_hook(data.mlx->win, 3, 1L << 1, &keyrelease, &data);
	mlx_hook(data.mlx->win, 17, 1L << 17, exit_game, &data);
	mlx_loop_hook(data.mlx->mlx, main_game, &data);// Boucle principale
	mlx_loop(data.mlx->mlx);
	exit_game(&data);
	return (0);
}

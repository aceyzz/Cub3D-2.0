/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:20:42 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/25 17:45:18 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
	check_params() fait les premiers checks (argv)
	init_data() parse le fichier de config et init la scene
	init_mlx() pour la fenetre et l'image
	mlx_hook():
		- close_win() pour fermer la fenetre
		- keypress() pour les touches (rota & move)
	mlx_loop_hook() pour eviter les lags, refresh l'image en continu
	
	raytracer() sera la fonction de dessin (Point d'entree du raytracing)

	mlx_loop() pour garder la fenetre ouverte
	valid_exit() pour free tout proprement
*/
int	main(int argc, char **argv)
{
	t_data	data;

	check_params(argc, argv);
	init_data(&data, argv[1]);
	init_mlx(&data);
	mlx_hook(data.mlx->win, 17, 1L << 17, close_win, &data);
	mlx_hook(data.mlx->win, 2, 1L << 0, keypress, &data);
	mlx_loop_hook(data.mlx->mlx, update_image, &data);
	// raytracer(&data);
	mlx_loop(data.mlx->mlx);
	valid_exit(&data);
	return (0);
}

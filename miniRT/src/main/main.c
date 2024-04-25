/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:20:42 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/25 12:15:01 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int argc, char **argv)
{
	t_data	data;

	check_params(argc, argv);// basique (CED)
	init_data(&data, argv[1]);// init et check des données (CED)
	// init_mlx(&data);// init de la mlx (CED)
	// A PARTIR DE LA, fonction de dessin
	// render(&data);// dessin de la scene sur l'image data->mlx->img (CHRIS)
	// mlx_put_image_to_window(data.mlx->mlx, data.mlx->win, data.mlx->img, 0, 0);// affichage de l'image (CED)
	// mlx_hook(data.mlx->win, 17, 1L << 17, close_win, &data);// gestion de la croix rouge (CED)
	// mlx_hook(data.mlx->win, 2, 1L << 0, key_hook, &data);// activation des touches pressées (CED)
	// mlx_hook(data.mlx->win, 3, 1L << 1, key_release, &data);// activation des touches relachées (CED)
	valid_exit(&data);// free et exit (CED)
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 09:00:02 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/27 10:09:41 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

// custom includes
# include "libft/libft.h"
# include "mlx/mlx.h"

// system includes
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>
# include <errno.h>
# include <limits.h>
# include <stdbool.h>

// includes by cedmulle
# include "raycasting.h"
# include "colors.h"

// includes by chris
// ...

// paramètres
# define DEBUG 1
# define X_RES 1280
# define Y_RES 720

// type de textures pour la liste chainée t_tex
typedef enum e_type
{
	NORTH = 1,
	SOUTH,
	WEST,
	EAST,
	FLOOR,
	CEIL
}	t_type;

// orientation du joueur pour t_data
typedef enum e_ori
{
	NORTH = 1,
	SOUTH,
	WEST,
	EAST
}	t_ori;

// liste chainée de toutes les textures
// le enum sert a definir a quoi elle correspond
typedef struct s_tex
{
	t_type	type;
	char	*path;
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		end;
	bool	is_rgb;
	int		rgb[3];
	t_tex	*next;
}			t_tex;

// structure de données principales
typedef struct s_data
{
	char	*filecontent;
	char	**map;
	char	**map_copy;
	int		pos_x;
	int		pos_y;
	t_ori	orientation;
	t_mlx	*mlx;
	t_tex	*tex;
}			t_data;

#endif

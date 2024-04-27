/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 09:00:02 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/27 11:42:50 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

// custom includes
# include "libft/libft.h"
# include "mlx/mlx.h"

// system includes
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// includes by cedmulle
# include "colors.h"
# include "raycasting.h"

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
}			t_type;

// orientation du joueur pour t_data
typedef enum e_ori
{
	NORTH = 1,
	SOUTH,
	WEST,
	EAST
}			t_ori;

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
	// init par Chris
	char	*filecontent;
	char	**map;
	char	**map_copy;
	int		pos_x;
	int		pos_y;
	t_ori	orientation;
	t_tex	*tex;
	// init par Ced
	t_mlx	*mlx;
	t_keys	*keys;
	t_plyr	*player;
}			t_data;

// ERROR_EXIT.C
int			error_exit(char *errmsg, char *func, t_data *data);
int			exit_game(t_data *data);

// FREE.C
void		free_ptr(void *ptr);
void		free_mlx(t_mlx *mlx);
void		free_tab(char **tab);
void		free_tex(t_tex *tex);
void		free_data(t_data *data);

// MAIN_GAME.C
void		game_loop(t_data *data);

#endif

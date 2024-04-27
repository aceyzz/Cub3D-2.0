/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:21:00 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/25 12:37:53 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

/* libft et mlx */
# include "libft/libft.h"
# include "mlx/mlx.h"

/* les headers de Ced pour la gestion de MLX */
# include "colors.h" // couleurs pour les debugs terminal
# include "xvi.h"    // pas d'inspi sur le nom, à changer

/* le ou les header de Chris pour la gestion de RT */
// # include (...)

// libs système (à compléter au fur et à mesure)
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <limits.h>

# define DEBUG 1

/*
	Ce header est le principal
	c'est seulement celui la qu'on #include dans les .c
	Ca permettra meilleure lisibilité + modularité
*/

typedef struct s_ambient
{
	double		ratio;	// entre 0 et 1
	int			rgb[3];	// entre 0 et 255
}				t_ambient;

typedef struct s_camera
{
	double		fov;			// entre 0 et 180
	double		position[3];	// x, y, z
	double		direction[3];	// x, y, z
}				t_camera;

typedef struct s_light
{
	double		ratio;			// entre 0 et 1
	double		position[3];	// x, y, z
	int			rgb[3];			// entre 0 et 255
}				t_light;

typedef struct s_plane
{
	double			position[3];	// x, y, z
	double			direction[3];	// x, y, z
	int				rgb[3];			// entre 0 et 255
	struct s_plane	*next;
	struct s_plane	*prev;
}				t_plane;

typedef struct s_sphere
{
	double			diameter;
	double			position[3];	// x, y, z : pos du centre de la sphere!
	int				rgb[3];			// entre 0 et 255
	struct s_sphere	*next;
	struct s_sphere	*prev;
}				t_sphere;

typedef struct s_cylinder
{
	double				diameter;		// entre 0 et 1
	double				height;
	double				position[3];	// x, y, z
	double				direction[3];	// x, y, z
	int					rgb[3];			// entre 0 et 255
	struct s_cylinder	*next;
	struct s_cylinder	*prev;
}				t_cylinder;

// les pl, sp et cy sont des listes chainées
// on peut en avoir plusieurs de chaque
// minimum 3 objets peu importe le type (pl, sp, cy)
typedef struct s_objs
{
	t_ambient	*ambient;	// 1 seul (mandatory)
	t_camera	*camera;	// 1 seul (mandatory)
	t_light		*light;		// 1 seul (mandatory)
	t_plane		*plane;
	t_sphere	*sphere;
	t_cylinder	*cylinder;
	int			nb_pl;		// nombre de plans
	int			nb_sp;		// nombre de spheres
	int			nb_cy;		// nombre de cylindres
}				t_objs;

typedef struct s_data
{
	t_parse		*parse;
	t_objs		*objs;
	t_mlx		*mlx;
}				t_data;

#endif

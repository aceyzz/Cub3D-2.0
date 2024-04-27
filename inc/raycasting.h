/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 09:20:04 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/27 10:15:04 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# define FOV 60

# define K_W 13
# define K_A 0
# define K_S 1
# define K_D 2
# define K_LEFT 123
# define K_RIGHT 124
# define K_ESC 53
# define K_ENTER 36

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		end;
}			t_mlx;

typedef struct s_keys
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	left;
	bool	right;
	bool	esc;
	bool	enter;
}			t_keys;

// MLX.C
void		init_mlx(t_data *data);

// ERROR_EXIT.C
int			error_exit(char *errmsg, char *func, t_data *data);

// FREE.C
void		free_ptr(void *ptr);
void		free_mlx(t_mlx *mlx);
void		free_tab(char **tab);
void		free_tex(t_tex *tex);
void		free_data(t_data *data);

#endif

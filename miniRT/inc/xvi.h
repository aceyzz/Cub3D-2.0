/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xvi.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:50:51 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/24 23:01:29 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XVI_H
# define XVI_H

# define X_RES 1280
# define Y_RES 720

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_ENTER 36

# define WHITESPACE " \t\n\v\f\r"

typedef struct s_data	t_data;

typedef struct s_mlx
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*addr;
	int					bpp;
	int					len;
	int					endian;
}						t_mlx;

typedef struct s_parse
{
	char				*filestr;
	char				**filetab;
	int					a_counter;
	int					c_counter;
	int					l_counter;
	int					sp_counter;
	int					pl_counter;
	int					cy_counter;
}						t_parse;

// EXITTERS.C
void					err_exit_void(char *msg);
void					err_exit_free(char *msg, t_data *data);
void					free_tab(char **tab);

// CHECK_ARGS.C
void					check_params(int argc, char **argv);

// UTILS.C
int						ft_iswhitespace(char c);
int						tablen(char **tab);
void					tab_trimmer(char **tab);
void					print_tab(char **tab);

// INIT_DATA.C
void					init_data_parse(t_parse *parse);

// MAIN_PARSE.C
void					init_data(t_data *data, char *filename);

#endif

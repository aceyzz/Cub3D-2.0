/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:23:31 by waziz             #+#    #+#             */
/*   Updated: 2024/04/30 22:41:42 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef struct s_data	t_data;
typedef struct s_tex	t_tex;

typedef enum e_orient
{
	N = 1,
	S,
	W,
	E
}						t_orient;

typedef struct s_check
{
	int					no;
	int					so;
	int					ea;
	int					we;
	int					f;
	int					c;
}						t_check;

typedef struct s_parse
{
	char				**params;
	char				**map;
	char				*north;
	char				*south;
	char				*east;
	char				*west;
	char				*floor;
	char				*ceil;
	int					pos_x;
	int					pos_y;
	int					frgb[3];
	int					crgb[3];
	t_data				*data;
	t_check				*check;
	t_orient			ori;
}						t_parse;

/*////////////////////////////////////////////////////////////////////////////*/
/* 		PARSING 					PARSING                      PARSING      */
/*////////////////////////////////////////////////////////////////////////////*/

// parsing.c
void					ft_parsing(t_data *data, char *filename);

// tex.c
t_tex					*init_texture(t_parse *parse);
void					init_frgb(t_tex *new, t_parse *parse);
void					init_crgb(t_tex *new, t_parse *parse);

// texture.c
t_tex					*tex_chain(t_parse *parse);

// select.c
void					north(t_tex *new, t_parse *parse);
void					south(t_tex *new, t_parse *parse);
void					east(t_tex *new, t_parse *parse);
void					west(t_tex *new, t_parse *parse);

// parse_file.c
char					**parse_file(t_data *data, char *filename);

/*////////////////////////////////////////////////////////////////////////////*/
/*     PARAMS						 PARAMS                          PARAMS   */
/*////////////////////////////////////////////////////////////////////////////*/

// fc_utils.c
int						fc_atoi(t_parse *parse, char **ws, char *s, char **tab);
int						fc_frgb(t_parse *parse, char **ws);
int						fc_crgb(t_parse *parse, char **ws);

// fc.c
int						check_last(t_parse *parse);

// nsew.c
int						first_check(t_parse *parse);
int						second_check(t_parse *parse);
int						third_check(t_parse *parse);
int						fourth_check(t_parse *parse);
int						fifth_check(t_parse *parse);

// params_init.c
char					**init_params(t_data *data, char *filename);

// params.c
int						params(t_parse *parse);

// return_params.c
int						invalid_extension(t_parse *parse, char **ws, int t);
int						invalid_name(t_parse *parse, char **ws, int t);
int						invalid_params(t_parse *parse, char **ws, int t);

/*////////////////////////////////////////////////////////////////////////////*/
/*		MAP								MAP                             MAP   */
/*////////////////////////////////////////////////////////////////////////////*/

// map_init.c
char					**error_init(char *errmsg, char *func, t_data *data);
char					**init_map(t_data *data, char *filename);

// check_map.c
int						check_one(t_parse *parse);
int						check_two(t_parse *parse);
int						check_three(t_parse *parse);
int						check_four(t_parse *parse);

// map.c
int						valid_map(t_parse *parse);

// utils.c
int						isvalid(t_parse *parse, int t, int i);
void					fix_limit(char *s, int *limit_a, int *limit_b);
int						first_n_last(t_parse *parse, char *s);
int						down_space(t_parse *parse, int t, int i);
int						up_space(t_parse *parse, int t, int i);

/*////////////////////////////////////////////////////////////////////////////*/
/*		UTILS						UTILS                           UTILS     */
/*////////////////////////////////////////////////////////////////////////////*/

// free.c
void					free_parse(t_parse *parse);

// init.c
t_check					*init_check(void);
t_parse					*parse_init(t_data *data);

// split_ws.c
char					**split_ws(char *s);

// utils
int						ft_tablen(char **s);
char					**ft_tabdup(char **tab);
int						is_void(char *s);
char					**erase_void(char **params);

#endif

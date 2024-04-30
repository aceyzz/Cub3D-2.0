/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:51:37 by waziz             #+#    #+#             */
/*   Updated: 2024/04/30 17:15:33 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_check	*init_check(void)
{
	t_check	*check;

	check = malloc(sizeof(t_check));
	if (!check)
		return (NULL);
	check->no = 0;
	check->so = 0;
	check->ea = 0;
	check->we = 0;
	check->f = 0;
	check->c = 0;
	return (check);
}

t_parse	*parse_init(t_data *data)
{
	t_parse	*parse;

	parse = malloc(sizeof(t_parse));
	if (!parse)
		error_exit("Malloc failed", "parse/init:2", NULL);
	parse->params = NULL;
	parse->map = NULL;
	parse->north = NULL;
	parse->south = NULL;
	parse->east = NULL;
	parse->west = NULL;
	parse->floor = NULL;
	parse->ceil = NULL;
	parse->pos_x = -1;
	parse->pos_y = -1;
	parse->frgb[0] = -1;
	parse->crgb[0] = -1;
	parse->data = data;
	parse->check = init_check();
	parse->ori = 0;
	return (parse);
}

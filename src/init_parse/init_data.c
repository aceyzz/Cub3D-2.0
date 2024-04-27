/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 22:21:32 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/25 12:43:30 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_data_parse(t_parse *parse)
{
	parse->filestr = NULL;
	parse->filetab = NULL;
	parse->a_counter = 0;
	parse->c_counter = 0;
	parse->l_counter = 0;
	parse->sp_counter = 0;
	parse->pl_counter = 0;
	parse->cy_counter = 0;
}

void	init_objs(t_data *data)
{
	data->objs = malloc(sizeof(t_objs));
	if (!data->objs)
		err_exit_free("Malloc error", data);
	data->objs->ambient = NULL;
	data->objs->camera = NULL;
	data->objs->light = NULL;
	data->objs->plane = NULL;
	data->objs->sphere = NULL;
	data->objs->cylinder = NULL;
}

void	export_objects_count(t_data *data)
{
	data->objs->nb_sp = data->parse->sp_counter;
	data->objs->nb_pl = data->parse->pl_counter;
	data->objs->nb_cy = data->parse->cy_counter;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:35:48 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/25 11:53:29 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	init_camera(t_data *data)
{
	data->objs->camera = malloc(sizeof(t_camera));
	if (!data->objs->camera)
		err_exit_free("Malloc error", data);
}

static void	get_pos_camera(t_data *data, char **tmp, int *ref_i)
{
	int	i;

	i = 0;
	data->objs->camera->position[0] = parse_double(tmp[i++], data);
	data->objs->camera->position[1] = parse_double(tmp[i++], data);
	data->objs->camera->position[2] = parse_double(tmp[i++], data);
	*ref_i = i;
}

static void	get_dir_camera(t_data *data, char **tmp, int *ref_i)
{
	int	i;

	i = *ref_i;
	data->objs->camera->direction[0] = parse_double(tmp[i++], data);
	data->objs->camera->direction[1] = parse_double(tmp[i++], data);
	data->objs->camera->direction[2] = parse_double(tmp[i], data);
	check_dir_values(data->objs->camera->direction, data);
}

void	parse_camera(t_data *data, char *line)
{
	char	**tmp;
	int		i;

	data->parse->c_counter++;
	if (data->parse->c_counter > 1)
		err_exit_free("Too many cameras", data);
	init_camera(data);
	tmp = ft_split(line + 1, ' ');
	if (tablen(tmp) != 7)
	{
		free_tab(tmp);
		err_exit_free("Invalid camera", data);
	}
	i = 0;
	get_pos_camera(data, tmp, &i);
	get_dir_camera(data, tmp, &i);
	data->objs->camera->fov = parse_double(tmp[tablen(tmp) - 1], data);
	free_tab(tmp);
	print_camera(data->objs->camera);
}

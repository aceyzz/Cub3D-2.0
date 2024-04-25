/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:45:54 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/25 12:06:09 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	init_cylinder(t_data *data)
{
	t_cylinder	*cylinder;

	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder)
		err_exit_free("Malloc error", data);
	if (!data->objs->cylinder)
	{
		data->objs->cylinder = cylinder;
		cylinder->next = NULL;
		cylinder->prev = NULL;
		return ;
	}
	else
	{
		cylinder->next = data->objs->cylinder;
		data->objs->cylinder->prev = cylinder;
		data->objs->cylinder = cylinder;
	}
}

static void	get_values_cylinder(t_data *data, char **tmp)
{
	int	i;

	i = 0;
	data->objs->cylinder->position[0] = parse_double(tmp[i++], data);
	data->objs->cylinder->position[1] = parse_double(tmp[i++], data);
	data->objs->cylinder->position[2] = parse_double(tmp[i++], data);
	data->objs->cylinder->direction[0] = parse_double(tmp[i++], data);
	data->objs->cylinder->direction[1] = parse_double(tmp[i++], data);
	data->objs->cylinder->direction[2] = parse_double(tmp[i++], data);
	data->objs->cylinder->diameter = parse_double(tmp[i++], data);
	data->objs->cylinder->height = parse_double(tmp[i++], data);
	if (data->objs->cylinder->diameter <= 0
		|| data->objs->cylinder->height <= 0)
		err_exit_free("Invalid cylinder (can't be negative or 0)", data);
	data->objs->cylinder->rgb[0] = parse_int(tmp[i++], data);
	data->objs->cylinder->rgb[1] = parse_int(tmp[i++], data);
	data->objs->cylinder->rgb[2] = parse_int(tmp[i], data);
	check_dir_values(data->objs->cylinder->direction, data);
	check_rgb_values(data->objs->cylinder->rgb, data);
}

void	parse_cylinder(t_data *data, char *line)
{
	char	**tmp;

	data->parse->cy_counter++;
	init_cylinder(data);
	tmp = ft_split(line + 2, ' ');
	if (tablen(tmp) != 11)
	{
		free_tab(tmp);
		err_exit_free("Invalid cylinder", data);
	}
	get_values_cylinder(data, tmp);
	free_tab(tmp);
}

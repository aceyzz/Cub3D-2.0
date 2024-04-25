/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:16:17 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/25 11:29:50 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	init_sphere(t_data *data)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		err_exit_free("Malloc error", data);
	if (!data->objs->sphere)
	{
		data->objs->sphere = sphere;
		sphere->next = NULL;
		sphere->prev = NULL;
		return ;
	}
	else
	{
		sphere->next = data->objs->sphere;
		data->objs->sphere->prev = sphere;
		data->objs->sphere = sphere;
	}
}

static void	get_values_sphere(t_data *data, char **tmp)
{
	int	i;

	i = 0;
	data->objs->sphere->position[0] = parse_double(tmp[i++], data);
	data->objs->sphere->position[1] = parse_double(tmp[i++], data);
	data->objs->sphere->position[2] = parse_double(tmp[i++], data);
	data->objs->sphere->diameter = parse_double(tmp[i++], data);
	if (data->objs->sphere->diameter <= 0)
		err_exit_free("Invalid sphere diameter", data);
	data->objs->sphere->rgb[0] = parse_int(tmp[i++], data);
	data->objs->sphere->rgb[1] = parse_int(tmp[i++], data);
	data->objs->sphere->rgb[2] = parse_int(tmp[i], data);
	check_rgb_values(data->objs->sphere->rgb, data);
}

void	parse_sphere(t_data *data, char *line)
{
	char	**tmp;

	data->parse->sp_counter++;
	init_sphere(data);
	tmp = ft_split(line + 2, ' ');
	if (tablen(tmp) != 7)
	{
		free_tab(tmp);
		err_exit_free("Invalid sphere", data);
	}
	get_values_sphere(data, tmp);
	free_tab(tmp);
	print_sphere(data->objs->sphere);
}

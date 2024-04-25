/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:31:38 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/25 11:43:08 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	init_plane(t_data *data)
{
	t_plane	*plane;

	plane = malloc(sizeof(t_plane));
	if (!plane)
		err_exit_free("Malloc error", data);
	if (!data->objs->plane)
	{
		data->objs->plane = plane;
		plane->next = NULL;
		plane->prev = NULL;
		return ;
	}
	else
	{
		plane->next = data->objs->plane;
		data->objs->plane->prev = plane;
		data->objs->plane = plane;
	}
}

static void	check_dir_plane(double dir[3], t_data *data)
{
	if (dir[0] < -1 || dir[0] > 1 || dir[1] < -1 || dir[1] > 1
		|| dir[2] < -1 || dir[2] > 1)
		err_exit_free("Invalid plane direction", data);
}

static void	get_values_plane(t_data *data, char **tmp)
{
	int	i;

	i = 0;
	data->objs->plane->position[0] = parse_double(tmp[i++], data);
	data->objs->plane->position[1] = parse_double(tmp[i++], data);
	data->objs->plane->position[2] = parse_double(tmp[i++], data);
	data->objs->plane->direction[0] = parse_double(tmp[i++], data);
	data->objs->plane->direction[1] = parse_double(tmp[i++], data);
	data->objs->plane->direction[2] = parse_double(tmp[i++], data);
	data->objs->plane->rgb[0] = parse_int(tmp[i++], data);
	data->objs->plane->rgb[1] = parse_int(tmp[i++], data);
	data->objs->plane->rgb[2] = parse_int(tmp[i], data);
	check_dir_plane(data->objs->plane->direction, data);
	check_rgb_values(data->objs->plane->rgb, data);
}

void	parse_plane(t_data *data, char *line)
{
	char	**tmp;

	data->parse->pl_counter++;
	if (data->parse->pl_counter > 1)
		err_exit_free("Too many planes", data);
	init_plane(data);
	tmp = ft_split(line + 2, ' ');
	if (tablen(tmp) != 9)
	{
		free_tab(tmp);
		err_exit_free("Invalid plane", data);
	}
	get_values_plane(data, tmp);
	free_tab(tmp);
	print_plane(data->objs->plane);
}

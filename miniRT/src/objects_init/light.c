/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:53:30 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/25 12:06:13 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	init_light(t_data *data)
{
	data->objs->light = malloc(sizeof(t_light));
	if (!data->objs->light)
		err_exit_free("Malloc error", data);
}

static void	get_values_light(t_data *data, char **tmp)
{
	int	i;

	i = 0;
	data->objs->light->position[0] = parse_double(tmp[i++], data);
	data->objs->light->position[1] = parse_double(tmp[i++], data);
	data->objs->light->position[2] = parse_double(tmp[i++], data);
	data->objs->light->ratio = parse_double(tmp[i++], data);
	if (data->objs->light->ratio < 0 || data->objs->light->ratio > 1)
		err_exit_free("Invalid light ratio", data);
	data->objs->light->rgb[0] = parse_int(tmp[i++], data);
	data->objs->light->rgb[1] = parse_int(tmp[i++], data);
	data->objs->light->rgb[2] = parse_int(tmp[i], data);
	check_rgb_values(data->objs->light->rgb, data);
}

void	parse_light(t_data *data, char *line)
{
	char	**tmp;

	data->parse->l_counter++;
	if (data->parse->l_counter > 1)
		err_exit_free("Too many lights", data);
	init_light(data);
	tmp = ft_split(line + 1, ' ');
	if (tablen(tmp) != 7)
	{
		free_tab(tmp);
		err_exit_free("Invalid light", data);
	}
	get_values_light(data, tmp);
	free_tab(tmp);
}

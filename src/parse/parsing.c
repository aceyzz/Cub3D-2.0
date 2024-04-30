/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:24:26 by waziz             #+#    #+#             */
/*   Updated: 2024/04/30 17:36:27 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	check_file(t_data *data, char *file)
{
	int	i;

	(void)data;
	if (ft_strlen(file) < 4)
		return (error_exit("Invalid argv[1]", "parsing/1:1", NULL));
	i = ft_strlen(file) - 1;
	if (file[i] != 'b' || file[i - 1] != 'u' || file[i - 2] != 'c' || file[i
			- 3] != '.')
		return (error_exit("Only extension '.cub'", "parsing/1:1", NULL));
	return (1);
}

static t_data	*transfert(t_data *data, t_parse *parse)
{
	data->map = ft_tabdup(parse->map);
	data->pos_x = parse->pos_x;
	data->pos_y = parse->pos_y;
	if (parse->ori == 1)
		data->orientation = NO;
	if (parse->ori == 2)
		data->orientation = SO;
	if (parse->ori == 3)
		data->orientation = WE;
	if (parse->ori == 4)
		data->orientation = EA;
	data->tex = tex_chain(parse);
	free_parse(parse);
	data->parse = NULL;
	return (data);
}

static void	set_orientation(t_data *data, char ori)
{
	if (ori == 'N')
		data->orientation = NO;
	if (ori == 'S')
		data->orientation = SO;
	if (ori == 'W')
		data->orientation = WE;
	if (ori == 'E')
		data->orientation = EA;
	return ;
}

static void	scan_orientation(t_data *data)
{
	int	i;
	int	k;

	i = -1;
	while (data->map[++i])
	{
		k = -1;
		while (data->map[i][++k])
		{
			if (data->map[i][k] == 'N' || data->map[i][k] == 'S'
				|| data->map[i][k] == 'W' || data->map[i][k] == 'E')
				return (set_orientation(data, data->map[i][k]));
		}
	}
}

void	ft_parsing(t_data *data, char *filename)
{
	t_parse	*parse;

	parse = NULL;
	if (check_file(data, filename))
	{
		parse = parse_init(data);
		data->parse = parse;
		parse->params = init_params(data, filename);
		parse->map = init_map(data, filename);
		if (params(parse))
			if (valid_map(parse))
				transfert(data, parse);
	}
	scan_orientation(data);
}

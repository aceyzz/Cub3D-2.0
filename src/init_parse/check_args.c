/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 22:21:03 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/25 12:31:48 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	check_params(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		return (err_exit_void("Usage: ./miniRT scene.rt"));
	if (ft_strlen(argv[1]) < 3)
		return (err_exit_void("Invalid file"));
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 3, ".rt", 3) != 0)
		return (err_exit_void("Invalid file extension"));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (err_exit_void("File not found"));
	close(fd);
}

void	check_nb_params(t_data *data)
{
	int	total;

	total = data->parse->a_counter + data->parse->c_counter
		+ data->parse->l_counter + data->parse->sp_counter
		+ data->parse->pl_counter + data->parse->cy_counter;
	if (total < 6)
		err_exit_free("Not enough objects in file (6 minimum)", data);
	if (data->parse->a_counter != 1)
		err_exit_free("Ambient light must be defined once", data);
	if (data->parse->c_counter != 1)
		err_exit_free("At least one camera must be defined", data);
	if (data->parse->l_counter != 1)
		err_exit_free("At least one light must be defined", data);
}

void	check_file(t_data *data, char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
	{
		if (ft_strlen(tab[i]) < 3 && !is_empty_line(tab[i]))
			err_exit_free("Invalid line in file", data);
		if (tab[i][0] == 'A' && is_space(tab[i][1]))
			parse_ambient(data, tab[i]);
		else if (tab[i][0] == 'C' && is_space(tab[i][1]))
			parse_camera(data, tab[i]);
		else if (tab[i][0] == 'L' && is_space(tab[i][1]))
			parse_light(data, tab[i]);
		else if (tab[i][0] == 's' && tab[i][1] == 'p' && is_space(tab[i][2]))
			parse_sphere(data, tab[i]);
		else if (tab[i][0] == 'p' && tab[i][1] == 'l' && is_space(tab[i][2]))
			parse_plane(data, tab[i]);
		else if (tab[i][0] == 'c' && tab[i][1] == 'y' && is_space(tab[i][2]))
			parse_cylinder(data, tab[i]);
		else if (is_empty_line(tab[i]))
			continue ;
		else
			err_exit_free("Invalid object in file", data);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:35:46 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/25 12:11:35 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	parse_file(t_parse *parse, char *filename)
{
	int		fd;
	int		size;
	char	c[1];

	size = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		err_exit_void("File not found");
	while (read(fd, c, 1) > 0)
		size++;
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		err_exit_void("File not found");
	parse->filestr = malloc(sizeof(char) * size + 1);
	if (!parse->filestr)
		err_exit_void("Malloc error");
	size = 0;
	while (read(fd, c, 1) > 0)
		parse->filestr[size++] = c[0];
	parse->filestr[size] = '\0';
	close(fd);
	parse->filetab = ft_split(parse->filestr, '\n');
	tab_trimmer(parse->filetab);
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

void	init_objs(t_data *data)
{
	data->objs = malloc(sizeof(t_objs));
	if (!data->objs)
		err_exit_free("Malloc error", data);
}

void	init_data(t_data *data, char *filename)
{
	t_parse	parse;

	data->parse = &parse;
	init_data_parse(&parse);
	parse_file(&parse, filename);
	if (tablen(data->parse->filetab) < 6)
		err_exit_free("Not enough objects in file (6 minimum)", data);
	init_objs(data);
	check_file(data, parse.filetab);
	free_tab(parse.filetab);
	free(parse.filestr);
	// check_data(data, parse.filetab);
	// init_params(data, parse.filetab);
	print_objs(data->objs);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:35:46 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/25 12:40:52 by cedmulle         ###   ########.fr       */
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

void	init_data(t_data *data, char *filename)
{
	t_parse	parse;

	data->parse = &parse;
	init_data_parse(&parse);
	parse_file(&parse, filename);
	init_objs(data);
	if (ft_tablen(data->parse->filetab) < 6)
		err_exit_free("Not enough objects in file (6 minimum)", data);
	check_file(data, parse.filetab);
	free_tab(parse.filetab);
	free(parse.filestr);
	check_nb_params(data);
	if (DEBUG == 1)
		print_objs(data->objs);
	export_objects_count(data);
}

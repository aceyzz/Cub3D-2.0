/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ced.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:35:46 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/24 17:30:35 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	err_exit_void(char *msg)
{
	ft_putstr_fd(REDD "Error: " YLLW, 2);
	if (msg)
		ft_putstr_fd(msg, 2);
	else
		ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n" RST, 2);
	exit(EXIT_FAILURE);
}

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		if (i % 2 == 0)
			ft_putstr_fd(GRY1, STDOUT_FILENO);
		else
			ft_putstr_fd(GRY2, STDOUT_FILENO);
		ft_putstr_fd(tab[i], STDOUT_FILENO);
		ft_putstr_fd("\n" RST, STDOUT_FILENO);
		i++;
	}
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

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

void	parse_file(t_parse *parse, char *filename)
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
}

void	init_data(t_data *data, char *filename)
{
	t_parse	parse;

	init_data_parse(&parse);
	parse_file(&parse, filename);
	// check_params(parse.filetab);
	// check_data(data, parse.filetab);
	// init_params(data, parse.filetab);
	(void)data;
	free_tab(parse.filetab);
	free(parse.filestr);
}

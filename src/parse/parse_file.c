/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 09:42:43 by waziz             #+#    #+#             */
/*   Updated: 2024/04/30 17:18:53 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	open_file(t_data *data, int *fd, char *filename)
{
	(*fd) = open(filename, O_RDONLY);
	if ((*fd) == -1)
		return (error_exit("Opening file failed", "parsing/parse/1:1", data));
	return (1);
}

static int	close_file(t_data *data, int fd)
{
	if (close(fd) == -1)
		return (error_exit("Closing file failed", "parsing/parse/1:2", data));
	return (1);
}

static int	count_characters(t_data *data, char *filename)
{
	char	buffer;
	ssize_t	isread;
	int		counter;
	int		fd;

	counter = 0;
	open_file(data, &fd, filename);
	while (1)
	{
		isread = 0;
		isread = read(fd, &buffer, 1);
		if (isread == -1)
		{
			close_file(data, fd);
			return (error_exit("Reading problem", "parsing/parse/1:3", data));
		}
		else if (isread == 0)
			break ;
		else
			counter++;
	}
	close_file(data, fd);
	if (counter <= 0)
		return (error_exit("Void file", "parsing/parse/1:3", data));
	return (counter);
}

static int	is_valid(char **file)
{
	int	t;

	t = ft_tablen(file);
	if (t >= 10)
		return (1);
	free_tab(file);
	return (0);
}

char	**parse_file(t_data *data, char *filename)
{
	char	*join_file;
	char	**file;
	char	buffer;
	int		fd;
	int		i;

	join_file = malloc((count_characters(data, filename) + 1) * sizeof(char));
	if (!join_file)
		return (error_init("Allocating Memory Failed", "parsing/parse/1:5",
				data));
	open_file(data, &fd, filename);
	i = 0;
	while (read(fd, &buffer, 1) > 0)
		join_file[i++] = buffer;
	join_file[i] = '\0';
	file = ft_split_nl(join_file);
	free(join_file);
	close_file(data, fd);
	if (!is_valid(file))
		return (error_init("Invalid File", "parsing/parse/1:5", data));
	return (file);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nsew.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:21:55 by waziz             #+#    #+#             */
/*   Updated: 2024/04/30 20:48:05 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	first_check(t_parse *parse)
{
	char	**ws;
	int		t;

	t = 0;
	while (parse->params[t])
	{
		ws = split_ws(parse->params[t]);
		if (ft_tablen(ws) != 2)
			invalid_params(parse, ws, t);
		free_tab(ws);
		t++;
	}
	return (1);
}

int	second_check(t_parse *parse)
{
	char	**ws;
	int		t;

	t = 0;
	while (parse->params[t])
	{
		ws = split_ws(parse->params[t]);
		if ((ft_strncmp(ws[0], "NO", 2) == 0 && ws[0][2] == '\0')
			|| (ft_strncmp(ws[0], "SO", 2) == 0 && ws[0][2] == '\0')
			|| (ft_strncmp(ws[0], "EA", 2) == 0 && ws[0][2] == '\0')
			|| (ft_strncmp(ws[0], "WE", 2) == 0 && ws[0][2] == '\0')
			|| (ft_strncmp(ws[0], "F", 1) == 0 && ws[0][1] == '\0')
			|| (ft_strncmp(ws[0], "C", 1) == 0 && ws[0][1] == '\0'))
			free_tab(ws);
		else
			invalid_name(parse, ws, t);
		t++;
	}
	return (1);
}

int	third_check(t_parse *parse)
{
	char	**ws;
	int		t;
	int		i;

	t = 0;
	while (parse->params[t])
	{
		ws = split_ws(parse->params[t]);
		if ((ft_strncmp(ws[0], "F", 1) == 0 && ws[0][1] == '\0')
			|| (ft_strncmp(ws[0], "C", 1) == 0 && ws[0][1] == '\0'))
			free_tab(ws);
		else
		{
			i = ft_strlen(ws[1]) - 1;
			if (ws[1][i] == 'm' && ws[1][i - 1] == 'p' && ws[1][i - 2] == 'x'
				&& ws[1][i - 3] == '.')
				free_tab(ws);
			else
				invalid_extension(parse, ws, t);
		}
		t++;
	}
	return (1);
}

int	fourth_check(t_parse *parse)
{
	char	**ws;
	int		t;

	t = 0;
	while (parse->params[t])
	{
		ws = split_ws(parse->params[t]);
		if (ft_strncmp(ws[0], "NO", 2) == 0 && ws[0][2] == '\0')
			parse->check->no++;
		if (ft_strncmp(ws[0], "SO", 2) == 0 && ws[0][2] == '\0')
			parse->check->so++;
		if (ft_strncmp(ws[0], "EA", 2) == 0 && ws[0][2] == '\0')
			parse->check->ea++;
		if (ft_strncmp(ws[0], "WE", 2) == 0 && ws[0][2] == '\0')
			parse->check->we++;
		free_tab(ws);
		t++;
	}
	if (parse->check->no != 1 || parse->check->so != 1 || parse->check->ea != 1
		|| parse->check->we != 1)
		return (error_exit("Similar setting detected", "parsing/params/3:4",
				parse->data));
	return (1);
}

int	fifth_check(t_parse *parse)
{
	char	**ws;
	int		t;
	int		fd;

	t = -1;
	while (parse->params[++t])
	{
		ws = split_ws(parse->params[t]);
		if (ft_strncmp(ws[0], "F", 1) != 0 && ft_strncmp(ws[0], "C", 1) != 0)
		{
			fd = open(ws[1], O_RDONLY);
			if (fd == -1)
			{
				free_tab(ws);
				return (error_exit("Invalid file path", "parsing/params/3:5",
						parse->data));
			}
			free_tab(ws);
			if (close(fd) == -1)
				return (error_exit("Closing file failed", "parsing/params/3:5",
						parse->data));
		}
		else
			free_tab(ws);
	}
	return (1);
}

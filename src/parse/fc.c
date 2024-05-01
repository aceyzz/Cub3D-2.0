/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:55:09 by waziz             #+#    #+#             */
/*   Updated: 2024/04/30 23:15:45 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	check_path(t_parse *parse, char **ws)
{
	int	fd;

	fd = open(ws[1], O_RDONLY);
	if (fd == -1)
	{
		printf("file path : %s\n", ws[1]);
		free_tab(ws);
		return (error_exit("Invalid file path", NULL, parse->data));
	}
	if (close(fd) == -1)
	{
		free_tab(ws);
		return (error_exit("Closing file failed", NULL, parse->data));
	}
	return (1);
}

static void	check_fextension(t_parse *parse)
{
	char	**ws;
	int		t;
	int		i;

	t = -1;
	while (parse->params[++t])
	{
		ws = split_ws(parse->params[t]);
		if (ft_strncmp(ws[0], "F", 1) == 0 && ws[0][1] == '\0')
		{
			i = ft_strlen(ws[1]) - 1;
			if (ws[1][i] == 'm' && ws[1][i - 1] == 'p' && ws[1][i - 2] == 'x'
				&& ws[1][i - 3] == '.')
			{
				if (check_path(parse, ws))
					parse->floor = ft_strdup(ws[1]);
				free_tab(ws);
				return ;
			}
			fc_frgb(parse, ws);
			free_tab(ws);
			return ;
		}
		free_tab(ws);
	}
}

static void	check_cextension(t_parse *parse)
{
	char	**ws;
	int		t;
	int		i;

	t = -1;
	while (parse->params[++t])
	{
		ws = split_ws(parse->params[t]);
		if (ft_strncmp(ws[0], "C", 1) == 0 && ws[0][1] == '\0')
		{
			i = ft_strlen(ws[1]) - 1;
			if (ws[1][i] == 'm' && ws[1][i - 1] == 'p' && ws[1][i - 2] == 'x'
				&& ws[1][i - 3] == '.')
			{
				if (check_path(parse, ws))
					parse->ceil = ft_strdup(ws[1]);
				free_tab(ws);
				return ;
			}
			fc_crgb(parse, ws);
			free_tab(ws);
			return ;
		}
		free_tab(ws);
	}
}

int	check_last(t_parse *parse)
{
	char	**ws;
	int		t;

	t = 0;
	while (parse->params[t])
	{
		ws = split_ws(parse->params[t]);
		if (ft_strncmp(ws[0], "F", 1) == 0 && ws[0][1] == '\0')
			parse->check->f++;
		if (ft_strncmp(ws[0], "C", 1) == 0 && ws[0][1] == '\0')
			parse->check->c++;
		free_tab(ws);
		t++;
	}
	if (parse->check->f != 1 || parse->check->c != 1)
		return (error_exit("Similar setting detected", NULL, parse->data));
	check_fextension(parse);
	check_cextension(parse);
	return (1);
}

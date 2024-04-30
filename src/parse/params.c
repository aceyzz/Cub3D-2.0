/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 23:31:14 by waziz             #+#    #+#             */
/*   Updated: 2024/04/30 15:15:13 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	valid_params(t_parse *parse)
{
	if (first_check(parse))
		if (second_check(parse))
			if (third_check(parse))
				if (fourth_check(parse))
					if (fifth_check(parse))
						return (1);
	return (0);
}

static void	rinit_check(t_parse *parse)
{
	free(parse->check);
	parse->check = init_check();
}

int	params(t_parse *parse)
{
	char	**ws;
	int		t;

	ws = NULL;
	if (valid_params(parse))
	{
		t = 0;
		while (parse->params[t])
		{
			ws = split_ws(parse->params[t]);
			if (ft_strncmp(ws[0], "NO", 2) == 0 && ws[0][2] == '\0')
				parse->north = ft_strdup(ws[1]);
			if (ft_strncmp(ws[0], "SO", 2) == 0 && ws[0][2] == '\0')
				parse->south = ft_strdup(ws[1]);
			if (ft_strncmp(ws[0], "EA", 2) == 0 && ws[0][2] == '\0')
				parse->east = ft_strdup(ws[1]);
			if (ft_strncmp(ws[0], "WE", 2) == 0 && ws[0][2] == '\0')
				parse->west = ft_strdup(ws[1]);
			free_tab(ws);
			t++;
		}
		check_last(parse);
	}
	rinit_check(parse);
	return (1);
}

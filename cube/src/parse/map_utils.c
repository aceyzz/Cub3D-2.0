/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:17:29 by waziz             #+#    #+#             */
/*   Updated: 2024/05/19 15:15:55 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	isvalid(t_parse *parse, int t, int i)
{
	if (parse->map[t][i] == ' ' || parse->map[t][i] == '1'
		|| parse->map[t][i] == '0' || parse->map[t][i] == 'N'
		|| parse->map[t][i] == 'S' || parse->map[t][i] == 'E'
		|| parse->map[t][i] == 'W')
	{
		if (parse->map[t][i] == 'N' || parse->map[t][i] == 'S'
			|| parse->map[t][i] == 'E' || parse->map[t][i] == 'W')
		{
			parse->pos_y = t;
			parse->pos_x = i;
		}
		if (parse->map[t][i] == 'N')
			parse->check->no++;
		if (parse->map[t][i] == 'S')
			parse->check->so++;
		if (parse->map[t][i] == 'E')
			parse->check->ea++;
		if (parse->map[t][i] == 'W')
			parse->check->we++;
		return (1);
	}
	return (0);
}

void	fix_limit(char *s, int *limit_a, int *limit_b)
{
	int	i;

	i = 0;
	while (s[i] && s[i] == 32)
		i++;
	(*limit_a) = i;
	i = ft_strlen(s) - 1;
	while (i > 0 && s[i] == 32)
		i--;
	(*limit_b) = i;
}

int	first_n_last(t_parse *parse, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == 32 || s[i] == '1')
			i++;
		else
			return (error_exit("Invalid map 1", NULL, parse->data));
	}
	return (1);
}

int	down_space(t_parse *parse, int t, int i)
{
	while (parse->map[t] && parse->map[t][i] == 32)
		t++;
	if (!parse->map[t])
		return (1);
	if (parse->map[t][i] != '1')
		return (error_exit("Invalid map 2", NULL, parse->data));
	return (1);
}

int	up_space(t_parse *parse, int t, int i)
{
	while (parse->map[t][i] == 32 && t > 0)
		t--;
	if (t == 0)
		return (1);
	if (parse->map[t][i] != '1' && parse->map[t][i] != '\n'
		&& parse->map[t][i] != '\0')
		return (error_exit("Invalid map 3", NULL, parse->data));
	return (1);
}

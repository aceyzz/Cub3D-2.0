/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:27:37 by waziz             #+#    #+#             */
/*   Updated: 2024/05/19 15:12:24 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	check_one(t_parse *parse)
{
	int	t;
	int	i;
	int	player;

	t = 0;
	while (parse->map[t])
	{
		i = 0;
		while (parse->map[t][i])
		{
			if (!isvalid(parse, t, i))
			{
				printf("Invalid character : %c\n", parse->map[t][i]);
				return (error_exit("Invalid map", NULL, parse->data));
			}
			i++;
		}
		t++;
	}
	player = parse->check->no + parse->check->so + parse->check->ea
		+ parse->check->we;
	if (player != 1)
		return (error_exit("Only one player", NULL, parse->data));
	return (1);
}

int	check_two(t_parse *parse)
{
	int	limit_a;
	int	limit_b;
	int	y;

	y = parse->pos_y;
	if (y == 0 || y == (ft_tablen(parse->map) - 1))
		return (error_exit("Player in the Wall", NULL, parse->data));
	fix_limit(parse->map[y], &limit_a, &limit_b);
	if (parse->pos_x < limit_a || parse->pos_x > limit_b)
		return (error_exit("Player hors limit", NULL, parse->data));
	return (1);
}

int	check_three(t_parse *parse)
{
	int	limit_a;
	int	limit_b;
	int	t;

	t = 0;
	if (first_n_last(parse, parse->map[t]))
		t++;
	while (parse->map[t])
	{
		fix_limit(parse->map[t], &limit_a, &limit_b);
		if (parse->map[t][limit_a] != '1' || parse->map[t][limit_b] != '1')
			return (error_exit("Invalid map", NULL, parse->data));
		t++;
	}
	t--;
	if (first_n_last(parse, parse->map[t]))
		return (1);
	return (42);
}

static int	valid_space(t_parse *parse, int t, int ia)
{
	if ((parse->map[t][ia - 1] == 32 || parse->map[t][ia - 1] == '1')
		&& (parse->map[t][ia + 1] == 32 || parse->map[t][ia + 1] == '1'))
	{
		if (down_space(parse, t, ia))
			if (up_space(parse, t, ia))
				return (1);
	}
	return (0);
}

int	check_four(t_parse *parse)
{
	int	ia;
	int	ib;
	int	t;

	t = 0;
	while (parse->map[t])
	{
		fix_limit(parse->map[t], &ia, &ib);
		while (ia < ib)
		{
			if (parse->map[t][ia] == 32)
			{
				if (!valid_space(parse, t, ia))
					return (error_exit("Invalid map", NULL, parse->data));
			}
			ia++;
		}
		t++;
	}
	free(parse->check);
	parse->check = NULL;
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 22:11:18 by waziz             #+#    #+#             */
/*   Updated: 2024/04/30 22:44:07 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	only_digit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	check_rgb_vals(t_parse *parse, int *rgb)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		if (rgb[i] < 0 || rgb[i] > 255)
			error_exit("Invalid rgb", "parsing/params/1:3", parse->data);
	}
}

static int	parse_int(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		res = (str[i] - 48) + (res * 10);
		i++;
	}
	return (res);
}

int	fc_crgb(t_parse *parse, char **ws)
{
	char	**tab;

	tab = ft_split(ws[1], ',');
	if (ft_tablen(tab) != 3)
	{
		free_tab(tab);
		free_tab(ws);
		error_exit("Invalid rgb", "parsing/params/1:3", parse->data);
	}
	if (!only_digit(tab[0]) || !only_digit(tab[1]) || !only_digit(tab[2]))
	{
		free_tab(tab);
		free_tab(ws);
		error_exit("Invalid rgb", "parsing/params/1:3", parse->data);
	}
	parse->crgb[0] = parse_int(tab[0]);
	parse->crgb[1] = parse_int(tab[1]);
	parse->crgb[2] = parse_int(tab[2]);
	free_tab(tab);
	check_rgb_vals(parse, parse->crgb);
	return (1);
}

int	fc_frgb(t_parse *parse, char **ws)
{
	char	**tab;

	tab = ft_split(ws[1], ',');
	if (ft_tablen(tab) != 3)
	{
		free_tab(tab);
		free_tab(ws);
		error_exit("Invalid rgb", "parsing/params/1:3", parse->data);
	}
	if (!only_digit(tab[0]) || !only_digit(tab[1]) || !only_digit(tab[2]))
	{
		free_tab(tab);
		error_exit("Invalid rgb", "parsing/params/1:3", parse->data);
	}
	parse->frgb[0] = parse_int(tab[0]);
	parse->frgb[1] = parse_int(tab[1]);
	parse->frgb[2] = parse_int(tab[2]);
	free_tab(tab);
	check_rgb_vals(parse, parse->frgb);
	return (1);
}

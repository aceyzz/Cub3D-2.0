/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 22:11:18 by waziz             #+#    #+#             */
/*   Updated: 2024/04/30 21:21:36 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	invalid_rgb(t_parse *parse, char **ws, char **tab)
{
	free_tab(ws);
	free_tab(tab);
	error_exit("Invalid rgb", "parsing/params/1:3", parse->data);
}

int	fc_atoi(t_parse *parse, char **ws, char *s, char **tab)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (s[i])
	{
		res = (s[i] - 48) + (res * 10);
		i++;
	}
	if (res < 0 || res > 255)
		invalid_rgb(parse, ws, tab);
	return (res);
}

int	only_digit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

int	fc_frgb(t_parse *parse, char **ws)
{
	char	**tab;
	int		t;

	tab = ft_split(ws[1], ',');
	if (!tab || ft_tablen(tab) != 3)
		invalid_rgb(parse, ws, tab);
	t = -1;
	while (tab[++t])
	{
		if (!only_digit(tab[t]))
			invalid_rgb(parse, ws, tab);
	}
	parse->frgb[0] = fc_atoi(parse, ws, tab[0], tab);
	parse->frgb[1] = fc_atoi(parse, ws, tab[1], tab);
	parse->frgb[2] = fc_atoi(parse, ws, tab[2], tab);
	free(tab);
	return (1);
}

int	fc_crgb(t_parse *parse, char **ws)
{
	char	**tab;
	int		t;

	tab = ft_split(ws[1], ',');
	if (!tab || ft_tablen(tab) != 3)
		invalid_rgb(parse, ws, tab);
	t = -1;
	while (tab[++t])
	{
		if (!only_digit(tab[t]))
			invalid_rgb(parse, ws, tab);
	}
	parse->crgb[0] = fc_atoi(parse, ws, tab[0], tab);
	parse->crgb[1] = fc_atoi(parse, ws, tab[1], tab);
	parse->crgb[2] = fc_atoi(parse, ws, tab[2], tab);
	free(tab);
	return (1);
}

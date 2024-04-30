/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 22:11:18 by waziz             #+#    #+#             */
/*   Updated: 2024/04/30 17:37:49 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	fc_atoi(t_parse *parse, char **ws, char *s)
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
	{
		free_tab(ws);
		return (error_exit("RGB number invalid", "parsing/params/1:1",
				parse->data));
	}
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
	{
		free_tab(ws);
		if (tab)
			free_tab(tab);
		return (error_exit("Invalid rgb", "parsing/params/1:3", parse->data));
	}
	t = -1;
	while (tab[++t])
	{
		if (!only_digit(tab[t]))
		{
			free_tab(ws);
			free_tab(tab);
			return (error_exit("Invalid rgb", "parsing/params/1:3",
					parse->data));
		}
	}
	parse->frgb[0] = fc_atoi(parse, ws, tab[0]);
	parse->frgb[1] = fc_atoi(parse, ws, tab[1]);
	parse->frgb[2] = fc_atoi(parse, ws, tab[2]);
	free(tab);
	return (1);
}

int	fc_crgb(t_parse *parse, char **ws)
{
	char	**tab;
	int		t;

	tab = ft_split(ws[1], ',');
	if (!tab || ft_tablen(tab) != 3)
	{
		free_tab(ws);
		if (tab)
			free_tab(tab);
		return (error_exit("Invalid rgb", "parsing/params/1:3", parse->data));
	}
	t = -1;
	while (tab[++t])
	{
		if (!only_digit(tab[t]))
		{
			free_tab(ws);
			free_tab(tab);
			return (error_exit("Invalid rgb", "parsing/params/1:3",
					parse->data));
		}
	}
	parse->crgb[0] = fc_atoi(parse, ws, tab[0]);
	parse->crgb[1] = fc_atoi(parse, ws, tab[1]);
	parse->crgb[2] = fc_atoi(parse, ws, tab[2]);
	free(tab);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 22:19:11 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/25 12:42:04 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	commas_to_spaces(char **tab)
{
	int	i;
	int	k;

	i = -1;
	while (tab[++i])
	{
		k = 0;
		while (tab[i][k])
		{
			if (tab[i][k] == ',')
				tab[i][k] = ' ';
			k++;
		}
	}
}

void	tab_trimmer(char **tab)
{
	int		i;
	char	*tmp;

	i = -1;
	while (tab[++i])
	{
		if (tab[i][0] != '\0')
		{
			tmp = ft_strtrim(tab[i], WHITESPACE);
			free(tab[i]);
			tab[i] = ft_strdup(tmp);
			free(tmp);
		}
	}
	commas_to_spaces(tab);
}

int	is_empty_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!is_space(str[i]))
			return (0);
		i++;
	}
	return (1);
}

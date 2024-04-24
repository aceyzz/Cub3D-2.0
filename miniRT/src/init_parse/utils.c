/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 22:19:11 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/24 22:20:11 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	ft_iswhitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

int	tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
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
}

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		if (i % 2 == 0)
			ft_putstr_fd(GRY1, STDOUT_FILENO);
		else
			ft_putstr_fd(GRY2, STDOUT_FILENO);
		ft_putstr_fd(tab[i], STDOUT_FILENO);
		ft_putstr_fd("\n" RST, STDOUT_FILENO);
		i++;
	}
}

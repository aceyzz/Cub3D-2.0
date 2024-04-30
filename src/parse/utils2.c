/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:56:58 by waziz             #+#    #+#             */
/*   Updated: 2024/04/30 16:45:48 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_tablen(char **s)
{
	int	t;

	if (!s)
		return (0);
	t = 0;
	while (s[t])
		t++;
	return (t);
}

char	**ft_tabdup(char **tab)
{
	char	**dup;
	int		t;

	if (!tab)
		return (NULL);
	dup = malloc((ft_tablen(tab) + 1) * sizeof(char *));
	if (!dup)
		return (NULL);
	t = 0;
	while (tab[t])
	{
		dup[t] = ft_strdup(tab[t]);
		t++;
	}
	dup[t] = NULL;
	return (dup);
}

int	is_void(char *s)
{
	int	i;

	if (!s)
		return (1);
	i = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '\0')
		return (1);
	return (0);
}

static char	**erasing(char **params, int t)
{
	char	*f;

	f = params[t];
	while (params[t])
	{
		params[t] = params[t + 1];
		t++;
	}
	free(f);
	return (params);
}

char	**erase_void(char **params)
{
	int	t;

	t = 0;
	while (params[t])
	{
		if (is_void(params[t]))
			params = erasing(params, t);
		else
			t++;
	}
	if (t == 0)
		return (error_init("Non-compliant file", "parsing/utils/4:5", NULL));
	return (params);
}

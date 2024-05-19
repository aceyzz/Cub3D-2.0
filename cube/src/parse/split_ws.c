/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_ws.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 13:25:54 by waziz             #+#    #+#             */
/*   Updated: 2024/04/30 23:15:45 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	is_ws(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static int	count_word(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (is_ws(s[i]))
			i++;
		if (s[i] && !is_ws(s[i]))
			count++;
		while (s[i] && !is_ws(s[i]))
			i++;
	}
	return (count);
}

char	**split_ws(char *s)
{
	char	**ws;
	int		t;
	int		i;
	int		start;

	ws = malloc((count_word(s) + 1) * sizeof(char *));
	if (!ws)
		return (error_init("Malloc Failed", NULL, NULL));
	i = 0;
	t = 0;
	while (s[i])
	{
		while (is_ws(s[i]))
			i++;
		if (s[i] && !is_ws(s[i]))
			start = i;
		while (s[i] && !is_ws(s[i]))
			i++;
		ws[t++] = ft_substr(s, start, i);
	}
	ws[t] = NULL;
	return (ws);
}

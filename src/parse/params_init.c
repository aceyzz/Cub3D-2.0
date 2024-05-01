/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:02:37 by waziz             #+#    #+#             */
/*   Updated: 2024/05/01 11:22:29 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	free_from_index(char **tab, int index)
{
	while (tab[index])
	{
		free(tab[index]);
		tab[index] = NULL;
		index++;
	}
}

char	**init_params(t_data *data, char *filename)
{
	char	**params;
	char	**file;
	int		t;

	file = parse_file(data, filename);
	t = ft_tablen(file);
	while (is_void(file[t]))
		t--;
	while (t >= 0)
		if (is_void(file[t--]))
			break ;
	free_from_index(file, t + 1);
	params = ft_tabdup(file);
	free_tab(file);
	if (!params)
		return (error_init("Malloc Failed", NULL, data));
	params = erase_void(params);
	if (ft_tablen(params) != 6)
	{
		free_tab(params);
		return (error_init("Non-compliant file", NULL, data));
	}
	return (params);
}

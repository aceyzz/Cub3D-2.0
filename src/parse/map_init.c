/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:22:19 by waziz             #+#    #+#             */
/*   Updated: 2024/04/30 20:35:42 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

char	**error_init(char *errmsg, char *func, t_data *data)
{
	error_exit(errmsg, func, data);
	return (NULL);
}

char	**init_map(t_data *data, char *filename)
{
	char	**map;
	char	**file;
	int		t;
	int		i;

	file = parse_file(data, filename);
	t = ft_tablen(file);
	while (is_void(file[t]))
		t--;
	while (t >= 0)
		if (is_void(file[t--]))
			break ;
	if (t < 6)
	{
		free_tab(file);
		return (error_init("Non-compliant file", "parsing/map/2:1", data));
	}
	map = malloc((ft_tablen(file) - t) * sizeof(char *));
	if (!map)
		return (error_init("Allocated Memory Failed", "parsing/map/2:1", data));
	i = 0;
	t += 1;
	while (file[t])
		map[i++] = ft_strdup(file[t++]);
	map[i] = NULL;
	map = erase_void(map);
	free_tab(file);
	return (map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:22:19 by waziz             #+#    #+#             */
/*   Updated: 2024/04/30 15:18:46 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

char	**error_init(char *errmsg, char *func, t_data *data)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(errmsg, 2);
	if (func)
	{
		ft_putstr_fd(" in function ", 2);
		ft_putstr_fd(func, 2);
	}
	ft_putstr_fd("\n", 2);
	if (data)
		free_data(data);
	exit(EXIT_FAILURE);
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
		return (error_init("Non-compliant file", "parsing/map/2:1", data));
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

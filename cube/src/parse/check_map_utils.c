/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 13:10:03 by cedmulle          #+#    #+#             */
/*   Updated: 2024/05/19 14:48:29 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	find_big_line(char **map_copy)
{
	int	i;
	int	j;
	int	biggest;

	i = 0;
	biggest = ft_strlen(map_copy[i]);
	while (map_copy[i])
	{
		j = ft_strlen(map_copy[i]);
		if (j > biggest)
			biggest = j;
		i++;
	}
	return (biggest);
}

static char	*fill_space(char *str, int size)
{
	char	*result;
	int		i;

	result = malloc(sizeof(char) * (size + 1));
	i = -1;
	while (str[++i])
		result[i] = str[i];
	while (i < size)
		result[i++] = ' ';
	result[i] = '\0';
	free(str);
	return (result);
}

static void	map_resizer(char **map_copy)
{
	size_t	biggest;
	int		i;

	biggest = find_big_line(map_copy);
	i = 0;
	while (map_copy[i])
	{
		if (ft_strlen(map_copy[i]) < biggest)
			map_copy[i] = fill_space(map_copy[i], (int)biggest);
		i++;
	}
}

static void	player_surrounded_by_wall(char **map, int x, int y, t_data *data)
{
	int	limit_x;
	int	limit_y;

	limit_x = ft_strlen(map[y]);
	limit_y = ft_tablen(map);
	if (x < 0 || y < 0 || x >= limit_x || y >= limit_y)
		return ;
	if (map[y][x] == '1' || map[y][x] == '2')
		return ;
	if (map[y][x] != '0' && map[y][x] != 'N' && map[y][x] != 'S' &&
		map[y][x] != 'E' && map[y][x] != 'W' && map[y][x] != '2')
		error_exit("Player is not surrounded by walls", NULL, data);
	if (map[y][x] == ' ')
		error_exit("Player is not surrounded by walls", NULL, data);
	map[y][x] = '2';
	player_surrounded_by_wall(map, x + 1, y, data);
	player_surrounded_by_wall(map, x - 1, y, data);
	player_surrounded_by_wall(map, x, y + 1, data);
	player_surrounded_by_wall(map, x, y - 1, data);
}

void	check_map_final(t_data *data)
{
	char	**map_copy;

	map_copy = ft_tabdup(data->map);
	map_resizer(map_copy);
	player_surrounded_by_wall(map_copy, data->pos_x, data->pos_y, data);
	free_tab(map_copy);
}

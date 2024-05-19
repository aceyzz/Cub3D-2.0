/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:25:49 by waziz             #+#    #+#             */
/*   Updated: 2024/04/30 17:13:48 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	free_parse(t_parse *parse)
{
	if (parse)
	{
		if (parse->map)
			free_tab(parse->map);
		if (parse->params)
			free_tab(parse->params);
		if (parse->north)
			free_ptr(parse->north);
		if (parse->south)
			free_ptr(parse->south);
		if (parse->east)
			free_ptr(parse->east);
		if (parse->west)
			free_ptr(parse->west);
		if (parse->floor)
			free_ptr(parse->floor);
		if (parse->ceil)
			free_ptr(parse->ceil);
		if (parse->check)
			free_ptr(parse->check);
		free_ptr(parse);
	}
}

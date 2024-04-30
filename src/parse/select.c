/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:18:36 by waziz             #+#    #+#             */
/*   Updated: 2024/04/30 17:40:41 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	north(t_tex *new, t_parse *parse)
{
	new->type = NORTH;
	new->path = ft_strdup(parse->north);
	free(parse->north);
	parse->north = NULL;
}

void	south(t_tex *new, t_parse *parse)
{
	new->type = SOUTH;
	new->path = ft_strdup(parse->south);
	free(parse->south);
	parse->south = NULL;
}

void	east(t_tex *new, t_parse *parse)
{
	new->type = EAST;
	new->path = ft_strdup(parse->east);
	free(parse->east);
	parse->east = NULL;
}

void	west(t_tex *new, t_parse *parse)
{
	new->type = WEST;
	new->path = ft_strdup(parse->west);
	free(parse->west);
	parse->west = NULL;
}

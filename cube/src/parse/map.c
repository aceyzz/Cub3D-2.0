/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 20:52:51 by waziz             #+#    #+#             */
/*   Updated: 2024/04/30 17:41:17 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	valid_map(t_parse *parse)
{
	if (check_one(parse))
		if (check_two(parse))
			if (check_three(parse))
				if (check_four(parse))
					return (1);
	return (0);
}

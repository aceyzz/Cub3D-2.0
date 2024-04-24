/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 22:21:32 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/24 22:26:55 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_data_parse(t_parse *parse)
{
	parse->filestr = NULL;
	parse->filetab = NULL;
	parse->a_counter = 0;
	parse->c_counter = 0;
	parse->l_counter = 0;
	parse->sp_counter = 0;
	parse->pl_counter = 0;
	parse->cy_counter = 0;
}

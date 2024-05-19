/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 23:04:24 by waziz             #+#    #+#             */
/*   Updated: 2024/04/30 23:15:45 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static t_tex	*error_tex(char *errmsg, char *func, t_data *data)
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

t_tex	*init_texture(t_parse *parse)
{
	t_tex	*texture;

	texture = malloc(sizeof(t_tex));
	if (!texture)
		return (error_tex("Malloc Failed", NULL, parse->data));
	texture->type = 0;
	texture->path = NULL;
	texture->is_rgb = false;
	texture->next = NULL;
	return (texture);
}

void	init_frgb(t_tex *new, t_parse *parse)
{
	new->rgb[0] = parse->frgb[0];
	new->rgb[1] = parse->frgb[1];
	new->rgb[2] = parse->frgb[2];
}

void	init_crgb(t_tex *new, t_parse *parse)
{
	new->rgb[0] = parse->crgb[0];
	new->rgb[1] = parse->crgb[1];
	new->rgb[2] = parse->crgb[2];
}

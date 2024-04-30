/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:52:19 by waziz             #+#    #+#             */
/*   Updated: 2024/04/30 17:40:22 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static t_tex	*init_nsew(t_parse *parse)
{
	t_tex	*new;

	new = init_texture(parse);
	if (parse->north)
	{
		north(new, parse);
		return (new);
	}
	if (parse->south)
	{
		south(new, parse);
		return (new);
	}
	if (parse->east)
	{
		east(new, parse);
		return (new);
	}
	if (parse->west)
	{
		west(new, parse);
		return (new);
	}
	free(new);
	return (NULL);
}

static t_tex	*init_f(t_parse *parse)
{
	t_tex	*new;

	new = init_texture(parse);
	if (parse->floor)
	{
		new->type = FLOOR;
		new->path = ft_strdup(parse->floor);
		free(parse->floor);
		parse->floor = NULL;
		return (new);
	}
	if (!parse->floor)
	{
		if (parse->frgb[0] != -1)
		{
			new->type = FLOOR;
			new->is_rgb = true;
			init_frgb(new, parse);
			parse->frgb[0] = -1;
			return (new);
		}
	}
	free(new);
	return (NULL);
}

static t_tex	*init_c(t_parse *parse)
{
	t_tex	*new;

	new = init_texture(parse);
	if (parse->ceil)
	{
		new->type = CEIL;
		new->path = ft_strdup(parse->ceil);
		free(parse->ceil);
		parse->ceil = NULL;
		return (new);
	}
	if (!parse->ceil)
	{
		if (parse->crgb[0] != -1)
		{
			new->type = CEIL;
			new->is_rgb = true;
			init_crgb(new, parse);
			parse->crgb[0] = -1;
			return (new);
		}
	}
	free(new);
	return (NULL);
}

static t_tex	*which_init(t_parse *parse)
{
	t_tex	*new;

	new = init_nsew(parse);
	if (!new)
	{
		new = init_f(parse);
		if (!new)
		{
			new = init_c(parse);
			if (!new)
				return (NULL);
		}
	}
	return (new);
}

t_tex	*tex_chain(t_parse *parse)
{
	t_tex	*head;
	t_tex	*new;
	t_tex	*current;
	int		count;

	count = 0;
	current = NULL;
	while (count < 6)
	{
		new = which_init(parse);
		if (current)
			current->next = new;
		else
			head = new;
		current = new;
		count++;
	}
	if (current)
		current->next = NULL;
	return (head);
}

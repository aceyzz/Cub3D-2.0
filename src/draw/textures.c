/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:21:37 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/27 23:21:04 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_tex	*get_tex(t_tex *tex, t_type type)
{
	while (tex)
	{
		if (tex->type == type)
			return (tex);
		tex = tex->next;
	}
	return (NULL);
}

int	calc_tex_x(t_data *data, t_ray *ray)
{
	int	wall_x;
	int	tex_x;

	if (ray->side == 0)
		wall_x = data->player->pos_y + ray->perp_wall_dist * ray->dir_y;
	else
		wall_x = data->player->pos_x + ray->perp_wall_dist * ray->dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)TSIZE);
	if (ray->side == 0 && ray->dir_x > 0)
		tex_x = TSIZE - tex_x - 1;
	if (ray->side == 1 && ray->dir_y < 0)
		tex_x = TSIZE - tex_x - 1;
	return (tex_x);
}

int	calc_tex_y(t_ray *ray, int y)
{
	int	tex_y;
	int	d;

	d = y * TSIZE - Y_RES * (TSIZE / 2) + ray->line_height * (TSIZE / 2);
	tex_y = ((d * TSIZE) / ray->line_height) / TSIZE;
	return (tex_y);
}

t_tex	*which_tex(t_data *data, t_ray *ray)
{
	if (ray->side == 1 && ray->dir_y < 0)
		return (get_tex(data->tex, NORTH));
	else if (ray->side == 1 && ray->dir_y > 0)
		return (get_tex(data->tex, SOUTH));
	else if (ray->side == 0 && ray->dir_x < 0)
		return (get_tex(data->tex, WEST));
	else
		return (get_tex(data->tex, EAST));
}

unsigned int	get_tex_color(t_data *data, t_ray *ray, int tex_x, int tex_y)
{
	t_tex			*tex;
	unsigned int	index;

	tex = which_tex(data, ray);
	if (tex == NULL)
		error_exit("Texture not found", "get_tex_color", data);
	tex_x = fmax(0, fmin(tex_x, TSIZE - 1));
	tex_y = fmax(0, fmin(tex_y, TSIZE - 1));
	index = tex_y * tex->len + tex_x * (tex->bpp / 8);
	return (*(unsigned int *)(tex->addr + index));
}

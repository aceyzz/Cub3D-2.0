/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:24:50 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/30 13:54:15 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	calc_tex_y(t_data *data, t_ray *ray, int y)
{
	int	tex_y;
	int	d;

	(void)data;
	d = y * TSIZE - Y_RES * TSIZE / 2 + ray->line_height * TSIZE / 2;
	tex_y = ((d * TSIZE) / ray->line_height) / TSIZE;
	return (tex_y);
}

static int	calc_tex_x(t_data *data, t_ray *ray)
{
	double	wall_x;
	int		tex_x;

	if (ray->side == 0)
		wall_x = data->player->pos_y + ray->perp_wall_dist * ray->dir_y;
	else
		wall_x = data->player->pos_x + ray->perp_wall_dist * ray->dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)TSIZE);
	if ((ray->side == 0 && ray->dir_x > 0)
		|| (ray->side == 1 && ray->dir_y < 0))
		tex_x = TSIZE - tex_x - 1;
	return (tex_x);
}

t_tex	*get_texture(t_data *data, t_type orientation)
{
	t_tex	*tmp;

	tmp = data->tex;
	while (tmp)
	{
		if (tmp->type == orientation)
			return (tmp);
		tmp = tmp->next;
	}
	printf("Error\nTexture not found (get_texture)\n");
	return (NULL);
}

static int	get_pixel(t_data *data, t_ray *ray, int tex_x, int tex_y)
{
	t_tex	*tex;
	int		index;

	if (ray->side == 1)
	{
		if (ray->dir_y < 0)
			tex = get_texture(data, NORTH);
		else
			tex = get_texture(data, SOUTH);
	}
	else
	{
		if (ray->dir_x < 0)
			tex = get_texture(data, WEST);
		else
			tex = get_texture(data, EAST);
	}
	tex_x = fmax(0, fmin(tex_x, TSIZE - 1));
	tex_y = fmax(0, fmin(tex_y, TSIZE - 1));
	index = tex_y * tex->len + tex_x * (tex->bpp / 8);
	return (*(int *)(tex->addr + index));
}

void	draw_wall(t_data *data, t_ray *ray, int x)
{
	int				y;
	unsigned int	color;
	int				tex_x;
	int				tex_y;
	int				end_y;

	y = ray->draw_start;
	end_y = ray->draw_end;
	while (y < end_y)
	{
		tex_y = calc_tex_y(data, ray, y);
		tex_x = calc_tex_x(data, ray);
		color = get_pixel(data, ray, tex_x, tex_y);
		my_pixel_put(data->mlx, x, y, color);
		y++;
	}
}

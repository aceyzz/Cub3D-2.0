/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:00:11 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/27 23:21:37 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	draw_wall(t_data *data, t_ray *ray, int x)
{
	unsigned int	color;
	int				y;
	int				tex_y;
	int				tex_x;
	int				end;

	y = ray->draw_start;
	end = ray->draw_end;
	while (y < end)
	{
		tex_y = calc_tex_y(ray, y);
		tex_x = calc_tex_x(data, ray);
		color = get_tex_color(data, ray, tex_x, tex_y);
		// transform the color to apply fog HERE
		my_pixel_put(data->mlx, x, y, color);
		y++;
	}
}

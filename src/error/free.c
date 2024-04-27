/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 10:08:55 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/27 23:20:38 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	free_ptr(void *ptr)
{
	if (ptr)
		free(ptr);
}

void	free_mlx(t_mlx *mlx)
{
	if (!mlx)
		return ;
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	free_ptr(mlx);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
		free_ptr(tab[i++]);
	free_ptr(tab);
}

void	free_tex(t_tex *tex)
{
	t_tex	*tmp;

	if (!tex)
		return ;
	while (tex)
	{
		tmp = tex->next;
		free_ptr(tex->path);
		free_ptr(tex);
		tex = tmp;
	}
}

void	free_data(t_data *data)
{
	free_mlx(data->mlx);
	if (data->map)
		free_tab(data->map);
	if (data->map_copy)
		free_tab(data->map_copy);
	free_tex(data->tex);
	free_ptr(data->player);
	free_ptr(data->keys);
}

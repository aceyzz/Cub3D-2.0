/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:06:56 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/25 12:16:19 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

static void	free_cylinder(t_cylinder *cyl)
{
	t_cylinder	*tmp;

	if (!cyl)
		return ;
	while (cyl)
	{
		tmp = cyl;
		cyl = cyl->next;
		free(tmp);
	}
}

static void	free_plane(t_plane *plane)
{
	t_plane	*tmp;

	if (!plane)
		return ;
	while (plane)
	{
		tmp = plane;
		plane = plane->next;
		free(tmp);
	}
}

static void	free_sphere(t_sphere *sphere)
{
	t_sphere	*tmp;

	if (!sphere)
		return ;
	while (sphere)
	{
		tmp = sphere;
		sphere = sphere->next;
		free(tmp);
	}
}

void	free_objs(t_objs *objs)
{
	if (!objs)
		return ;
	if (objs->ambient)
		free(objs->ambient);
	if (objs->camera)
		free(objs->camera);
	if (objs->light)
		free(objs->light);
	free_cylinder(objs->cylinder);
	free_plane(objs->plane);
	free_sphere(objs->sphere);
	free(objs);
}

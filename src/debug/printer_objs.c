/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_objs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:05:26 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/25 12:48:18 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	print_acl(t_camera *camera, t_ambient *ambient, t_light *light)
{
	if (!camera || !ambient || !light)
		err_exit_void("problem: ACL not found");
	printf("%sCamera:\n", CYAN);
	printf("Position[0]:\t%f\n", camera->position[0]);
	printf("Position[1]:\t%f\n", camera->position[1]);
	printf("Position[2]:\t%f\n", camera->position[2]);
	printf("Direction[0]:\t%f\n", camera->direction[0]);
	printf("Direction[1]:\t%f\n", camera->direction[1]);
	printf("Direction[2]:\t%f\n", camera->direction[2]);
	printf("FOV:\t\t%f\n\n%s", camera->fov, RST);
	printf("%sAmbient light:\n", ORNG);
	printf("Ratio:\t\t%f\n", ambient->ratio);
	printf("RGB[0]:\t\t%d\n", ambient->rgb[0]);
	printf("RGB[1]:\t\t%d\n", ambient->rgb[1]);
	printf("RGB[2]:\t\t%d\n\n%s", ambient->rgb[2], RST);
	printf("%sLight:\n", YLLW);
	printf("Position[0]:\t%f\n", light->position[0]);
	printf("Position[1]:\t%f\n", light->position[1]);
	printf("Position[2]:\t%f\n", light->position[2]);
	printf("Ratio:\t\t%f\n", light->ratio);
	printf("RGB[0]:\t\t%d\n", light->rgb[0]);
	printf("RGB[1]:\t\t%d\n", light->rgb[1]);
	printf("RGB[2]:\t\t%d\n\n%s", light->rgb[2], RST);
}

static void	print_sphere(t_sphere *sphere)
{
	t_sphere	*tmp;
	int			i;

	tmp = sphere;
	i = 0;
	while (sphere)
	{
		printf("%sSphere (%d):\n", PURP, i++);
		printf("Position[0]:\t%f\n", sphere->position[0]);
		printf("Position[1]:\t%f\n", sphere->position[1]);
		printf("Position[2]:\t%f\n", sphere->position[2]);
		printf("Diameter:\t%f\n", sphere->diameter);
		printf("RGB[0]:\t\t%d\n", sphere->rgb[0]);
		printf("RGB[1]:\t\t%d\n", sphere->rgb[1]);
		printf("RGB[2]:\t\t%d\n\n%s", sphere->rgb[2], RST);
		sphere = sphere->next;
	}
	sphere = tmp;
}

static void	print_plane(t_plane *plane)
{
	t_plane	*tmp;
	int		i;

	tmp = plane;
	i = 0;
	while (plane)
	{
		printf("%sPlane (%d):\n", LIME, i++);
		printf("Position[0]:\t%f\n", plane->position[0]);
		printf("Position[1]:\t%f\n", plane->position[1]);
		printf("Position[2]:\t%f\n", plane->position[2]);
		printf("Direction[0]:\t%f\n", plane->direction[0]);
		printf("Direction[1]:\t%f\n", plane->direction[1]);
		printf("Direction[2]:\t%f\n", plane->direction[2]);
		printf("RGB[0]:\t\t%d\n", plane->rgb[0]);
		printf("RGB[1]:\t\t%d\n", plane->rgb[1]);
		printf("RGB[2]:\t\t%d\n\n%s", plane->rgb[2], RST);
		plane = plane->next;
	}
	plane = tmp;
}

static void	print_cylinder(t_cylinder *cylinder)
{
	t_cylinder	*tmp;
	int			i;

	tmp = cylinder;
	i = 0;
	while (cylinder)
	{
		printf("%sCylinder (%d):\n", REDD, i++);
		printf("Position[0]:\t%f\n", cylinder->position[0]);
		printf("Position[1]:\t%f\n", cylinder->position[1]);
		printf("Position[2]:\t%f\n", cylinder->position[2]);
		printf("Direction[0]:\t%f\n", cylinder->direction[0]);
		printf("Direction[1]:\t%f\n", cylinder->direction[1]);
		printf("Direction[2]:\t%f\n", cylinder->direction[2]);
		printf("Diameter:\t%f\n", cylinder->diameter);
		printf("Height:\t\t%f\n", cylinder->height);
		printf("RGB[0]:\t\t%d\n", cylinder->rgb[0]);
		printf("RGB[1]:\t\t%d\n", cylinder->rgb[1]);
		printf("RGB[2]:\t\t%d\n\n%s", cylinder->rgb[2], RST);
		cylinder = cylinder->next;
	}
	cylinder = tmp;
}

void	print_objs(t_objs *objs)
{
	print_acl(objs->camera, objs->ambient, objs->light);
	if (objs->sphere)
		print_sphere(objs->sphere);
	if (objs->plane)
		print_plane(objs->plane);
	if (objs->cylinder)
		print_cylinder(objs->cylinder);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:05:26 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/25 11:29:27 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	print_camera(t_camera *camera)
{
	printf("%sCamera:\n", CYAN);
	printf("Position[0]: %f\n", camera->position[0]);
	printf("Position[1]: %f\n", camera->position[1]);
	printf("Position[2]: %f\n", camera->position[2]);
	printf("Direction[0]: %f\n", camera->direction[0]);
	printf("Direction[1]: %f\n", camera->direction[1]);
	printf("Direction[2]: %f\n", camera->direction[2]);
	printf("FOV: %f\n\n%s", camera->fov, RST);
}

void	print_ambient(t_ambient *ambient)
{
	printf("%sAmbient light:\n", ORNG);
	printf("Ratio: %f\n", ambient->ratio);
	printf("RGB[0]: %d\n", ambient->rgb[0]);
	printf("RGB[1]: %d\n", ambient->rgb[1]);
	printf("RGB[2]: %d\n\n%s", ambient->rgb[2], RST);
}

void	print_light(t_light *light)
{
	printf("%sLight:\n", YLLW);
	printf("Position[0]: %f\n", light->position[0]);
	printf("Position[1]: %f\n", light->position[1]);
	printf("Position[2]: %f\n", light->position[2]);
	printf("Ratio: %f\n", light->ratio);
	printf("RGB[0]: %d\n", light->rgb[0]);
	printf("RGB[1]: %d\n", light->rgb[1]);
	printf("RGB[2]: %d\n\n%s", light->rgb[2], RST);
}

void	print_sphere(t_sphere *sphere)
{
	t_sphere	*tmp;
	int			i;

	tmp = sphere;
	i = 0;
	while (sphere)
	{
		printf("%sSphere (%d):\n", PURP, i++);
		printf("Position[0]: %f\n", sphere->position[0]);
		printf("Position[1]: %f\n", sphere->position[1]);
		printf("Position[2]: %f\n", sphere->position[2]);
		printf("Diameter: %f\n", sphere->diameter);
		printf("RGB[0]: %d\n", sphere->rgb[0]);
		printf("RGB[1]: %d\n", sphere->rgb[1]);
		printf("RGB[2]: %d\n\n%s", sphere->rgb[2], RST);
		sphere = sphere->next;
	}
	sphere = tmp;
}

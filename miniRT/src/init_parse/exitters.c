/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exitters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 22:20:31 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/25 11:14:47 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	free_objs(t_objs *objs)
{
	if (!objs)
		return ;
	if (objs->ambient)
		free(objs->ambient);
	if (objs->camera)
		free(objs->camera);
	if (objs->light)
		free(objs->light);
	if (objs->sphere)
		free(objs->sphere);
	if (objs->plane)
		free(objs->plane);
	if (objs->cylinder)
		free(objs->cylinder);
	free(objs);
}

void	err_exit_void(char *msg)
{
	ft_putstr_fd(REDD "Error:\n", 2);
	ft_putstr_fd(YLLW "-> ", 2);
	if (msg)
		ft_putstr_fd(msg, 2);
	else
		ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n" RST, 2);
	exit(EXIT_FAILURE);
}

void	err_exit_free(char *msg, t_data *data)
{
	free_tab(data->parse->filetab);
	if (data->parse->filestr)
		free(data->parse->filestr);
	free_objs(data->objs);
	err_exit_void(msg);
}

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

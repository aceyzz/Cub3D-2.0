/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exitters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 22:20:31 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/25 17:11:32 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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
	if (data->parse->filetab)
		free_tab(data->parse->filetab);
	if (data->parse->filestr)
		free(data->parse->filestr);
	if (data->objs)
		free_objs(data->objs);
	if (data->mlx)
		free_mlx(data->mlx);
	err_exit_void(msg);
}

void	valid_exit(t_data *data)
{
	ft_putstr_fd(LIME "\nExit requested. Goodbye !\n\n" RST, 1);
	free_objs(data->objs);
	exit(EXIT_SUCCESS);
}

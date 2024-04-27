/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 10:03:34 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/27 10:14:13 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	error_exit(char *errmsg, char *func, t_data *data)
{
	ft_putstr_fd(REDD "Error: ", 2);
	ft_putstr_fd(errmsg, 2);
	if (func)
	{
		ft_putstr_fd(" in function " GOLD, 2);
		ft_putstr_fd(func, 2);
	}
	ft_putstr_fd(RST "\n", 2);
	if (data)
		free_data(data);
	exit(EXIT_FAILURE);
	return (0);
}

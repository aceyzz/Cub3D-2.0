/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 22:21:03 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/24 22:21:13 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	check_params(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		return (err_exit_void("Usage: ./miniRT scene.rt"));
	if (ft_strlen(argv[1]) < 3)
		return (err_exit_void("Invalid file"));
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 3, ".rt", 3) != 0)
		return (err_exit_void("Invalid file extension"));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (err_exit_void("File not found"));
	close(fd);
}

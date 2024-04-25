/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:43:39 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/25 09:44:37 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	parse_int(char *str, t_data *data)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		while (is_space(str[i]) && str[i])
			i++;
		if (str[i] < '0' || str[i] > '9')
			err_exit_free("Invalid integer in file", data);
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb);
}

void	check_rgb_values(int rgb[3], t_data *data)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		if (rgb[i] < 0 || rgb[i] > 255)
			err_exit_free("Invalid RGB value in file", data);
	}
}

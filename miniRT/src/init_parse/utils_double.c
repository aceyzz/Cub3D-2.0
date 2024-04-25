/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:03:03 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/25 09:57:31 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	ft_atof(const char *str)
{
	double	decimal;
	int		i;

	decimal = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		decimal = decimal * 10 + (str[i] - '0');
		i++;
	}
	return (decimal);
}

double	ft_atod(char *str)
{
	double	nb;
	int		i;
	int		sign;

	nb = 0;
	i = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		nb += ft_atof(str + i + 1) / pow(10, ft_strlen(str + i + 1));
	return (nb * sign);
}

static int	is_valid_double(char *str, int start, int end)
{
	int	i;
	int	dot;

	i = start;
	dot = 0;
	if (!str)
		return (0);
	if (str[i] == '-')
		i++;
	while (i < end)
	{
		if (str[i] == '.')
			dot++;
		if (!ft_isdigit(str[i]) && str[i] != '.')
			return (0);
		if (dot > 1)
			return (0);
		i++;
	}
	return (1);
}

double	parse_double(char *str, t_data *data)
{
	int		i;
	int		k;
	char	*tmp;
	double	result;

	i = -1;
	while (str[++i])
	{
		while (str[i] && is_space(str[i]))
			i++;
		k = i;
		while (str[i] && !is_space(str[i]))
			i++;
		tmp = ft_substr(str, k, i - k);
		if (!is_valid_double(tmp, k, i))
		{
			free(tmp);
			err_exit_free("Invalid double in file", data);
		}
		result = ft_atod(tmp);
		free(tmp);
		return (result);
	}
	return (42.424242);
}

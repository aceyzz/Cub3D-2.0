/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:41:26 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/25 12:41:36 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		if (i % 2 == 0)
			ft_putstr_fd(GRY1, STDOUT_FILENO);
		else
			ft_putstr_fd(GRY2, STDOUT_FILENO);
		ft_putstr_fd(tab[i], STDOUT_FILENO);
		ft_putstr_fd("\n" RST, STDOUT_FILENO);
		i++;
	}
}

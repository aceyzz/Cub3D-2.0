/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:12:15 by waziz             #+#    #+#             */
/*   Updated: 2024/04/30 17:41:33 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	invalid_extension(t_parse *parse, char **ws, int t)
{
	free_tab(ws);
	printf("params : %s\n", parse->params[t]);
	return (error_exit("Invalid extension '.xmp'", "parsing/params/6:1",
			parse->data));
}

int	invalid_name(t_parse *parse, char **ws, int t)
{
	free_tab(ws);
	printf("params : %s\n", parse->params[t]);
	return (error_exit("Only : NO,SO,EA,WE,F or C", "parsing/params/6:2",
			parse->data));
}

int	invalid_params(t_parse *parse, char **ws, int t)
{
	free_tab(ws);
	printf("params : %s\n", parse->params[t]);
	return (error_exit("Invalid params", "parsing/params/6:3", parse->data));
}

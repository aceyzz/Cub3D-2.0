/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:12:15 by waziz             #+#    #+#             */
/*   Updated: 2024/04/30 23:15:45 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	invalid_extension(t_parse *parse, char **ws, int t)
{
	free_tab(ws);
	printf("params : %s\n", parse->params[t]);
	return (error_exit("Invalid extension '.xmp'", NULL, parse->data));
}

int	invalid_name(t_parse *parse, char **ws, int t)
{
	free_tab(ws);
	printf("params : %s\n", parse->params[t]);
	return (error_exit("Only : NO,SO,EA,WE,F or C", NULL, parse->data));
}

int	invalid_params(t_parse *parse, char **ws, int t)
{
	free_tab(ws);
	printf("params : %s\n", parse->params[t]);
	return (error_exit("Invalid params", NULL, parse->data));
}

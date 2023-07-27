/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_resolution_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 02:40:50 by psaeyang          #+#    #+#             */
/*   Updated: 2023/07/27 08:31:24 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../paser.h"

void	util_radius(char *radius)
{
	if (!str_is_decimal(radius) && ft_strlen(radius) != 1)
		error(BYEL"radius not correct"RESET);
	// printf(BCYN"radius ok next\n"RESET); //del
}

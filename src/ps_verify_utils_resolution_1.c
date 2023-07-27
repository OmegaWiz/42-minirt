/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_verify_utils_resolution_1.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 02:40:50 by psaeyang          #+#    #+#             */
/*   Updated: 2023/07/27 14:08:51 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	util_radius(char *radius)
{
	if (!str_is_decimal(radius) && ft_strlen(radius) != 1)
		error(BYEL"radius not correct"RESET);
	// printf(BCYN"radius ok next\n"RESET); //del
}

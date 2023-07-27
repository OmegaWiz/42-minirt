/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_getinfo_utils_get.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:33:03 by psaeyang          #+#    #+#             */
/*   Updated: 2023/07/27 15:03:14 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_vec3(char **xyz, t_vec3 *pos)
{
	pos->x = ft_atof(xyz[0]);
	pos->y = ft_atof(xyz[1]);
	pos->z = ft_atof(xyz[2]);
}

void	get_point(char **xyz, t_point *pos)
{
	pos->x = ft_atof(xyz[0]);
	pos->y = ft_atof(xyz[1]);
	pos->z = ft_atof(xyz[2]);
}

void	get_color(char **colour, int *color)
{
	t_color	col;

	col.x = ft_atoi(colour[0]);
	col.y = ft_atoi(colour[1]);
	col.z = ft_atoi(colour[2]);
	*color = color2int(col.x, col.y, col.z);
}

int	*get_digit(char *digit, int	*color)
{
	*color = ft_atoi(digit);
	return (color);
}

double	*get_decimal(char *dec, double *decimal)
{
	*decimal = ft_atof(dec);
	return (decimal);
}

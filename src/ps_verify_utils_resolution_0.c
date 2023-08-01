/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_verify_utils_resolution_0.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:08:00 by psaeyang          #+#    #+#             */
/*   Updated: 2023/08/01 17:39:31 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	util_dir(char *direction)
{
	if (str_is_decimal(direction) == 0)
		error(BYEL"dir not digit nor decimal");
	else if (ft_atof(direction) > 1.0 || ft_atof(direction) < -1.0)
		error(BYEL"dir between -1.0 - 1.0");
}

void	util_ori(char **origin)
{
	int	i;

	i = 0;
	verify_len(origin, 3);
	while (i < 3)
	{
		if (twod_is_decimal(origin) == 0)
			error(BYEL"not decimal or digit"RESET);
		i++;
	}
}

void	util_fov(char *fov)
{
	if (str_is_decimal(fov) == 0 || ((ft_atof(fov) > 180 || ft_atof(fov) < 0)))
	{
		if (ft_atof(fov) < 0 || ft_atof(fov) > 180)
			error(BYEL"only 0-180");
		else if (str_is_decimal(fov) == 0)
			error(BYEL"not number");
	}
}

void	util_ratio(char **ratio, int index)
{
	double	n;

	n = ft_atof(ratio[index]);
	if (!(n >= 0 && n <= 1.0) || str_is_decimal(ratio[index]) == 0)
	{
		free_error(BYEL"ratio not correct"RESET, ratio);
	}
}

void	util_color(char **color, int len)
{
	int	i;

	i = 0;
	verify_len(color, len);
	while (i < len)
	{
		if (twod_is_digit(color) == 0 || color[i][0] == '-' ||
		ft_atoi(color[i]) > 255)
		{
			if (color[i][0] == '-' || ft_atoi(color[i]) > 255)
				free_error(BYEL"color only 0-255"RESET, color);
			free_error(BYEL"color not correct"RESET, color);
		}
		i++;
	}
}

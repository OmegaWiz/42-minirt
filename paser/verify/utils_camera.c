/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:08:00 by psaeyang          #+#    #+#             */
/*   Updated: 2023/07/17 03:44:16 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../paser.h"

void	util_c_dir(char *direction)
{
	if (direction[0] == '-')
	{
		if (direction[1] != '1' || (direction[2] == '.' && direction[3] != '0'))
			error(BYEL"dir between -1.0 - 1.0", 0);
	}
	else
	{
		if (ft_atof(direction) > 1.0)
			error(BYEL"dir between -1.0 - 1.0", 0);
	}
}

void	util_c_ori(char **origin)
{
	int	i;

	i = 0;
	verify_len(origin, 3);
	while (i < 3)
	{
		if (twod_is_decimal(origin) == 0)
			error(BYEL"not decimal or digit"RESET, 0);
		i++;
	}
}

void	util_c_fov(char *fov)
{
	int	i;

	i = 0;
	if (str_is_digit(fov) == 0 || ((ft_atoi(fov) > 180 || ft_atoi(fov) < 0)))
	{
		if (ft_atoi(fov) < 0 || ft_atoi(fov) > 180)
			error(BYEL"only 0-180", 0);
		else if (str_is_digit(fov) == 0)
			error(BYEL"connot be flaot number", 0);
	}
}

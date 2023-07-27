/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_resolution_0.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:08:00 by psaeyang          #+#    #+#             */
/*   Updated: 2023/07/27 08:30:38 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../paser.h"

void	util_dir(char *direction)
{
	if (direction[0] == '-')
	{
		if (direction[1] != '1' || (direction[2] == '.' && direction[3] != '0'))
			error(BYEL"dir between -1.0 - 1.0");
	}
	else
	{
		if (str_is_decimal(direction) == 0)
			error(BYEL"dir not digit nor decimal");
		else if (ft_atof(direction) > 1.0)
			error(BYEL"dir between -1.0 - 1.0");
	}
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
	// printf(BCYN"ori num ok\n"RESET); //del
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
	// printf(BCYN"fov num ok\n"RESET); //del
}

void	util_ratio(char **ratio, int index)
{
	int	i;

	i = 0;
	if (ratio[index][0] == '0' || ratio[index][0] == '1')
	{
		if (twod_is_decimal(&ratio[index]) && ft_strlen(ratio[index]) == 3)
		{
			while (ft_atoi(&ratio[index][2]) != i && i != 11)
				i++;
			if (i == 10 || (ratio[index][0] == '1' && ratio[index][2] != '0'))
				free_error(BYEL"ratio not correct"RESET, ratio);
		}
	}
	else
		free_error(BYEL"ratio not correct"RESET, ratio);
	// printf(BCYN"ratio ok next\n"RESET); //del
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
	// printf(BCYN"color ok\n"RESET); //del
}

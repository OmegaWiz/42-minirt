/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 02:40:50 by psaeyang          #+#    #+#             */
/*   Updated: 2023/07/17 03:43:15 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../paser.h"

void	util_ratio(char **ratio)
{
	int	i;

	i = 0;
	if ((ratio[1][0] == '0' || ratio[1][0] == '1') && ratio[1][1] == '.' 
	&& ft_strlen(ratio[1]) == 3)
	{
		while (ft_atoi(&ratio[1][2]) != i && i != 11)
			i++;
		if (i == 10 || (ratio[1][0] == '1' && ratio[1][2] != '0'))
			error(BYEL"ratio not correct"RESET, 0);
	}
	else
		error(BYEL"ratio not correct"RESET, 0);
	printf(BCYN"ratio ok next\n"RESET); //del
}

void	util_color(char **color)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (twod_is_digit(color) == 0 || color[i][0] == '-' ||
		ft_atoi(color[i]) > 255)
		{
			if (color[i][0] == '-' || ft_atoi(color[i]) > 255)
				error(BYEL"color only 0-255"RESET, 0);
			error(BYEL"color not correct"RESET, 0);
		}
		i++;
	}
}

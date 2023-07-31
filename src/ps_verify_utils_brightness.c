/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_verify_utils_brightness.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 04:19:50 by psaeyang          #+#    #+#             */
/*   Updated: 2023/08/01 04:32:00 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	util_ratio_light(char **brightness)
{
	int	i;

	i = 0;
	printf("%s\n", brightness[2]);
	if (brightness[2][0] == '0' || brightness[2][0] == '1')
	{
		if (twod_is_decimal(&brightness[2]) && ft_strlen(brightness[2]) == 3)
		{
			while (ft_atoi(&brightness[2][2]) != i && i != 11)
				i++;
			if (i == 10 || (brightness[2][0] == '1' && brightness[2][2] != '0'))
				error(BYEL"brightness not correct"RESET);
		}
	}
	else
		error(BYEL"brightness not correct"RESET);
}

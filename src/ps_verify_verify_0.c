/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_verify_verify_0.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:54:38 by psaeyang          #+#    #+#             */
/*   Updated: 2023/08/01 04:31:28 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	verify_a(char **chop)
{
	char	**color;

	verify_len(chop, 3);
	util_ratio(chop, 1);
	color = ft_split(chop[2], ',');
	util_color(color, 3);
	erase_split(color);
}

void	verify_cy(char **chop)
{
	char	**center;
	char	**normal;
	char	**color;
	int		i;

	i = 0;
	verify_len(chop, 6);
	center = ft_split(chop[1], ',');
	normal = ft_split(chop[2], ',');
	color = ft_split(chop[5], ',');
	util_ori(center);
	verify_len(normal, 3);
	while (i != 3)
	{
		util_dir(normal[i]);
		i++;
	}
	util_radius(chop[3]);
	util_radius(chop[4]);
	util_color(color, 3);
	erase_split(center);
	erase_split(normal);
	erase_split(color);
}

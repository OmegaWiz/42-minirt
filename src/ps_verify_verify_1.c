/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_verify_verify_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:52:52 by psaeyang          #+#    #+#             */
/*   Updated: 2023/08/01 04:31:10 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	verify_c(char **chop)
{
	char	**ori;
	char	**dir;
	int		i;

	i = 0;
	verify_len(chop, 4);
	ori = ft_split(chop[1], ',');
	dir = ft_split(chop[2], ',');
	util_ori(ori);
	while (i != 3)
	{
		util_dir(dir[i]);
		i++;
	}
	verify_len(&chop[3], 1);
	util_fov(chop[3]);
	erase_split(ori);
	erase_split(dir);
}

void	verify_l(char **chop)
{
	char	**origin;

	verify_len(chop, 3);
	origin = ft_split(chop[1], ',');
	util_ori(origin);
	util_ratio(chop, 2);
	erase_split(origin);
}

void	verify_sp(char **chop)
{
	char	**center;
	char	**color;

	center = ft_split(chop[1], ',');
	color = ft_split(chop[3], ',');
	verify_len(chop, 4);
	util_ori(center);
	util_radius(chop[2]);
	util_color(color, 3);
	erase_split(center);
	erase_split(color);
}

void	verify_pl(char **chop)
{
	char	**center;
	char	**normal;
	char	**color;
	int		i;

	i = 0;
	center = ft_split(chop[1], ',');
	normal = ft_split(chop[2], ',');
	color = ft_split(chop[3], ',');
	verify_len(chop, 4);
	util_ori(center);
	verify_len(normal, 3);
	while (i != 3)
	{
		util_dir(normal[i]);
		i++;
	}
	util_color(color, 3);
	erase_split(center);
	erase_split(normal);
	erase_split(color);
}

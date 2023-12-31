/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_verify_verify_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:52:52 by psaeyang          #+#    #+#             */
/*   Updated: 2023/08/01 18:05:21 by kkaiyawo         ###   ########.fr       */
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
	tuple_cnt(chop[1], ',', 2);
	tuple_cnt(chop[2], ',', 2);
	ori = ft_split(chop[1], ',');
	dir = ft_split(chop[2], ',');
	util_ori(ori);
	while (dir[i])
	{
		util_dir(dir[i]);
		i++;
	}
	verify_len(&chop[3], 1);
	util_fov(chop[3]);
	erase_split(ori);
	erase_split(dir);
	if (i != 3)
		error("Invalid camera direction\n");
}

void	verify_l(char **chop)
{
	char	**origin;

	verify_len(chop, 3);
	tuple_cnt(chop[1], ',', 2);
	origin = ft_split(chop[1], ',');
	util_ori(origin);
	util_ratio(chop, 2);
	erase_split(origin);
}

void	verify_sp(char **chop)
{
	char	**center;
	char	**color;

	tuple_cnt(chop[1], ',', 2);
	tuple_cnt(chop[3], ',', 2);
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
	tuple_cnt(chop[1], ',', 2);
	tuple_cnt(chop[2], ',', 2);
	tuple_cnt(chop[3], ',', 2);
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

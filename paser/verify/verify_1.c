/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:52:52 by psaeyang          #+#    #+#             */
/*   Updated: 2023/07/27 09:18:50 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../paser.h"

void	verify_c(char **chop)
{
	char	**ori;
	char	**dir;
	int		i;

	i = 0;
	verify_len(chop, 4);
	ori = ft_split(chop[1], ',');
	dir = ft_split(chop[2], ',');
	// printf(BCYN"C ok\n"RESET); //del
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
	printf(BGRN"camera checked. all ok\n"RESET); //del
	printf(BWHT"===============================\n"RESET); //del
}

void	verify_l(char **chop)
{
	char	**origin;

	verify_len(chop, 3);
	origin = ft_split(chop[1], ',');
	// printf(BCYN"L ok\n"RESET);
	util_ori(origin);
	util_ratio(chop, 2);
	erase_split(origin);
	printf(BGRN"light checked. all ok\n"RESET); //del
	printf(BWHT"===============================\n"RESET); //del
}

void	verify_sp(char **chop)
{
	char	**center;
	char	**color;

	center = ft_split(chop[1], ',');
	color = ft_split(chop[3], ',');
	verify_len(chop, 4);
	// printf(BCYN"SP ok\n"RESET);
	util_ori(center);
	util_radius(chop[2]);
	util_color(color, 3);
	erase_split(center);
	erase_split(color);
	printf(BGRN"sph checked. all ok\n"RESET); //del
	printf(BWHT"===============================\n"RESET); //del
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
	// printf(BCYN"PL ok\n"RESET);
	util_ori(center);
	verify_len(normal, 3);
	while (i != 3)
	{
		util_dir(normal[i]);
		i++;
	}
	// printf(BCYN"dir num ok\n"RESET); //del
	util_color(color, 3);
	erase_split(center);
	erase_split(normal);
	erase_split(color);
	printf(BGRN"pl checked, all ok\n"RESET); //del
	printf(BWHT"===============================\n"RESET); //del
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:54:38 by psaeyang          #+#    #+#             */
/*   Updated: 2023/07/27 08:30:00 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../paser.h"

void	verify_a(char **chop)
{
	char	**color;

	verify_len(chop, 3);
	// printf(BCYN"A ok\n"RESET); //del
	util_ratio(chop, 1);
	color = ft_split(chop[2], ',');
	util_color(color, 3);
	erase_split(color);
	printf(BGRN"ambi checked. all ok\n"RESET); //del
	printf(BWHT"===============================\n"RESET); //del
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
	// printf(BCYN"CY ok\n"RESET); //del
	util_ori(center);
	verify_len(normal, 3);
	while (i != 3)
	{
		util_dir(normal[i]);
		i++;
	}
	util_radius(chop[3]); //radius
	util_radius(chop[4]); //height
	util_color(color, 3);
	erase_split(center);
	erase_split(normal);
	erase_split(color);
	printf(BGRN"cylinder checked. all ok\n"RESET); //del
	printf(BWHT"===============================\n"RESET); //del
}

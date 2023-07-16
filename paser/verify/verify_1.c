/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:52:52 by psaeyang          #+#    #+#             */
/*   Updated: 2023/07/17 01:27:12 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../paser.h"

void	verify_c(char **chop)
{
	char	**ori;
	char	**dir;
	int		i;

	i = 0;
	// while (chop[i])
	// {
	// 	printf("str chop == %s\n", chop[i]);
	// 	i++;
	// }
	verify_len(chop, 4);
	ori = ft_split(chop[1], ',');
	dir = ft_split(chop[2], ',');
	
	printf(BCYN"C ok\n"RESET); //del

	verify_len(ori, 3);
	util_c_ori(ori);
	printf(BCYN"ori num ok, len 3\n"RESET); //del

	verify_len(dir, 3);
	while (i != 3)
	{
		util_c_dir(dir[i]);
		i++;
	}
	printf(BCYN"dir num ok, len 3\n"RESET); //del

	verify_len(&chop[3], 1);
	if (ft_strchr(chop[3], '.') != NULL && (ft_atoi(chop[3]) > 180 && ft_atoi(chop[3]) < 0))
		error(BYEL"connot be flaot number\n", 0);
	printf(BCYN"fov num ok, len 3\n"RESET); //del

}

void	verify_l(char **chop)
{
	verify_len(chop, 4);
	printf(BCYN"L ok\n"RESET);
	printf(BGRN"go check info\n\n"RESET);
}

void	verify_sp(char **chop)
{
	verify_len(chop, 4);
	printf(BCYN"SP ok\n"RESET);
	printf(BGRN"go check info\n\n"RESET);
}

void	verify_pl(char **chop)
{
	verify_len(chop, 4);
	printf(BCYN"PL ok\n"RESET);
	printf(BGRN"go check info\n\n"RESET);
}

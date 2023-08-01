/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:26:14 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/08/01 18:26:27 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		error(BRED"wrong ac Σ(￣ロ￣lll)"RESET);
	verify_file(argv);
	printf(BMAG"go get info\n"RESET);
	vars_init(&vars);
	get_info(&vars, argv[1]);
	cam_init(&vars);
	win_init(&vars);
}

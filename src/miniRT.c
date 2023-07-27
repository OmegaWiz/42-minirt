/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:26:14 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/07/27 16:03:24 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	// t_vars	vars;

	// (void) argv;
	// if (argc != 2)
	// 	return (1);
	// if (file_init(&vars, argv[1]) != 0)
	// 	return (2);
	// win_init(&vars);
	// return (0);

	t_vars	vars;

	if (argc != 2)
		error(BRED"wrong ac Σ(￣ロ￣lll)"RESET);
	verify_file(argv);
	printf(BMAG"go get info\n"RESET);
	vars.obj_list = NULL;
	get_info(&vars, argv[1]);
	cam_init(&vars);
	win_init(&vars);


	// t_vars	*vars;

	// vars = NULL;
	// if (argc != 2)
	// 	error(BRED"wrong ac Σ(￣ロ￣lll)"RESET);
	// verify_file(argv);
	// printf(BMAG"go get info\n"RESET);
	// vars = malloc(sizeof(t_vars));
	// get_info(vars, argv[1]);
	// win_init(vars);

	// print_ambi(parser);
	// print_camera(parser);
	// print_light(parser);
	// print_sp(parser);
	// print_pl(parser);
	// print_cy(parser);
	// free(parser);
}

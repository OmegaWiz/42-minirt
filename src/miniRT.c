/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moonegg <moonegg@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:19:51 by moonegg           #+#    #+#             */
/*   Updated: 2023/07/03 16:08:05 by moonegg          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	(void) argv;
	if (argc != 2)
		return (0);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "miniRT");
	vars.img.img = mlx_new_image(vars.mlx, WIN_WIDTH, WIN_HEIGHT);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bpp,
			&vars.img.line_len, &vars.img.end);
	mlx_loop_hook(vars.mlx, do_none, (void *) &vars);
	mlx_hook(vars.win, 17, 0, close_x, (void *) &vars);
	mlx_key_hook(vars.win, key_hook, (void *) &vars);
	mlx_loop(vars.mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 08:40:25 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/08/01 18:26:24 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	win_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_HEIGHT, "miniRT");
	vars->img.img = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bpp,
			&vars->img.line_len, &vars->img.end);
	draw(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	mlx_loop_hook(vars->mlx, do_none, (void *) vars);
	mlx_hook(vars->win, 17, 0, close_x, (void *) vars);
	mlx_key_hook(vars->win, key_hook, (void *) vars);
	mlx_loop(vars->mlx);
}

void	vars_init(t_vars *vars)
{
	vars->mlx = NULL;
	vars->win = NULL;
	vars->img.img = NULL;
	vars->img.addr = NULL;
	vars->img.bpp = 0;
	vars->img.line_len = 0;
	vars->img.end = 0;
	vars->obj_list = NULL;
}

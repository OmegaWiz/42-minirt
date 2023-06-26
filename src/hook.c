/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:14:16 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/04/17 17:42:18 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_x(void *param)
{
	t_vars	*vars;

	vars = (t_vars *) param;
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

void	udlr(int keycode, t_vars *vars)
{
	t_z		sz;
	float	mult;

	sz.x = vars->mx.x - vars->mn.x;
	sz.y = vars->mx.y - vars->mn.y;
	mult = 0.1;
	if (keycode % 2)
		mult = -0.1;
	if (keycode < 125)
	{
		vars->mn.x += sz.x * mult;
		vars->mx.x += sz.x * mult;
	}
	else
	{
		vars->mn.y += sz.y * mult;
		vars->mx.y += sz.y * mult;
	}
}

/*
123-126
lrud
*/
int	keyb(int keycode, void *param)
{
	t_vars	*vars;

	vars = (t_vars *) param;
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if (122 < keycode && keycode < 127)
	{
		udlr(keycode, vars);
		draw(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	}
	if (keycode == 45)
	{
		vars->color = (vars->color + 1) % 6;
		draw(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	}
	return (0);
}

/*
4 - scroll up
5 - scroll down
*/
int	zoom(int button, int x, int y, void *param)
{
	t_vars	*vars;
	t_z		mouse;

	vars = (t_vars *) param;
	if (button != 4 && button != 5)
		return (0);
	if (button == 4)
		vars->zoomidx = 1.08;
	if (button == 5)
		vars->zoomidx = 1 / 1.08;
	mouse.x = vars->mn.x + ((x / (float)WIN_WIDTH) * (vars->mx.x - vars->mn.x));
	mouse.y = (WIN_HEIGHT - y) / (float)WIN_HEIGHT * (vars->mx.y - vars->mn.y);
	mouse.y += vars->mn.y;
	vars->mn.x = mouse.x - (vars->zoomidx * (mouse.x - vars->mn.x));
	vars->mx.x = mouse.x + (vars->zoomidx * (vars->mx.x - mouse.x));
	vars->mn.y = mouse.y - (vars->zoomidx * (mouse.y - vars->mn.y));
	vars->mx.y = mouse.y + (vars->zoomidx * (vars->mx.y - mouse.y));
	draw(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}

int	do_none(void *data)
{
	return (0);
}

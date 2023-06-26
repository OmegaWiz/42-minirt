/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:12:36 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/04/17 17:19:23 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_z c, t_z z)
{
	int	i;
	t_z	k;
	t_z	l;

	i = 1;
	k.x = c.x;
	k.y = c.y;
	while (i < 80)
	{
		l.x = (k.x * k.x) - (k.y * k.y) + z.x;
		l.y = (2 * k.x * k.y) + z.y;
		k.x = l.x;
		k.y = l.y;
		if ((k.x * k.x) + (k.y * k.y) > 4)
			return (i);
		i++;
	}
	return (0);
}

int	burn(t_z c, t_z z)
{
	int	i;
	t_z	k;

	i = 1;
	while (i < 80)
	{
		k.x = (z.x * z.x) - (z.y * z.y) + c.x;
		k.y = -fabs(2 * z.x * z.y) + c.y;
		if ((k.x * k.x) + (k.y * k.y) > 4)
			return (i);
		z.x = k.x;
		z.y = k.y;
		i++;
	}
	return (0);
}

int	mandelbrot(t_z c, t_z z)
{
	int	i;
	t_z	k;

	i = 1;
	while (i < MAX_ITER)
	{
		k.x = (z.x * z.x) - (z.y * z.y) + c.x;
		k.y = (2 * z.x * z.y) + c.y;
		if ((k.x * k.x) + (k.y * k.y) > 4)
			return (i);
		z.x = k.x;
		z.y = k.y;
		i++;
	}
	return (0);
}

void	draw(t_vars *vars)
{
	t_z		p;
	t_z		c;
	int		color;

	p.x = 0;
	while (p.x < WIN_WIDTH)
	{
		p.y = 0;
		c.x = ((p.x / WIN_WIDTH) * (vars->mx.x - vars->mn.x)) + vars->mn.x;
		while (p.y < WIN_HEIGHT)
		{
			c.y = (WIN_HEIGHT - p.y) / WIN_HEIGHT;
			c.y *= (vars->mx.y - vars->mn.y);
			c.y += vars->mn.y;
			color = vars->iter(c, vars->mi);
			if (color > 0)
				color = vars->scheme[vars->color] * color / MAX_ITER;
			my_mlx_pixel_put(&(vars->img), p, color);
			p.y++;
		}
		p.x++;
	}
}

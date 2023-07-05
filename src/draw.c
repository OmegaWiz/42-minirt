/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 08:40:55 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/07/05 14:29:54 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	my_mlx_pixel_put(t_data *data, t_vec2 px, int color)
{
	char	*dst;
	int		x;
	int		y;

	y = (int) px.y;
	x = (int) px.x;
	if (x >= WIN_WIDTH || y >= WIN_HEIGHT)
		return ;
	// printf("putting pixel at x: %d, y: %d with color: %x\n", x, y, color);
	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw(t_vars *vars)
{
	t_vec2	p;
	int		color;

	color = 0;
	p.x = 0;
	while (p.x < WIN_WIDTH)
	{
		p.y = 0;
		while (p.y < WIN_HEIGHT)
		{
			color = raytrace(p, vars);
			my_mlx_pixel_put(&(vars->img), p, color);
			p.y++;
		}
		p.x++;
	}
}


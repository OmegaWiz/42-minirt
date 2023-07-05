/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:19:51 by moonegg           #+#    #+#             */
/*   Updated: 2023/07/05 08:32:55 by kkaiyawo         ###   ########.fr       */
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
			my_mlx_pixel_put(&(vars->img), p, color);
			p.y++;
		}
		p.x++;
	}
}

void	init(t_vars *vars)
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

int	main(int argc, char **argv)
{
	t_vars	vars;

	(void) argv;
	if (argc != 2)
		return (0);
	init(&vars);
	return (0);
}

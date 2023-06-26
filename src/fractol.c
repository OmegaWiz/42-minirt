/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 08:48:35 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/04/18 08:56:03 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
x	horizontal	row		height
y	vertical	column	width
*/

void	my_mlx_pixel_put(t_data *data, t_z px, int color)
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

void	init(t_vars *vars, int (*iter)(t_z, t_z))
{
	t_data	*d;

	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_HEIGHT, "fractol");
	d = &(vars->img);
	d->img = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	d->addr = mlx_get_data_addr(d->img, &(d->bpp), &(d->line_len), &(d->end));
	vars->mx.y = MAX_INIT;
	vars->mx.x = (float) MAX_INIT * ((float) WIN_WIDTH / WIN_HEIGHT);
	vars->mn.x = vars->mx.x * -1;
	vars->mn.y = vars->mx.y * -1;
	vars->scheme = (int [6]){0xcdd6f4, 0xcad3f5, 0xc6d0f5,
		0xff0000, 0xffff00, 0x8800ff};
	vars->color = 0;
	vars->iter = iter;
	vars->zoomidx = 1;
	draw(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	mlx_loop_hook(vars->mlx, do_none, (void *) vars);
	mlx_hook(vars->win, 17, 0, close_x, (void *) vars);
	mlx_key_hook(vars->win, keyb, (void *) vars);
	mlx_mouse_hook(vars->win, zoom, (void *) vars);
	mlx_loop(vars->mlx);
	exit(0);
}

void	print_man(void)
{
	ft_putstr_fd("\033[96mUsage:\033[32m\n", 1);
	ft_putstr_fd("> ./fractol <fractal:uint> <*re:int> <*im:int>\033[0m\n", 1);
	ft_putstr_fd("	fractal: fractol type (0 = Mandelbrot, ", 1);
	ft_putstr_fd("1 = Burning ship, 2 = Julia, 3 = Broken Julia)\n", 1);
	ft_putstr_fd("	re(al): real coordinate for julia set ", 1);
	ft_putstr_fd("(*1000) [-2000, 2000]\n", 1);
	ft_putstr_fd("	im(aginary): imaginary coordinate for julia set ", 1);
	ft_putstr_fd("(*1000) [-2000, 2000]\n\n", 1);
	ft_putstr_fd("\033[96mKey bindings:\033[0m\n", 1);
	ft_putstr_fd("	[Arrow keys]: Pans the camera\n", 1);
	ft_putstr_fd("	[Scrollwheel]: Zooms in and out\n", 1);
	ft_putstr_fd("	[N]: Change color scheme\n", 1);
	ft_putstr_fd("	[Esc]: Exit application.\n\n\033[93m", 1);
	ft_putstr_fd("\033[0m\n", 1);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc == 2)
	{
		vars.mi.x = 0;
		vars.mi.y = 0;
		if (ft_strncmp(argv[1], "0", 2) == 0)
			init(&vars, mandelbrot);
		else if (ft_strncmp(argv[1], "1", 2) == 0)
			init(&vars, burn);
		else
			print_man();
	}
	else if (argc == 4)
	{
		vars.mi.x = (float) ft_atoi(argv[2]) / 1000.0;
		vars.mi.y = (float) ft_atoi(argv[3]) / 1000.0;
		if (ft_strncmp(argv[1], "2", 2) != 0)
			print_man();
		if (fabs(vars.mi.x) > 2 || fabs(vars.mi.y) > 2)
			print_man();
		init(&vars, julia);
		return (0);
	}
	print_man();
}

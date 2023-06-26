/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:02:41 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/06/26 12:39:00 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include <math.h>

# include "../lib/mlx/mlx.h"
# include "../lib/libft/libft.h"

# ifndef WIN_WIDTH
#  define WIN_WIDTH 500
# endif

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 500
# endif

# define MAX_ITER 80
# define MAX_COLOR 6
# define MAX_INIT 2

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		end;
}	t_data;

typedef struct s_z {
	float	x;
	float	y;
}	t_z;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_data	img;
	t_z		mn;
	t_z		mx;
	t_z		mi;
	int		color;
	int		*scheme;
	int		(*iter)(t_z, t_z);
	float	zoomidx;
}	t_vars;

/*
drawing functio (draw.c)
*/
int		julia(t_z c, t_z z);
int		burn(t_z c, t_z z);
int		mandelbrot(t_z c, t_z z);
void	draw(t_vars *vars);

/*
keyhooking function (hook.c)
*/
int		close_x(void *param);
void	udlr(int keycode, t_vars *vars);
int		keyb(int keycode, void *param);
int		zoom(int button, int x, int y, void *param);
int		do_none(void *data);

/*
pixel_put (fractol.c)
*/
void	my_mlx_pixel_put(t_data *data, t_z px, int color);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:08:59 by moonegg           #+#    #+#             */
/*   Updated: 2023/07/05 08:18:16 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "algebra.h"
# include "../lib/mlx/mlx.h"
// # include "../lib/minilibx-linux/mlx.h"
# include "../lib/libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>

# ifndef WIN_WIDTH
#  define WIN_WIDTH 1000
# endif

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 1000
# endif

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		end;
}	t_data;

typedef struct s_ray
{
	t_point	origin;
	t_vec3	direction;
}	t_ray;

typedef struct s_camera
{
	t_point	origin;
	t_vec3	direction;
	float	fov;
}	t_camera;

typedef struct s_camera_plane
{
	t_point	center;
	t_vec3	normal;
	float	width;
	float	height;
	t_vec3	right;
	t_vec3	down;
	t_point	top_left;
}	t_camera_plane;

typedef struct s_sphere
{
	t_point	center;
	float	radius;
}	t_sphere;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_data	img;
}	t_vars;

int	close_x(void *param);
int	key_hook(int keycode, void *param);
int	do_none(void *data);

#endif

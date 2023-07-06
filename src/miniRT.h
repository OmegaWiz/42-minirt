/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:08:59 by moonegg           #+#    #+#             */
/*   Updated: 2023/07/06 08:49:47 by kkaiyawo         ###   ########.fr       */
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
# include <stdbool.h>

# ifndef WIN_WIDTH
#  define WIN_WIDTH 500
# endif

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 500
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

typedef struct s_ambient
{
	float	ratio;
	int		color;
}	t_ambient;

typedef struct s_light
{
	t_point	origin;
	float	brightness;
	int		color;
}	t_light;

typedef struct s_sphere
{
	t_point	center;
	float	radius;
	int		color;
}	t_sphere;

typedef struct s_plane
{
	t_point	center;
	t_vec3	normal;
	int		color;
}	t_plane;

typedef struct s_cylinder
{
	t_point	center;
	t_vec3	normal;
	float	radius;
	float	height;
	int		color;
}	t_cylinder;

typedef enum e_obj_type
{
	SPHERE,
	PLANE,
	CYLINDER,
}	t_obj_type;

typedef struct s_obj
{
	t_obj_type	type;
	void		*obj;
}	t_obj;

typedef struct s_vars {
	void			*mlx;
	void			*win;
	t_data			img;
	t_camera		camera;
	t_camera_plane	cam_plane;
	t_light			light;
	t_ambient		ambient;
	t_list			*obj_list;
}	t_vars;

// file.c
int		file_init(t_vars *vars, char *file);
int		parse_file(int fd, t_vars *vars);
int		cam_init(t_vars *vars);

// init.c
void	win_init(t_vars *vars);

// hook.c
int		close_x(void *param);
int		key_hook(int keycode, void *param);
int		do_none(void *data);

// draw.c
void	draw(t_vars *vars);

// raytrace.c
int		raytrace(t_vec2 pixel, t_vars *vars);
t_obj	*raycast(t_vec2 p, t_vars *vars, t_ray *hit_ray);
bool	is_intersect(t_obj *obj, t_ray *ray1, t_ray *ray2);
t_ray	get_ray(t_vec2 p, t_vars *vars);
float	distance(t_point p1, t_point p2);

// intersect.c
bool	intersect_sphere(t_obj *obj, t_ray *ray1, t_ray *ray2);
bool	intersect_plane(t_obj *obj, t_ray *ray1, t_ray *ray2);

// color.c
int		color2int(int r, int g, int b);
int		get_color(t_obj *obj);

// light.c
bool	is_shadow(t_ray hit_ray, t_vars *vars);

#endif

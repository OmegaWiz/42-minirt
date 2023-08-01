/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:08:59 by moonegg           #+#    #+#             */
/*   Updated: 2023/08/01 16:18:12 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "algebra.h"
# include "../lib/mlx/mlx.h"
// # include "../lib/minilibx-linux/mlx.h"
# include "../lib/libft/libft.h"
# include "color.h"
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stdbool.h>

# ifndef WIN_WIDTH
#  define WIN_WIDTH 1080
# endif

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 720
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
	double	fov;
}	t_camera;

typedef struct s_camera_plane
{
	t_point	center;
	t_vec3	normal;
	double	width;
	double	height;
	t_vec3	right;
	t_vec3	down;
	t_point	top_left;
}	t_camera_plane;

typedef struct s_ambient
{
	double	brightness;
	int		color;
}	t_ambient;

typedef struct s_light
{
	t_point	origin;
	double	brightness;
	int		color;
}	t_light;

typedef struct s_sphere
{
	t_point	center;
	double	radius;
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
	t_vec3	direction;
	double	radius;
	double	height;
	int		color;
}	t_cylinder;

typedef struct s_cone
{
	t_point	center;
	t_vec3	direction;
	double	radius;
	double	height;
	int		color;
}	t_cone;

typedef enum e_obj_type
{
	SPHERE,
	CYLINDER,
	PLANE,
	CONE,
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

/*
PARSER
*/

typedef struct s_color
{
	int	x;
	int	y;
	int	z;
}	t_color;

//error
void		erase_split(char **av);
void		free_error(char *s, char **free);
void		error(char *s);
void		error_a_c_l(int cnt_a, int cnt_c, int cnt_l);

void		verify_file(char **av);
void		verify_a(char **chop);
void		verify_c(char **chop);
void		verify_l(char **chop);
void		verify_sp(char **chop);
void		verify_pl(char **chop);
void		verify_cy(char **chop);
void		verify_len(char **line, int len);
int			i_c_comment(char *line);
int			empty_line(char *line);

//utils_resolution_0
void		util_ori(char **origin);
void		util_dir(char *direction);
void		util_fov(char *fov);
void		util_ratio(char **ratio, int index);
void		util_color(char **color, int len);

//utils_resolution_1
void		util_radius(char *radius);

//utils_0
int			twod_is_decimal(char **str);
int			twod_is_digit(char **str);
int			str_is_digit(char *str);
int			str_is_decimal(char *str);

//get_info
void		get_info(t_vars *parser, char *av);
void		get_line(char *line, t_vars *parser);

//go_get
void		go_get_a(char **chop, t_vars *parser);
void		go_get_c(char **chop, t_vars *parser);
void		go_get_l(char **chop, t_vars *parser);
void		go_get_sp(char **chop, t_vars *parser);
void		go_get_pl(char **chop, t_vars *parser);
void		go_get_cy(char **chop, t_vars *parser);
void		go_get_co(char **chop, t_vars *parser);

//utils_get
int			*get_digit(char *digit, int	*color);
double		*get_decimal(char *dec, double *decimal);
void		get_color(char **colour, int *color);
void		get_point(char **xyz, t_point *pos);
void		get_vec3(char **xyz, t_vec3 *pos);

//print_test
void		print_ambi(t_vars *parser);
void		print_camera(t_vars *parser);
void		print_light(t_vars *parser);
void		print_sp(t_vars *parser);
void		print_pl(t_vars *parser);
void		print_cy(t_vars *parser);

/*
RENDERER
*/
// color.c
int			color2int(int r, int g, int b);
int			obj_color(t_obj *obj);
int			color_scale(int color, double scale);
int			color_add(int color1, int color2);
int			color_mult(int color1, int color2);

// draw.c
void		draw(t_vars *vars);
void		my_mlx_pixel_put(t_data *data, t_vec2 px, int color);

// file.c
int			file_init(t_vars *vars, char *file);
int			parse_file(int fd, t_vars *vars);
int			cam_init(t_vars *vars);

// hook.c
int			close_x(void *param);
int			key_hook(int keycode, void *param);
int			do_none(void *data);

// init.c
void		vars_init(t_vars *vars);
void		win_init(t_vars *vars);

// intersect.c
int			is_intersect(t_obj *obj, t_ray *ray1, t_ray *ray2);
double		solve_quadratic(double a, double b, double c);

// obj_camera.c
void		cam_translate(t_vars *vars);

// obj_cone.c
int			intersect_cone(t_obj *obj, t_ray *ray1, t_ray *ray2);

// obj_cylinder.c
int			intersect_cylinder(t_obj *obj, t_ray *ray1, t_ray *ray2);
t_cylinder	*translate_cylinder(void *obj, t_point ori_pt, t_vec3 ori_vec);

// obj_cylinder_intersect.c
int			intersect_cylinder_top(t_cylinder *cylinder,
				t_ray *ray1, t_ray *ray2);
int			intersect_cylinder_bot(t_cylinder *cylinder,
				t_ray *ray1, t_ray *ray2);
int			intersect_cylinder_body(t_cylinder *cylinder,
				t_ray *ray1, t_ray *ray2);

// obj_plane.c
int			intersect_plane(t_obj *obj, t_ray *ray1, t_ray *ray2);
t_plane		*translate_plane(void *obj, t_point ori_pt, t_vec3 ori_vec);

// obj_sphere.c
int			intersect_sphere(t_obj *obj, t_ray *ray1, t_ray *ray2);
t_sphere	*translate_sphere(void *obj, t_point ori_pt, t_vec3 ori_vec);

// raycast.c
t_obj		*raycast(t_vec2 p, t_vars *vars, t_ray *hit_ray);
t_ray		get_ray(t_vec2 p, t_vars *vars);

// raytrace.c
int			raytrace(t_vec2 pixel, t_vars *vars);

// shade.c
int			shade(t_ray hit_ray, t_obj *hit_obj, t_vars *vars, int color);

// shadow.c
int			is_shadow(t_ray hit_ray, t_vars *vars);

// translate.c
void		translate_obj(t_vars *vars, t_point ori_pt, t_vec3 ori_vec);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 08:50:18 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/08/01 10:51:09 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	file_init(t_vars *vars, char *file)
{
	int	fd;

	(void) file;
	fd = 2;
	if (fd < 0)
		return (0);
	if (parse_file(fd, vars) != 0)
		return (1);
	close(fd);
	return (0);
}

int	parse_file(int fd, t_vars *vars)
{
	(void) fd;
	(void) vars;
	return (0);
}
// int	parse_file(int fd, t_vars *vars)
// {
// 	t_sphere	*sphere;
// 	t_plane		*plane;
// 	t_cylinder	*cylinder;
// 	t_obj		*obj;

// 	(void) fd;
// 	vars->camera.origin = point(0, 0, 0);
// 	vars->camera.direction = vec3(0, 0, 1);
// 	vars->camera.fov = 90;
// 	cam_init(vars);

// 	vars->light.origin = point(20, 20, 0);
// 	vars->light.color = color2int(255, 255, 255);
// 	vars->light.brightness = 1;

// 	vars->ambient.color = color2int(128, 128, 128);
// 	vars->ambient.brightness = 0.5;

// 	vars->obj_list = NULL;

// 	sphere = malloc(sizeof(t_sphere));
// 	sphere->center = point(-5, 10, 50);
// 	sphere->radius = 7;
// 	sphere->color = color2int(255, 0, 0);
// 	obj = malloc(sizeof(t_obj));
// 	obj->type = SPHERE;
// 	obj->obj = sphere;
// 	// ft_lstadd_back(&vars->obj_list, ft_lstnew(obj));

// 	sphere = malloc(sizeof(t_sphere));
// 	sphere->center = point(15, 5, 50);
// 	sphere->radius = 5;
// 	sphere->color = color2int(0, 255, 0);
// 	obj = malloc(sizeof(t_obj));
// 	obj->type = SPHERE;
// 	obj->obj = sphere;
// 	// ft_lstadd_back(&vars->obj_list, ft_lstnew(obj));

// 	sphere = malloc(sizeof(t_sphere));
// 	sphere->center = point(35, 5, 50);
// 	sphere->radius = 5;
// 	sphere->color = color2int(255, 0, 0);
// 	obj = malloc(sizeof(t_obj));
// 	obj->type = SPHERE;
// 	obj->obj = sphere;
// 	ft_lstadd_back(&vars->obj_list, ft_lstnew(obj));

// 	cylinder = malloc(sizeof(t_cylinder));
// 	cylinder->center = point(0, 10, 50);
// 	cylinder->direction = vec3_normalize(vec3(0, 1, -0.5));
// 	cylinder->radius = 5;
// 	cylinder->height = 15;
// 	cylinder->color = color2int(0, 255, 0);
// 	obj = malloc(sizeof(t_obj));
// 	obj->type = CYLINDER;
// 	obj->obj = cylinder;
// 	ft_lstadd_back(&vars->obj_list, ft_lstnew(obj));

// 	plane = malloc(sizeof(t_plane));
// 	plane->center = point(0, -20, 0);
// 	plane->normal = vec3(0, 1, 0);
// 	plane->color = color2int(0, 0, 255);
// 	obj = malloc(sizeof(t_obj));
// 	obj->type = PLANE;
// 	obj->obj = plane;
// 	ft_lstadd_back(&vars->obj_list, ft_lstnew(obj));

// 	return (0);
// }

int	cam_init(t_vars *vars)
{
	t_camera		*cam;
	t_camera_plane	*cam_pln;

	cam = &vars->camera;
	cam_pln = &vars->cam_plane;
	cam_pln->center = cam->origin;
	cam_pln->normal = cam->direction;
	cam_pln->width = 2 * tan((cam->fov / 2) * (M_PI / 180));
	cam_pln->height = cam_pln->width * ((double) WIN_HEIGHT / WIN_WIDTH);
	cam_pln->right = vec3_cross(cam_pln->normal, vec3(0, 1, 0));
	cam_pln->down = vec3_cross(cam_pln->right, cam_pln->normal);
	cam_pln->top_left = point_add(cam_pln->center, point_neg(
				vec3_to_point(vec3_scale(cam_pln->right, cam_pln->width / 2))));
	cam_pln->top_left = point_add(cam_pln->top_left, point_neg(
				vec3_to_point(vec3_scale(cam_pln->down, cam_pln->height / 2))));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 08:50:18 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/07/06 09:49:34 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	file_init(t_vars *vars, char *file)
{
	int	fd;

	// printf("file: %s\n", file);
	// fd = open(file, O_RDONLY);
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
	t_sphere	*sphere;
	t_plane		*plane;
	t_obj		*obj;

	(void) fd;
	vars->camera.origin = point(0, 0, 0);
	vars->camera.direction = vec3(0, 0, 1);
	vars->camera.fov = 90;
	cam_init(vars);

	vars->light.origin = point(0, 100, 0);
	vars->light.color = color2int(255, 255, 255);
	vars->light.brightness = 0.5;

	vars->obj_list = NULL;

	sphere = malloc(sizeof(t_sphere));
	sphere->center = point(-10, 10, 50);
	sphere->radius = 10;
	sphere->color = color2int(255, 0, 0);
	obj = malloc(sizeof(t_obj));
	obj->type = SPHERE;
	obj->obj = sphere;
	ft_lstadd_back(&vars->obj_list, ft_lstnew(obj));

	sphere = malloc(sizeof(t_sphere));
	sphere->center = point(15, 5, 50);
	sphere->radius = 5;
	sphere->color = color2int(0, 255, 0);
	obj = malloc(sizeof(t_obj));
	obj->type = SPHERE;
	obj->obj = sphere;
	ft_lstadd_back(&vars->obj_list, ft_lstnew(obj));

	plane = malloc(sizeof(t_plane));
	plane->center = point(0, -50, 0);
	plane->normal = vec3(0.2, 1, 0);
	plane->color = color2int(0, 0, 255);
	obj = malloc(sizeof(t_obj));
	obj->type = PLANE;
	obj->obj = plane;
	ft_lstadd_back(&vars->obj_list, ft_lstnew(obj));

	return (0);
}

int	cam_init(t_vars *vars)
{
	t_camera	*cam;
	t_camera_plane	*cam_plane;

	cam = &vars->camera;
	cam_plane = &vars->cam_plane;
	cam_plane->center = cam->origin;
	cam_plane->normal = cam->direction;
	cam_plane->width = 2 * tan((cam->fov / 2) * (M_PI / 180));
	cam_plane->height = cam_plane->width * ((float) WIN_HEIGHT / WIN_WIDTH);
	printf("width: %f height: %f\n", cam_plane->width, cam_plane->height);
	cam_plane->right = vec3_cross(cam_plane->normal, vec3(0, 1, 0));
	cam_plane->down = vec3_cross(cam_plane->right, cam_plane->normal);
	cam_plane->top_left = point_add(cam_plane->center, point_neg(
		vec3_to_point(vec3_scale(cam_plane->right, cam_plane->width / 2))));
	cam_plane->top_left = point_add(cam_plane->top_left, point_neg(
		vec3_to_point(vec3_scale(cam_plane->down, cam_plane->height / 2))));
	return (0);
}

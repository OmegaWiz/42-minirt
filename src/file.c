/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 08:50:18 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/07/05 09:14:31 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	file_init(t_vars *vars, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	if (!parse_file(fd, vars))
		return (0);
	close(fd);
	return (1);
}

int	parse_file(int fd, t_vars *vars)
{
	t_sphere	*sphere;
	t_obj		*obj;

	vars->camera.origin = point(0, 0, 0);
	vars->camera.direction = vec3(0, 0, -1);
	vars->camera.fov = 90;
	cam_init(vars);

	sphere = malloc(sizeof(t_sphere));
	sphere->center = point(0, 0, 20);
	sphere->radius = 5;
	obj = malloc(sizeof(t_obj));
	obj->type = SPHERE;
	obj->obj = sphere;
	ft_lstadd_back(&vars->obj_list, ft_lstnew(obj));
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
	cam_plane->height = cam_plane->width * (WIN_HEIGHT / WIN_WIDTH);
	cam_plane->right = vec3_cross(cam_plane->normal, vec3(0, 1, 0));
	cam_plane->down = vec3_cross(cam_plane->right, cam_plane->normal);
	cam_plane->top_left = point_sub(cam_plane->center,
		vec3_to_point(vec3_scale(cam_plane->right, cam_plane->width / 2)));
	cam_plane->top_left = point_add(cam_plane->top_left,
		vec3_to_point(vec3_scale(cam_plane->down, cam_plane->height / 2)));
}

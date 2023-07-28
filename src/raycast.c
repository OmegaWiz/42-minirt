/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:20:37 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/07/28 16:54:52 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_obj	*raycast(t_vec2 p, t_vars *vars, t_ray *hit_ray)
{
	t_ray	ray1;
	t_ray	ray2;
	t_list	*lst;
	t_obj	*hit_obj;
	double	min_dist;

	ray1 = get_ray(p, vars);
	min_dist = INFINITY;
	hit_obj = NULL;
	lst = vars->obj_list;
	while (lst)
	{
		if (is_intersect((t_obj *)(lst->content), &ray1, &ray2) == 1)
		{
			if (point_distance(vars->camera.origin, ray2.origin) < min_dist)
			{
				min_dist = point_distance(vars->camera.origin, ray2.origin);
				hit_obj = (t_obj *)(lst->content);
				*hit_ray = ray2;
			}
		}
		lst = lst->next;
	}
	return (hit_obj);
}

double	calc_z(t_vars *vars)
{
	double	fov;

	fov = vars->camera.fov;
	fov = fov * M_PI / 180;
	return (1 / tan(fov / 2));
}

t_ray	get_ray(t_vec2 p, t_vars *vars)
{
	// t_ray	ray;
	// double	length;
	// t_point	pixel;

	// ray.origin = vars->camera.origin;
	// length = tan((vars->camera.fov / 2) * M_PI / 180);
	// pixel.x = (2 * ((p.x + 0.5) / WIN_WIDTH) - 1)
	// 	* length * vars->cam_plane.width / 2;
	// pixel.y = (1 - 2 * ((p.y + 0.5) / WIN_HEIGHT))
	// 	* length * vars->cam_plane.height / 2;
	// pixel.z = 1.0f;
	// ray.direction = vec3_normalize(point_sub(pixel, ray.origin));

	t_ray	ray;
	t_vec2	pp;
	t_vec3	cam_fru[3];

	pp.x = (p.x / (double) WIN_WIDTH * 2.0 - 1.0) * ((double) WIN_WIDTH / (double) WIN_HEIGHT);
	pp.y = (p.y / (double) WIN_HEIGHT * 2.0 - 1.0) * -1.0;
	ray.origin = vars->camera.origin;
	cam_fru[0] = vec3_normalize(vars->camera.direction);
	cam_fru[1] = vec3_normalize(vec3_cross(cam_fru[0], vec3(0, 1, 0)));
	if (vars->camera.direction.x == 0 && vars->camera.direction.y == 1 && vars->camera.direction.z == 0)
		cam_fru[1] = vec3(1, 0, 0);
	cam_fru[2] = vec3_normalize(vec3_cross(cam_fru[1], cam_fru[0]));
	if (vars->camera.direction.x == 0 && vars->camera.direction.y == 1 && vars->camera.direction.z == 0)
		cam_fru[2] = vec3(0, 0, 1);
	ray.direction = vec3_normalize(vec3_add(vec3_add(vec3_scale(cam_fru[1],
			pp.x), vec3_scale(cam_fru[2], pp.y)), vec3_scale(cam_fru[0],
					calc_z(vars))));
	return (ray);
}

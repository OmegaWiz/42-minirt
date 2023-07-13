/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:20:37 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/07/12 19:46:20 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_obj	*raycast(t_vec2 p, t_vars *vars, t_ray *hit_ray)
{
	t_ray	ray1;
	t_ray	ray2;
	t_list	*lst;
	t_obj	*hit_obj;
	float	min_dist;

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

t_ray	get_ray(t_vec2 p, t_vars *vars)
{
	t_ray	ray;
	float	length;
	t_point	pixel;

	ray.origin = vars->camera.origin;
	length = tan((vars->camera.fov / 2) * M_PI / 180);
	pixel.x = (2 * ((p.x + 0.5) / WIN_WIDTH) - 1)
		* length * vars->cam_plane.width / 2;
	pixel.y = (1 - 2 * ((p.y + 0.5) / WIN_HEIGHT))
		* length * vars->cam_plane.height / 2;
	pixel.z = 1.0f;
	ray.direction = vec3_normalize(point_sub(pixel, ray.origin));
	return (ray);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:15:22 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/07/12 20:15:18by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	intersect_cylinder_top(t_cylinder *cylinder, t_ray *ray1, t_ray *ray2)
{
	t_plane	tmp_plane;
	t_obj	tmp_obj;
	t_point	topcap_cen;

	tmp_obj.obj = &tmp_plane;
	tmp_obj.type = PLANE;
	topcap_cen = point_translate(cylinder->center,
			cylinder->direction, cylinder->height / 2);
	tmp_plane.center = topcap_cen;
	tmp_plane.normal = cylinder->direction;
	if (intersect_plane(&tmp_obj, ray1, ray2))
	{
		if (point_distance(ray2->origin, topcap_cen) <= cylinder->radius)
			return (1);
	}
	return (0);
}

int	intersect_cylinder_bot(t_cylinder *cylinder, t_ray *ray1, t_ray *ray2)
{
	t_plane	tmp_plane;
	t_obj	tmp_obj;
	t_point	botcap_cen;

	tmp_obj.obj = &tmp_plane;
	tmp_obj.type = PLANE;
	botcap_cen = point_translate(cylinder->center,
			cylinder->direction, cylinder->height / -2);
	tmp_plane.center = botcap_cen;
	tmp_plane.normal = vec3_neg(cylinder->direction);
	if (intersect_plane(&tmp_obj, ray1, ray2))
	{
		if (point_distance(ray2->origin, botcap_cen) < cylinder->radius + 1e-4)
			return (1);
	}
	return (0);
}

int	intersect_cylinder_body(t_cylinder *cylinder, t_ray *ray1, t_ray *ray2)
{
	t_vec3		oc;
	t_point		abc;
	t_point		bottom_center;
	double		t;
	double		m;

	bottom_center = point_translate(cylinder->center,
			cylinder->direction, cylinder->height / -2.0f);
	oc = point_sub(ray1->origin, bottom_center);
	abc.x = vec3_dot(ray1->direction, ray1->direction)
		- pow(vec3_dot(ray1->direction, cylinder->direction), 2);
	abc.y = 2.0f * (vec3_dot(oc, ray1->direction)
			- vec3_dot(ray1->direction, cylinder->direction)
			* vec3_dot(oc, cylinder->direction));
	abc.z = vec3_dot(oc, oc) - pow(vec3_dot(oc, cylinder->direction), 2)
		- cylinder->radius * cylinder->radius;
	t = solve_quadratic(abc.x, abc.y, abc.z);
	if (t < 0.0f)
		return (0);
	m = vec3_dot(ray1->direction, cylinder->direction) * t
		+ vec3_dot(oc, cylinder->direction);
	if (m < -0.0002f || m > cylinder->height)
		return (0);
	ray2->origin = point_translate(ray1->origin, ray1->direction, t);
	ray2->direction = vec3_normalize(point_sub(ray2->origin, point_translate(bottom_center,
					cylinder->direction, m)));
	return (1);
}

int	intersect_cylinder(t_obj *obj, t_ray *ray1, t_ray *ray2)
{
	t_ray	tmp_ray;
	double	min_dist;
	int		i;
	int		(*intersect [3])(t_cylinder *, t_ray *, t_ray *);

	min_dist = INFINITY;
	intersect[0] = intersect_cylinder_body;
	intersect[1] = intersect_cylinder_top;
	intersect[2] = intersect_cylinder_bot;
	i = -1;
	while (++i < 3)
	{
		if (intersect[i]((t_cylinder *) obj->obj, ray1, &tmp_ray) == 1)
		{
			if (point_distance(ray1->origin, tmp_ray.origin) < min_dist)
			{
				min_dist = point_distance(ray1->origin, tmp_ray.origin);
				ray2->origin = tmp_ray.origin;
				ray2->direction = tmp_ray.direction;
			}
		}
	}
	if (min_dist == INFINITY)
		return (0);
	return (1);
}

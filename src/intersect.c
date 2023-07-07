/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:04:20 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/07/07 07:58:48 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	is_intersect(t_obj *obj, t_ray *ray1, t_ray *ray2)
{
	if (obj->type == SPHERE)
		return (intersect_sphere(obj, ray1, ray2));
	else if (obj->type == CYLINDER)
		return (intersect_cylinder(obj, ray1, ray2));
	else if (obj->type == PLANE)
		return (intersect_plane(obj, ray1, ray2));
	return (false);
}

bool	intersect_sphere(t_obj *obj, t_ray *ray1, t_ray *ray2)
{
	t_sphere	*sphere;
	t_vec3		oc;
	t_point		abc;
	t_point		d2r;

	sphere = (t_sphere *) obj->obj;
	oc = point_sub(ray1->origin, sphere->center);
	abc.x = vec3_dot(ray1->direction, ray1->direction);
	abc.y = 2.0f * vec3_dot(oc, ray1->direction);
	abc.z = vec3_dot(oc, oc) - sphere->radius * sphere->radius;
	d2r.x = abc.y * abc.y - 4.0f * abc.x * abc.z;
	if (d2r.x < 0.0f)
		return (false);
	d2r.y = (-abc.y - sqrtf(d2r.x)) / (2.0f * abc.x);
	d2r.z = (-abc.y + sqrtf(d2r.x)) / (2.0f * abc.x);
	if (d2r.y < 0.0f && d2r.z < 0.0f)
		return (false);
	if (d2r.y < 0.0f || d2r.y > d2r.z)
		d2r.y = d2r.z;
	if (d2r.z < 0.0f)
		d2r.z = d2r.y;
	ray2->origin = point_add(ray1->origin,
			vec3_to_point(vec3_scale(ray1->direction, d2r.y)));
	ray2->direction = vec3_normalize(point_sub(ray2->origin, sphere->center));
	return (true);
}

bool	intersect_plane(t_obj *obj, t_ray *ray1, t_ray *ray2)
{
	t_plane		*plane;
	float		denom;
	float		t;

	plane = (t_plane *) obj->obj;
	denom = vec3_dot(plane->normal, ray1->direction);
	if (fabs(denom) > 0.0001)
	{
		t = vec3_dot(point_sub(plane->center, ray1->origin),
				plane->normal) / denom;
		if (t > 0)
		{
			ray2->origin = point_add(ray1->origin,
					vec3_to_point(vec3_scale(ray1->direction, t)));
			ray2->direction = plane->normal;
			return (true);
		}
	}
	return (false);
}

bool	intersect_cylinder(t_obj *obj, t_ray *ray1, t_ray *ray2)
{
	t_cylinder	*cylinder;
	t_vec3		oc;
	t_point		abc;
	t_point		d2r;
	float		t;
	t_vec3		tmp;

	cylinder = (t_cylinder *) obj->obj;
	oc = point_sub(ray1->origin, cylinder->center);
	abc.x = vec3_dot(ray1->direction, ray1->direction) - pow(vec3_dot(ray1->direction, cylinder->normal), 2);
	abc.y = 2 * (vec3_dot(ray1->direction, oc) - vec3_dot(ray1->direction, cylinder->normal) * vec3_dot(oc, cylinder->normal));
	abc.z = vec3_dot(oc, oc) - pow(vec3_dot(oc, cylinder->normal), 2) - pow(cylinder->radius, 2);
	d2r.x = abc.y * abc.y - 4 * abc.x * abc.z;
	if (d2r.x < 0)
		return (false);
	d2r.y = (-abc.y - sqrt(d2r.x)) / (2 * abc.x);
	d2r.z = (-abc.y + sqrt(d2r.x)) / (2 * abc.x);
	if (d2r.y < 0 && d2r.z < 0)
		return (false);
	if (d2r.y < 0)
		d2r.y = d2r.z;
	if (d2r.z < 0)
		d2r.z = d2r.y;
	if (d2r.y > d2r.z)
		d2r.y = d2r.z;
	t = d2r.y;
	ray2->origin = point_add(ray1->origin, vec3_to_point(vec3_scale(ray1->direction, t)));
	tmp = point_sub(ray2->origin, cylinder->center);
	ray2->direction = vec3_normalize(vec3_sub(tmp, vec3_scale(cylinder->normal, vec3_dot(tmp, cylinder->normal))));
	return (true);
}

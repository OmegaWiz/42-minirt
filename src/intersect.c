/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:04:20 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/07/05 16:14:45 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool		intersect_sphere(t_obj *obj, t_ray *ray1, t_ray *ray2)
{
	t_sphere *sphere;

	sphere = (t_sphere *) obj->obj;
	t_vec3 oc = {ray1->origin.x - sphere->center.x, ray1->origin.y - sphere->center.y, ray1->origin.z - sphere->center.z};
	float a = vec3_dot(ray1->direction, ray1->direction);
	float b = 2.0f * vec3_dot(oc, ray1->direction);
	float c = vec3_dot(oc, oc) - sphere->radius * sphere->radius;
	float discriminant = b * b - 4.0f * a * c;
	if (discriminant < 0.0f) {
		return false;
	}
	float sqrtd = sqrtf(discriminant);
	float root1 = (-b - sqrtd) / (2.0f * a);
	float root2 = (-b + sqrtd) / (2.0f * a);
	if (root1 < 0.0f && root2 < 0.0f) {
		return false;
	}
	if (root1 < 0.0f) {
		root1 = root2;
	}
	if (root2 < 0.0f) {
		root2 = root1;
	}
	if (root1 > root2) {
		root1 = root2;
	}
	(void) ray2;
	return true;
}

bool		intersect_plane(t_obj *obj, t_ray *ray1, t_ray *ray2)
{
	t_plane		*plane;
	float		denom;
	float		t;

	plane = (t_plane *) obj->obj;
	denom = vec3_dot(plane->normal, ray1->direction);
	if (fabs(denom) > 0.0001)
	{
		t = vec3_dot(point_sub(plane->center, ray1->origin), plane->normal) / denom;
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

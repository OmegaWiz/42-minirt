/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:04:20 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/07/12 19:46:32 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	is_intersect(t_obj *obj, t_ray *ray1, t_ray *ray2)
{
	if (obj->type == SPHERE)
		return (intersect_sphere(obj, ray1, ray2));
	else if (obj->type == CYLINDER)
		return (intersect_cylinder(obj, ray1, ray2));
	else if (obj->type == PLANE)
		return (intersect_plane(obj, ray1, ray2));
	return (0);
}

double	solve_quadratic(double a, double b, double c)
{
	double	d2r;
	double	sol1;
	double	sol2;

	d2r = (b * b) - (4.0f * a * c);
	if (d2r < 0.0f)
		return (-1.0f);
	sol1 = (-b - sqrtf(d2r)) / (2.0f * a);
	sol2 = (-b + sqrtf(d2r)) / (2.0f * a);
	if (sol1 < 0.0f && sol2 < 0.0f)
		return (-1.0f);
	if (sol1 < 0.0f || sol1 > sol2)
		return (sol2);
	return (sol1);
}

int	intersect_sphere(t_obj *obj, t_ray *ray1, t_ray *ray2)
{
	t_sphere	*sphere;
	t_vec3		oc;
	t_point		abc;
	double		t;

	sphere = (t_sphere *) obj->obj;
	oc = point_sub(ray1->origin, sphere->center);
	abc.x = vec3_dot(ray1->direction, ray1->direction);
	abc.y = 2.0f * vec3_dot(oc, ray1->direction);
	abc.z = vec3_dot(oc, oc) - sphere->radius * sphere->radius;
	t = solve_quadratic(abc.x, abc.y, abc.z);
	if (t < 0.0f)
		return (0);
	ray2->origin = point_translate(ray1->origin, ray1->direction, t);
	ray2->direction = vec3_normalize(point_sub(ray2->origin, sphere->center));
	return (1);
}

int	intersect_plane(t_obj *obj, t_ray *ray1, t_ray *ray2)
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
			return (1);
		}
	}
	return (0);
}

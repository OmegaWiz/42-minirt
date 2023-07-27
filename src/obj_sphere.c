/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 09:32:15 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/07/27 13:35:55 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

t_sphere	*translate_sphere(void *obj, t_point ori_pt, t_vec3 ori_vec)
{
	t_sphere	*sphere;

	sphere = (t_sphere *) obj;
	sphere->center = point_add(sphere->center, point_neg(ori_pt));
	(void) ori_vec;
	return (sphere);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 09:37:01 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/07/27 14:20:54 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	intersect_plane(t_obj *obj, t_ray *ray1, t_ray *ray2)
{
	t_plane		*plane;
	double		denom;
	double		t;

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

t_plane		*translate_plane(void *obj, t_point ori_pt, t_vec3 ori_vec)
{
	t_plane		*plane;

	plane = (t_plane *) obj;
	plane->center = point_add(plane->center, point_neg(ori_pt));
	(void) ori_vec;
	return (plane);
}

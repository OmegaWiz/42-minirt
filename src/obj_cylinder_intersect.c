/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_cylinder_intersect.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:15:22 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/08/01 10:49:53 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

int	intersect_cylinder_body(t_cylinder *cy, t_ray *ray1, t_ray *ray2)
{
	t_vec3		oc;
	t_point		abc;
	t_point		bot_cen;
	double		tm[2];

	bot_cen = point_translate(cy->center, cy->direction, cy->height / -2.0f);
	oc = point_sub(ray1->origin, bot_cen);
	abc.x = vec3_dot(ray1->direction, ray1->direction)
		- pow(vec3_dot(ray1->direction, cy->direction), 2);
	abc.y = 2.0f * (vec3_dot(oc, ray1->direction)
			- vec3_dot(ray1->direction, cy->direction)
			* vec3_dot(oc, cy->direction));
	abc.z = vec3_dot(oc, oc) - pow(vec3_dot(oc, cy->direction), 2)
		- cy->radius * cy->radius;
	tm[0] = solve_quadratic(abc.x, abc.y, abc.z);
	if (tm[0] < 0.0f)
		return (0);
	tm[1] = vec3_dot(ray1->direction, cy->direction) * tm[0]
		+ vec3_dot(oc, cy->direction);
	if (tm[1] < -0.0002f || tm[1] > cy->height)
		return (0);
	ray2->origin = point_translate(ray1->origin, ray1->direction, tm[0]);
	ray2->direction = vec3_normalize(point_sub(ray2->origin, \
	point_translate(bot_cen, cy->direction, tm[1])));
	return (1);
}

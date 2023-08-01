/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 09:37:23 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/08/01 16:17:45 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	intersect_cone_bot(t_cone *cone, t_ray *ray1, t_ray *ray2)
{
	t_plane	tmp_plane;
	t_obj	tmp_obj;
	t_point	botcap_cen;

	tmp_obj.obj = &tmp_plane;
	tmp_obj.type = PLANE;
	botcap_cen = point_translate(cone->center,
			cone->direction, cone->height / -2);
	tmp_plane.center = botcap_cen;
	tmp_plane.normal = vec3_neg(cone->direction);
	if (intersect_plane(&tmp_obj, ray1, ray2))
	{
		if (point_distance(ray2->origin, botcap_cen) < cone->radius + 1e-4)
			return (1);
	}
	return (0);
}

// tmk = a,b,c,t,m,k
int	intersect_cone_body(t_cone *cone, t_ray *ray1, t_ray *ray2)
{
	t_vec3		oc;
	t_vec3		dir;
	t_point		bot_cen;
	double		tmk[6];

	dir = vec3_neg(cone->direction);
	bot_cen = point_translate(cone->center, dir, cone->height / -2);
	tmk[5] = cone->radius / cone->height;
	oc = point_sub(ray1->origin, bot_cen);
	tmk[0] = vec3_dot(ray1->direction, ray1->direction) - (1 + tmk[5] * tmk[5])
		* pow(vec3_dot(ray1->direction, dir), 2);
	tmk[1] = 2.0f * (vec3_dot(ray1->direction, oc) - vec3_dot(ray1->direction,
				dir) * vec3_dot(oc, dir) * (1 + tmk[5] * tmk[5]));
	tmk[2] = vec3_dot(oc, oc) - (pow(vec3_dot(oc, dir), 2)
			* (1 + tmk[5] * tmk[5]));
	tmk[3] = solve_quadratic(tmk[0], tmk[1], tmk[2]);
	if (tmk[3] < 0.0f)
		return (0);
	tmk[4] = vec3_dot(ray1->direction, dir) * tmk[3] + vec3_dot(oc, dir);
	if (tmk[4] < -0.0002f || tmk[4] > cone->height)
		return (0);
	ray2->origin = point_translate(ray1->origin, ray1->direction, tmk[3]);
	ray2->direction = vec3_normalize(point_sub(ray2->origin, point_translate(
					bot_cen, dir, tmk[4] * (1 + tmk[5] * tmk[5]))));
	return (1);
}

int	intersect_cone(t_obj *obj, t_ray *ray1, t_ray *ray2)
{
	t_ray	tmp_ray;
	double	min_dist;
	int		i;
	int		(*intersect [2])(t_cone *, t_ray *, t_ray *);

	min_dist = INFINITY;
	intersect[0] = intersect_cone_body;
	intersect[1] = intersect_cone_bot;
	i = -1;
	while (++i < 2)
	{
		if (intersect[i]((t_cone *) obj->obj, ray1, &tmp_ray) == 1)
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

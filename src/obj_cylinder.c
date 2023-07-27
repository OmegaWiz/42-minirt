/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 09:37:23 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/07/27 13:35:38 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

t_cylinder	*translate_cylinder(void *obj, t_point ori_pt, t_vec3 ori_vec)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *) obj;
	cylinder->center = point_add(cylinder->center, point_neg(ori_pt));
	(void) ori_vec;
	return (cylinder);
}

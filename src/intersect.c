/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:04:20 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/08/01 15:06:54 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	is_intersect(t_obj *obj, t_ray *ray1, t_ray *ray2)
{
	if (obj->type == SPHERE)
		return (intersect_sphere(obj, ray1, ray2));
	else if (obj->type == CYLINDER)
		return (intersect_cylinder(obj, ray1, ray2));
	else if (obj->type == PLANE)
		return (intersect_plane(obj, ray1, ray2));
	else if (obj->type == CONE)
		return (intersect_cone(obj, ray1, ray2));
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

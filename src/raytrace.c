/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 08:47:21 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/07/27 13:30:42 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	raytrace(t_vec2 p, t_vars *vars)
{
	t_ray	hit_ray;
	t_obj	*hit_obj;
	int		color;

	hit_obj = raycast(p, vars, &hit_ray);
	color = color_scale(vars->ambient.color, vars->ambient.brightness);
	if (hit_obj == NULL)
		return (color);
	else
	{
		if (is_shadow(hit_ray, vars) == 1)
			return (color);
		else
			return (color_add(color_mult(color, get_color(hit_obj)),
					shade(hit_ray, hit_obj, vars, get_color(hit_obj))));
	}
	return (color);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:33:38 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/07/27 13:30:42 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	shade(t_ray hit_ray, t_obj *hit_obj, t_vars *vars, int color)
{
	t_ray	light_ray;
	double	angle;

	light_ray.origin = point_translate(hit_ray.origin, hit_ray.direction, 1e-4);
	light_ray.direction = vec3_normalize(point_sub(vars->light.origin,
				hit_ray.origin));
	angle = vec3_dot(light_ray.direction, hit_ray.direction);
	angle /= (vec3_length(light_ray.direction)
			* vec3_length(hit_ray.direction));
	color = color_mult(color, color_scale(vars->light.color,
				vars->light.brightness));
	color = color_scale(color, angle);
	(void) hit_obj;
	return (color);
}

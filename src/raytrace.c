/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 08:47:21 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/07/06 11:24:16 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	raytrace(t_vec2 p, t_vars *vars)
{
	t_ray	hit_ray;
	t_obj	*hit_obj;

	if (p.y == WIN_HEIGHT / 2)
		printf("raytracing at pixel %.0f %.0f\n", p.x, p.y);
	// printf("raytracing at pixel %.0f %.0f\n", p.x, p.y);
	hit_obj = raycast(p, vars, &hit_ray);
	if (hit_obj == NULL) // hit no object
		return (0); //for initial tests, there is no color ambience, return black
	if (is_shadow(hit_ray, vars) == true)
		return (0);
	return (get_color(hit_obj));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:57:47 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/07/05 20:38:27 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	is_visible(t_ray ray, t_vars *vars)
{
	t_light light = vars->light;
	t_point hit_point = ray.origin;
	t_vec3 to_light = {light.origin.x - hit_point.x, light.origin.y - hit_point.y, light.origin.z - hit_point.z};
	float distance_to_light = vec3_length(to_light);
	t_ray shadow_ray = {hit_point, to_light};
	bool is_shadowed = false;
	t_list *lst = vars->obj_list;
	while (lst)
	{
		t_obj *obj = (t_obj *) (lst->content);
		if (obj->type == SPHERE)
		{
			if (intersect_sphere(obj, &shadow_ray, NULL))
			{
				is_shadowed = true;
				break;
			}
		}
		else if (obj->type == PLANE)
		{
			if (intersect_plane(obj, &shadow_ray, NULL))
			{
				is_shadowed = true;
				break;
			}
		}
		lst = lst->next;
	}
	if (is_shadowed) {
		return false;
	}
	float attenuation = 1.0f / (distance_to_light * distance_to_light);
	float diffuse = vec3_dot(vec3_normalize(to_light), vec3(1, 1, 1)) * attenuation * light.brightness;
	return diffuse > 0.0f;
}

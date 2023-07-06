/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:57:47 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/07/06 12:11:03 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	is_shadow(t_ray hit_ray, t_vars *vars)
{
	t_ray	shadow_ray;
	t_ray	tmp;
	t_list	*lst;
	bool	is_shadow;

	shadow_ray.origin = point_translate(hit_ray.origin, hit_ray.direction, 1e-4);
	shadow_ray.direction = vec3_normalize(point_sub(vars->light.origin, hit_ray.origin));
	is_shadow = false;
	lst = vars->obj_list;
	while (lst)
	{
		if (is_intersect((t_obj *) (lst->content), &shadow_ray, &tmp) == true)
		{
			is_shadow = true;
			break ;
		}
		lst = lst->next;
	}
	return (is_shadow);
}

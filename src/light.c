/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:57:47 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/07/05 21:01:45 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	is_shadow(t_ray hit_ray, t_vars *vars)
{
	t_ray	shadow_ray;
	t_ray	tmp;
	t_list	*lst;
	bool	is_shadow;

	shadow_ray.origin = hit_ray.origin;
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

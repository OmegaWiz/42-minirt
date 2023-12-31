/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:57:47 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/08/01 04:39:15 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	is_shadow(t_ray hit_ray, t_vars *vars)
{
	t_ray	shadow_ray;
	t_ray	tmp;
	t_list	*lst;
	int		is_shadow;

	shadow_ray.origin = point_translate(hit_ray.origin,
			hit_ray.direction, 1e-4);
	shadow_ray.direction = vec3_normalize(point_sub(vars->light.origin,
				hit_ray.origin));
	is_shadow = 0;
	lst = vars->obj_list;
	while (lst)
	{
		if (is_intersect((t_obj *)(lst->content), &shadow_ray, &tmp) == 1)
		{
			is_shadow = 1;
			break ;
		}
		lst = lst->next;
	}
	return (is_shadow);
}

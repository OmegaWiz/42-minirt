/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:23:18 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/07/27 13:30:42 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	translate_obj(t_vars *vars, t_point ori_pt, t_vec3 ori_vec)
{
	t_list		*tmp;
	t_obj		*obj;

	cam_translate(vars);
	tmp = vars->obj_list;
	while (tmp)
	{
		obj = (t_obj *)tmp->content;
		if (obj->type == SPHERE)
			obj->obj = translate_sphere(obj->obj, ori_pt, ori_vec);
		else if (obj->type == PLANE)
			obj->obj = translate_plane(obj->obj, ori_pt, ori_vec);
		else if (obj->type == CYLINDER)
			obj->obj = translate_cylinder(obj->obj, ori_pt, ori_vec);
		tmp = tmp->next;
	}
	return ;
}

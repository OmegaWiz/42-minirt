/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:29:36 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/07/27 13:34:59 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	cam_translate(t_vars *vars)
{
	t_point		ori_pt;
	t_vec3		ori_vec;

	ori_pt = vars->camera.origin;
	ori_vec = vars->camera.direction;
	// vars->camera.origin = point(0, 0, 0);
	// vars->camera.direction = vec3(0, 0, 1);
	// cam_pln->center = point(0, 0, 0);
	// cam_pln->direction = vec3(0, 0, 1);
	// vars->light.origin = point_add(vars->light.origin, point_neg(ori_pt));
	// obj_translate(vars, ori_pt, ori_vec);
}

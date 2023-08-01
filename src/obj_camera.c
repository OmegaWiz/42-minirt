/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:29:36 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/08/01 10:40:42 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	cam_translate(t_vars *vars)
{
	t_point		ori_pt;
	t_vec3		ori_vec;

	ori_pt = vars->camera.origin;
	ori_vec = vars->camera.direction;
}

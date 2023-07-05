/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 09:25:39 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/07/05 19:58:10 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	color2int(int r, int g, int b)
{
	if (r > 255)
		r = 255;
	else if (r < 0)
		r = 0;
	if (g > 255)
		g = 255;
	else if (g < 0)
		g = 0;
	if (b > 255)
		b = 255;
	else if (b < 0)
		b = 0;
	return (r << 16 | g << 8 | b);
}

int	get_color(t_obj *obj)
{
	if (obj->type == SPHERE)
	{
		t_sphere *sphere = (t_sphere *) obj->obj;
		return (sphere->color);
	}
	else if (obj->type == PLANE)
	{
		t_plane *plane = (t_plane *) obj->obj;
		return (plane->color);
	}
	return (0);
}

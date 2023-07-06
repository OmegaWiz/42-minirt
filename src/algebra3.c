/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algebra3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:02:20 by moonegg           #+#    #+#             */
/*   Updated: 2023/07/06 11:23:39 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"

t_point	point(double x, double y, double z)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

t_point	point_add(t_point a, t_point b)
{
	return (point(a.x + b.x, a.y + b.y, a.z + b.z));
}

t_point	point_neg(t_point a)
{
	return (point(-a.x, -a.y, -a.z));
}

t_point	point_abs(t_point a)
{
	return (point(fabs(a.x), fabs(a.y), fabs(a.z)));
}

double	point_distance(t_point a, t_point b)
{
	return (sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2)));
}

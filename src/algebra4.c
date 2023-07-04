/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algebra4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moonegg <moonegg@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:03:18 by moonegg           #+#    #+#             */
/*   Updated: 2023/07/03 14:06:16 by moonegg          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"

t_point	vec3_to_point(t_vec3 a)
{
	return (point(a.x, a.y, a.z));
}

t_vec3	point_to_vec3(t_point a)
{
	return (vec3(a.x, a.y, a.z));
}

t_vec3	point_sub(t_point a, t_point b)
{
	return (vec3(a.x - b.x, a.y - b.y, a.z - b.z));
}

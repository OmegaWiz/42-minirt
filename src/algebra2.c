/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algebra2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moonegg <moonegg@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:00:16 by moonegg           #+#    #+#             */
/*   Updated: 2023/07/03 14:02:06 by moonegg          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"

double	vec3_dot(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

double	vec3_length(t_vec3 a)
{
	return (sqrt(vec3_dot(a, a)));
}

t_vec3	vec3_normalize(t_vec3 a)
{
	return (vec3_scale(a, 1 / vec3_length(a)));
}

t_vec3	vec3_neg(t_vec3 a)
{
	return (vec3_scale(a, -1));
}

t_vec3	vec3_abs(t_vec3 a)
{
	return (vec3(fabs(a.x), fabs(a.y), fabs(a.z)));
}

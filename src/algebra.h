/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algebra.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:01:24 by moonegg           #+#    #+#             */
/*   Updated: 2023/07/06 11:06:18 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGEBRA_H
# define ALGEBRA_H

# include <math.h>

typedef struct s_vec3
{
	double		x;
	double		y;
	double		z;
}				t_vec3;

typedef struct s_vec2
{
	double		x;
	double		y;
}				t_vec2;

typedef struct s_point
{
	double		x;
	double		y;
	double		z;
}				t_point;

t_vec3	vec3(double x, double y, double z);
t_vec3	vec3_add(t_vec3 a, t_vec3 b);
t_vec3	vec3_sub(t_vec3 a, t_vec3 b);
t_vec3	vec3_scale(t_vec3 a, double b);
t_vec3	vec3_cross(t_vec3 a, t_vec3 b);
double	vec3_dot(t_vec3 a, t_vec3 b);
double	vec3_length(t_vec3 a);
t_vec3	vec3_normalize(t_vec3 a);
t_vec3	vec3_neg(t_vec3 a);
t_vec3	vec3_abs(t_vec3 a);

t_point	point(double x, double y, double z);
t_point	point_add(t_point a, t_point b);
t_point	point_neg(t_point a);
t_point	point_abs(t_point a);
double	point_length(t_point a, t_point b);
t_point	point_translate(t_point a, t_vec3 b, double t);

t_point	vec3_to_point(t_vec3 a);
t_vec3	point_to_vec3(t_point a);
t_vec3	point_sub(t_point a, t_point b);

#endif

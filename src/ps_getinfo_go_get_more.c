/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_getinfo_go_get_more.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 04:36:47 by psaeyang          #+#    #+#             */
/*   Updated: 2023/08/01 15:10:09 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	go_get_co(char **chop, t_vars *parser)
{
	t_cone		*co;
	t_obj		*obj;
	char		**split;

	obj = malloc(sizeof(t_obj));
	co = malloc(sizeof(t_cone));
	split = ft_split(chop[1], ',');
	get_point(split, &co->center);
	erase_split(split);
	split = ft_split(chop[2], ',');
	get_vec3(split, &co->direction);
	erase_split(split);
	get_decimal(chop[3], &co->radius);
	get_decimal(chop[4], &co->height);
	split = ft_split(chop[5], ',');
	get_color(split, &co->color);
	obj->type = CONE;
	obj->obj = co;
	ft_lstadd_front(&parser->obj_list, ft_lstnew(obj));
	erase_split(split);
}

void	go_get_cy(char **chop, t_vars *parser)
{
	t_cylinder	*cy;
	t_obj		*obj;
	char		**split;

	obj = malloc(sizeof(t_obj));
	cy = malloc(sizeof(t_cylinder));
	split = ft_split(chop[1], ',');
	get_point(split, &cy->center);
	erase_split(split);
	split = ft_split(chop[2], ',');
	get_vec3(split, &cy->direction);
	erase_split(split);
	get_decimal(chop[3], &cy->radius);
	get_decimal(chop[4], &cy->height);
	split = ft_split(chop[5], ',');
	get_color(split, &cy->color);
	obj->type = CYLINDER;
	obj->obj = cy;
	ft_lstadd_front(&parser->obj_list, ft_lstnew(obj));
	erase_split(split);
}

void	go_get_pl(char **chop, t_vars *parser)
{
	t_plane	*plane;
	t_obj	*obj;
	char	**split;

	obj = malloc(sizeof(t_obj));
	plane = malloc(sizeof(t_plane));
	split = ft_split(chop[1], ',');
	get_point(split, &plane->center);
	erase_split(split);
	split = ft_split(chop[2], ',');
	get_vec3(split, &plane->normal);
	erase_split(split);
	split = ft_split(chop[3], ',');
	get_color(split, &plane->color);
	obj->type = PLANE;
	obj->obj = plane;
	ft_lstadd_front(&parser->obj_list, ft_lstnew(obj));
	erase_split(split);
}

void	go_get_sp(char **chop, t_vars *parser)
{
	t_sphere	*sphere;
	t_obj		*obj;
	char		**split;

	sphere = malloc(sizeof(t_sphere));
	split = ft_split(chop[1], ',');
	get_point(split, &sphere->center);
	erase_split(split);
	get_decimal(chop[2], &sphere->radius);
	split = ft_split(chop[3], ',');
	get_color(split, &sphere->color);
	obj = malloc(sizeof(t_obj));
	obj->type = SPHERE;
	obj->obj = sphere;
	ft_lstadd_front(&parser->obj_list, ft_lstnew(obj));
	erase_split(split);
}

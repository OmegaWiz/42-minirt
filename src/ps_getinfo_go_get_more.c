/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_getinfo_go_get_more.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 04:36:47 by psaeyang          #+#    #+#             */
/*   Updated: 2023/07/28 03:56:38 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

	// t_list *lst;
	// lst = parser->obj_list;
	// printf(BCYN"cy center == [%f], [%f], [%f]\n"RESET, cy->center.x, cy->center.y, cy->center.z);
	// printf(BGRN"cy normal == [%f], [%f], [%f]\n"RESET, cy->direction.x, cy->direction.y, cy->direction.z);
	// printf(BMAG"cy color == [%d], [%d], [%d]\n"RESET, (cy->color & (255 << 16)) >> 16, (cy->color & (255 << 8)) >> 8, cy->color & 255);
	// printf(BYEL"cy raduis height == [%f], [%f]\n"RESET, cy->radius, cy->height);

	erase_split(split);
}

void	go_get_pl(char **chop, t_vars *parser)
{
	t_plane	*plane;
	t_obj		*obj;
	char	**split;

	obj = malloc(sizeof(t_obj));
	plane = malloc(sizeof(t_plane));
	split = ft_split(chop[1], ',');
	get_point(split, &plane->center);
	erase_split(split);
	split = ft_split(chop[2], ',');
	erase_split(split);
	get_vec3(split, &plane->normal);
	split = ft_split(chop[3], ',');
	get_color(split, &plane->color);
	obj->type = PLANE;
	obj->obj = plane;
	ft_lstadd_front(&parser->obj_list, ft_lstnew(obj));

	// t_list *lst;
	// lst = parser->obj_list;
	// printf(BCYN"pl center == [%f], [%f], [%f]\n"RESET, plane->center.x, plane->center.y, plane->center.z);
	// printf(BGRN"pl normal == [%f], [%f], [%f]\n"RESET, plane->normal.x, plane->normal.y, plane->normal.z);
	// printf(BMAG"pl color == [%d], [%d], [%d]\n"RESET, (plane->color & (255 << 16)) >> 16, (plane->color & (255 << 8)) >> 8, plane->color & 255);
	// printf("---------------------------------------\n");

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

	// t_list *lst;
	// lst = parser->obj_list;
	// printf(BCYN"sp x == [%f], sp y == [%f], sp z == [%f]\n"RESET, sphere->center.x, sphere->center.y, sphere->center.z);
	// printf(BGRN"sp raduis == [%f]\n"RESET, sphere->radius);
	// printf(BMAG"sp color == [%d], [%d], [%d]\n"RESET, (sphere->color & (255 << 16)) >> 16, (sphere->color & (255 << 8)) >> 8, sphere->color & 255);
	// printf("---------------------------------------\n");

	erase_split(split);
}

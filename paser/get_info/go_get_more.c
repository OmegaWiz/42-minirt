/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_get_more.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 04:36:47 by psaeyang          #+#    #+#             */
/*   Updated: 2023/07/27 10:45:50 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../paser.h"

void	go_get_cy(char **chop, t_vars *paser)
{
	t_cylinder	*cy;
	t_obj		*obj;
	char		**split;

	obj = malloc(sizeof(t_obj));
	cy = malloc(sizeof(t_cylinder));
	split = ft_split(chop[1], ',');
	get_point(split, &cy->center);
	split = ft_split(chop[2], ',');
	get_vec3(split, &cy->normal);
	get_decimal(chop[3], &cy->radius);
	get_decimal(chop[4], &cy->height);
	split = ft_split(chop[5], ',');
	get_color(split, &cy->color);
	obj->type = CYLINDER;
	obj->obj = cy;
	ft_lstadd_back(&paser->obj_list, ft_lstnew(obj));
	
	t_list *lst;
	lst = paser->obj_list;
	printf(BCYN"cy center == [%f], [%f], [%f]\n"RESET, cy->center.x, cy->center.y, cy->center.z);
	printf(BGRN"cy normal == [%f], [%f], [%f]\n"RESET, cy->normal.x, cy->normal.y, cy->normal.z);
	printf(BMAG"cy color == [%d], [%d], [%d]\n"RESET, cy->color.x, cy->color.y, cy->color.z);
	printf(BYEL"cy raduis height == [%f], [%f]\n"RESET, cy->radius, cy->height);
	
	erase_split(split);
}

void	go_get_pl(char **chop, t_vars *paser)
{
	t_plane	*plane;
	t_obj		*obj;
	char	**split;

	obj = malloc(sizeof(t_obj));
	plane = malloc(sizeof(t_plane));
	split = ft_split(chop[1], ',');
	get_point(split, &plane->center);
	split = ft_split(chop[2], ',');
	get_vec3(split, &plane->normal);
	split = ft_split(chop[3], ',');
	get_color(split, &plane->color);
	obj->type = PLANE;
	obj->obj = plane;
	ft_lstadd_back(&paser->obj_list, ft_lstnew(obj));
	
	t_list *lst;
	lst = paser->obj_list;
	printf(BCYN"pl center == [%f], [%f], [%f]\n"RESET, plane->center.x, plane->center.y, plane->center.z);
	printf(BGRN"pl normal == [%f], [%f], [%f]\n"RESET, plane->normal.x, plane->normal.y, plane->normal.z);
	printf(BMAG"pl color == [%d], [%d], [%d]\n"RESET, plane->color.x, plane->color.y, plane->color.z);
	printf("---------------------------------------\n");
	
	erase_split(split);
}

void	go_get_sp(char **chop, t_vars *paser)
{
	t_sphere	*sphere;
	t_obj		*obj;
	char		**split;

	obj = malloc(sizeof(t_obj));
	sphere = malloc(sizeof(t_sphere));
	split = ft_split(chop[1], ',');
	get_point(split, &sphere->center);
	get_decimal(chop[2], &sphere->radius);
	split = ft_split(chop[3], ',');
	get_color(split, &sphere->color);
	obj->type = SPHERE;
	obj->obj = sphere;
	printf("here sp\n");
	ft_lstadd_back(&paser->obj_list, ft_lstnew(obj));
	
	t_list *lst;
	lst = paser->obj_list;
	printf(BCYN"sp x == [%f], sp y == [%f], sp z == [%f]\n"RESET, sphere->center.x, sphere->center.y, sphere->center.z);
	printf(BGRN"sp raduis == [%f]\n"RESET, sphere->radius);
	printf(BMAG"sp color == [%d], [%d], [%d]\n"RESET, sphere->color.x, sphere->color.y, sphere->color.z);
	printf("---------------------------------------\n");
	
	erase_split(split);
}

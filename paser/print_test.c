/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 04:56:49 by psaeyang          #+#    #+#             */
/*   Updated: 2023/07/27 10:07:02 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "paser.h"

void	print_ambi(t_vars *paser)
{
	printf(BBLU"paser->ambient.ratio == %f\n"RESET, paser->ambient.ratio);
	printf(BRED"paser->ambient.color.x == %d\n"RESET, paser->ambient.color.x);
	printf(BRED"paser->ambient.color.y == %d\n"RESET, paser->ambient.color.y);
	printf(BRED"paser->ambient.color.z == %d\n"RESET, paser->ambient.color.z);
	printf("========================================\n");
}

void	print_camera(t_vars *paser)
{
	printf(BYEL"paser->camera.origin.x == %f\n"RESET, paser->camera.origin.x);
	printf(BYEL"paser->camera.origin.y == %f\n"RESET, paser->camera.origin.y);
	printf(BYEL"paser->camera.origin.z == %f\n"RESET, paser->camera.origin.z);
	printf(BMAG"paser->camera.direction.x == %f\n"RESET, paser->camera.direction.x);
	printf(BMAG"paser->camera.direction.y == %f\n"RESET, paser->camera.direction.y);
	printf(BMAG"paser->camera.direction.z == %f\n"RESET, paser->camera.direction.z);
	printf(BCYN"paser->camera.fov == %f\n"RESET, paser->camera.fov);
	printf("========================================\n");
}

void	print_light(t_vars *paser)
{
	printf(BGRN"paser->light.origin.x == %f\n"RESET, paser->light.origin.x);
	printf(BGRN"paser->light.origin.y == %f\n"RESET, paser->light.origin.y);
	printf(BGRN"paser->light.origin.z == %f\n"RESET, paser->light.origin.z);
	printf(BBLU"paser->light.brightness == %f\n"RESET, paser->light.brightness);
	printf("========================================\n");
}

// void	print_sp(t_vars *paser)
// {
// 	printf(BRED"paser->sp->center.x == %f\n"RESET, paser->sp->center.x);
// 	printf(BRED"paser->sp->center y == %f\n"RESET, paser->sp->center.y);
// 	printf(BRED"paser->sp->center z == %f\n"RESET, paser->sp->center.z);
// 	printf(BYEL"paser->sp->radius == %f\n"RESET, paser->sp->radius);
// 	printf(BMAG"paser->sp->color.x == %d\n"RESET, paser->sp->color.x);
// 	printf(BMAG"paser->sp->color.y == %d\n"RESET, paser->sp->color.y);
// 	printf(BMAG"paser->sp->color.z == %d\n"RESET, paser->sp->color.z);
// 	printf("========================================\n");
	
// }

// void	print_pl(t_vars *paser)
// {
// 	printf(BCYN"paser->pl->center.x == %f\n"RESET, paser->pl->center.x);
// 	printf(BCYN"paser->pl->center y == %f\n"RESET, paser->pl->center.y);
// 	printf(BCYN"paser->pl->center z == %f\n"RESET, paser->pl->center.z);
// 	printf(BGRN"paser->pl->normal.x == %f\n"RESET, paser->pl->normal.x);
// 	printf(BGRN"paser->pl->normal.y == %f\n"RESET, paser->pl->normal.y);
// 	printf(BGRN"paser->pl->normal.z == %f\n"RESET, paser->pl->normal.z);
// 	printf(BBLU"paser->pl->color.x == %d\n"RESET, paser->pl->color.x);
// 	printf(BBLU"paser->pl->color.y == %d\n"RESET, paser->pl->color.y);
// 	printf(BBLU"paser->pl->color.z == %d\n"RESET, paser->pl->color.z);
// 	printf("========================================\n");
// }

// void	print_cy(t_vars *paser)
// {
// 	printf(BRED"paser->cy->center.x == %f\n"RESET, paser->cy->center.x);
// 	printf(BRED"paser->cy->center y == %f\n"RESET, paser->cy->center.y);
// 	printf(BRED"paser->cy->center z == %f\n"RESET, paser->cy->center.z);
// 	printf(BYEL"paser->cy->normal.x == %f\n"RESET, paser->cy->normal.x);
// 	printf(BYEL"paser->cy->normal.y == %f\n"RESET, paser->cy->normal.y);
// 	printf(BYEL"paser->cy->normal.z == %f\n"RESET, paser->cy->normal.z);
// 	printf(BMAG"paser->cy->radius == %f\n"RESET, paser->cy->radius);
// 	printf(BCYN"paser->cy->height == %f\n"RESET, paser->cy->height);
// 	printf(BBLU"paser->cy->color.x == %d\n"RESET, paser->cy->color.x);
// 	printf(BBLU"paser->cy->color.y == %d\n"RESET, paser->cy->color.y);
// 	printf(BBLU"paser->cy->color.z == %d\n"RESET, paser->cy->color.z);
// 	printf("========================================\n");
	
// }
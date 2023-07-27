/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 04:56:49 by psaeyang          #+#    #+#             */
/*   Updated: 2023/07/27 15:43:32 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_ambi(t_vars *parser)
{
	printf(BBLU"parser->ambient.brightness == %f\n"RESET, parser->ambient.brightness);
	printf(BRED"parser->ambient.color = %d, %d, %d\n"RESET, parser->ambient.color >> 16, parser->ambient.color >> 8, parser->ambient.color);
	printf("========================================\n");
}

void	print_camera(t_vars *parser)
{
	printf(BYEL"parser->camera.origin.x == %f\n"RESET, parser->camera.origin.x);
	printf(BYEL"parser->camera.origin.y == %f\n"RESET, parser->camera.origin.y);
	printf(BYEL"parser->camera.origin.z == %f\n"RESET, parser->camera.origin.z);
	printf(BMAG"parser->camera.direction.x == %f\n"RESET, parser->camera.direction.x);
	printf(BMAG"parser->camera.direction.y == %f\n"RESET, parser->camera.direction.y);
	printf(BMAG"parser->camera.direction.z == %f\n"RESET, parser->camera.direction.z);
	printf(BCYN"parser->camera.fov == %f\n"RESET, parser->camera.fov);
	printf("========================================\n");
}

void	print_light(t_vars *parser)
{
	printf(BGRN"parser->light.origin.x == %f\n"RESET, parser->light.origin.x);
	printf(BGRN"parser->light.origin.y == %f\n"RESET, parser->light.origin.y);
	printf(BGRN"parser->light.origin.z == %f\n"RESET, parser->light.origin.z);
	printf(BBLU"parser->light.brightness == %f\n"RESET, parser->light.brightness);
	printf("========================================\n");
}

// void	print_sp(t_vars *parser)
// {
// 	printf(BRED"parser->sp->center.x == %f\n"RESET, parser->sp->center.x);
// 	printf(BRED"parser->sp->center y == %f\n"RESET, parser->sp->center.y);
// 	printf(BRED"parser->sp->center z == %f\n"RESET, parser->sp->center.z);
// 	printf(BYEL"parser->sp->radius == %f\n"RESET, parser->sp->radius);
// 	printf(BMAG"parser->sp->color.x == %d\n"RESET, parser->sp->color.x);
// 	printf(BMAG"parser->sp->color.y == %d\n"RESET, parser->sp->color.y);
// 	printf(BMAG"parser->sp->color.z == %d\n"RESET, parser->sp->color.z);
// 	printf("========================================\n");

// }

// void	print_pl(t_vars *parser)
// {
// 	printf(BCYN"parser->pl->center.x == %f\n"RESET, parser->pl->center.x);
// 	printf(BCYN"parser->pl->center y == %f\n"RESET, parser->pl->center.y);
// 	printf(BCYN"parser->pl->center z == %f\n"RESET, parser->pl->center.z);
// 	printf(BGRN"parser->pl->normal.x == %f\n"RESET, parser->pl->normal.x);
// 	printf(BGRN"parser->pl->normal.y == %f\n"RESET, parser->pl->normal.y);
// 	printf(BGRN"parser->pl->normal.z == %f\n"RESET, parser->pl->normal.z);
// 	printf(BBLU"parser->pl->color.x == %d\n"RESET, parser->pl->color.x);
// 	printf(BBLU"parser->pl->color.y == %d\n"RESET, parser->pl->color.y);
// 	printf(BBLU"parser->pl->color.z == %d\n"RESET, parser->pl->color.z);
// 	printf("========================================\n");
// }

// void	print_cy(t_vars *parser)
// {
// 	printf(BRED"parser->cy->center.x == %f\n"RESET, parser->cy->center.x);
// 	printf(BRED"parser->cy->center y == %f\n"RESET, parser->cy->center.y);
// 	printf(BRED"parser->cy->center z == %f\n"RESET, parser->cy->center.z);
// 	printf(BYEL"parser->cy->direction.x == %f\n"RESET, parser->cy->direction.x);
// 	printf(BYEL"parser->cy->direction.y == %f\n"RESET, parser->cy->direction.y);
// 	printf(BYEL"parser->cy->direction.z == %f\n"RESET, parser->cy->direction.z);
// 	printf(BMAG"parser->cy->radius == %f\n"RESET, parser->cy->radius);
// 	printf(BCYN"parser->cy->height == %f\n"RESET, parser->cy->height);
// 	printf(BBLU"parser->cy->color.x == %d\n"RESET, parser->cy->color.x);
// 	printf(BBLU"parser->cy->color.y == %d\n"RESET, parser->cy->color.y);
// 	printf(BBLU"parser->cy->color.z == %d\n"RESET, parser->cy->color.z);
// 	printf("========================================\n");

// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 04:56:49 by psaeyang          #+#    #+#             */
/*   Updated: 2023/08/01 04:40:23 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_ambi(t_vars *parser)
{
	printf(BBLU"parser->ambient.brightness == %f\n"RESET, \
	parser->ambient.brightness);
	printf(BRED"parser->ambient.color = %d, %d, %d\n"RESET, \
	parser->ambient.color >> 16, parser->ambient.color >> 8, \
	parser->ambient.color);
	printf("========================================\n");
}

void	print_camera(t_vars *parser)
{
	printf(BYEL"parser->camera.origin.x == %f\n"RESET, parser->camera.origin.x);
	printf(BYEL"parser->camera.origin.y == %f\n"RESET, parser->camera.origin.y);
	printf(BYEL"parser->camera.origin.z == %f\n"RESET, parser->camera.origin.z);
	printf(BMAG"parser->camera.direction.x == %f\n"RESET, \
	parser->camera.direction.x);
	printf(BMAG"parser->camera.direction.y == %f\n"RESET, \
	parser->camera.direction.y);
	printf(BMAG"parser->camera.direction.z == %f\n"RESET, \
	parser->camera.direction.z);
	printf(BCYN"parser->camera.fov == %f\n"RESET, parser->camera.fov);
	printf("========================================\n");
}

void	print_light(t_vars *parser)
{
	printf(BGRN"parser->light.origin.x == %f\n"RESET, parser->light.origin.x);
	printf(BGRN"parser->light.origin.y == %f\n"RESET, parser->light.origin.y);
	printf(BGRN"parser->light.origin.z == %f\n"RESET, parser->light.origin.z);
	printf(BBLU"parser->light.brightness == %f\n"RESET, \
	parser->light.brightness);
	printf("========================================\n");
}

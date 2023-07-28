/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_getinfo_go_get.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:56:46 by psaeyang          #+#    #+#             */
/*   Updated: 2023/07/28 03:54:28 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	go_get_l(char **chop, t_vars *parser)
{
	t_light	*light;
	char	**split;

	light = malloc(sizeof(t_light));
	split = ft_split(chop[1], ',');
	get_point(split, &light->origin);
	get_decimal(chop[2], &light->brightness);
	erase_split(split);
	parser->light = *light;
	parser->light.color = color2int(255, 255, 255);
	printf(BCYN"light origin:{%f, %f, %f} brightness:%f\n"RESET, parser->light.origin.x, parser->light.origin.y, parser->light.origin.z, parser->light.brightness);
}

void	go_get_c(char **chop, t_vars *parser)
{
	t_camera	*camera;
	char		**split;

	camera = malloc(sizeof(t_camera));
	split = ft_split(chop[1], ',');
	get_point(split, &camera->origin);
	erase_split(split);
	split = ft_split(chop[2], ',');
	get_vec3(split, &camera->direction);
	get_decimal(chop[3], &camera->fov);
	erase_split(split);
	parser->camera = *camera;
	printf(BCYN"camera origin:{%f, %f, %f} direction:{%f, %f, %f} fov:%f\n"RESET, parser->camera.origin.x, parser->camera.origin.y, parser->camera.origin.z, parser->camera.direction.x, parser->camera.direction.y, parser->camera.direction.z, parser->camera.fov);
}

void	go_get_a(char **chop, t_vars *parser)
{
	t_ambient	*ambi = NULL;
	char		**split;

	ambi = malloc(sizeof(t_ambient));
	split = ft_split(chop[2], ',');
	get_decimal(chop[1], &ambi->brightness);
	get_color(split, &ambi->color);
	erase_split(split);
	parser->ambient = *ambi;
	printf(BCYN"ambi color:{%d, %d, %d}, brightness:%f\n"RESET, (parser->ambient.color & (255 << 16)) >> 16, (parser->ambient.color & (255 << 8)) >> 8, parser->ambient.color & 255, parser->ambient.brightness);
}

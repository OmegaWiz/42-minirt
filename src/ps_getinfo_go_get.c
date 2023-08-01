/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_getinfo_go_get.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:56:46 by psaeyang          #+#    #+#             */
/*   Updated: 2023/08/01 13:21:01 by psaeyang         ###   ########.fr       */
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
}

void	go_get_a(char **chop, t_vars *parser)
{
	char		**split;
	t_ambient	*ambi;

	ambi = malloc(sizeof(t_ambient));
	split = ft_split(chop[2], ',');
	get_decimal(chop[1], &ambi->brightness);
	get_color(split, &ambi->color);
	erase_split(split);
	parser->ambient = *ambi;
}

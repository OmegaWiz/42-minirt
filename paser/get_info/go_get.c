/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:56:46 by psaeyang          #+#    #+#             */
/*   Updated: 2023/07/27 10:35:19 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../paser.h"

void	go_get_l(char **chop, t_vars *paser)
{
	t_light	*light;
	char	**split;

	light = malloc(sizeof(t_light));
	split = ft_split(chop[1], ',');
	get_point(split, &light->origin);
	get_decimal(chop[2], &light->brightness);
	erase_split(split);
	paser->light = *light;
}

void	go_get_c(char **chop, t_vars *paser)
{
	t_camera	*camera;
	char		**split;

	camera = malloc(sizeof(t_camera));
	split = ft_split(chop[1], ',');
	get_point(split, &camera->origin);
	split = ft_split(chop[2], ',');
	get_vec3(split, &camera->direction);
	get_decimal(chop[3], &camera->fov);
	erase_split(split);
	paser->camera = *camera;
}

void	go_get_a(char **chop, t_vars *paser)
{
	t_ambient	*ambi = NULL;
	char		**split;

	ambi = malloc(sizeof(t_ambient));
	split = ft_split(chop[2], ',');
	get_decimal(chop[1], &ambi->ratio);
	get_color(split, &ambi->color);
	erase_split(split);
	paser->ambient = *ambi;
}

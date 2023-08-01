/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_getinfo_get_info.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:21:59 by psaeyang          #+#    #+#             */
/*   Updated: 2023/08/01 16:21:27 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_line(char *line, t_vars *parser)
{
	char	**chop;

	chop = split_blank(line);
	if (chop == NULL)
		return ;
	if (chop[0] == NULL)
	{
		erase_split(chop);
		return ;
	}
	if (ft_strncmp(chop[0], "A", 2) == 0)
		go_get_a(chop, parser);
	else if (ft_strncmp(chop[0], "C", 2) == 0)
		go_get_c(chop, parser);
	else if (ft_strncmp(chop[0], "L", 2) == 0)
		go_get_l(chop, parser);
	else if (ft_strncmp(chop[0], "sp", 3) == 0)
		go_get_sp(chop, parser);
	else if (ft_strncmp(chop[0], "pl", 3) == 0)
		go_get_pl(chop, parser);
	else if (ft_strncmp(chop[0], "cy", 3) == 0)
		go_get_cy(chop, parser);
	else if (ft_strncmp(chop[0], "co", 3) == 0)
		go_get_co(chop, parser);
	erase_split(chop);
}

void	get_info(t_vars *parser, char *av)
{
	int			fd;
	char		*line;

	fd = open(av, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL )
	{
		get_line(line, parser);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

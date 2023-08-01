/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_getinfo_get_info.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:21:59 by psaeyang          #+#    #+#             */
/*   Updated: 2023/08/01 15:51:05 by kkaiyawo         ###   ########.fr       */
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
	if (chop[0][0] == 'A')
		go_get_a(chop, parser);
	else if (chop[0][0] == 'C')
		go_get_c(chop, parser);
	else if (chop[0][0] == 'L')
		go_get_l(chop, parser);
	else if (chop[0][0] == 's' && chop[0][1] == 'p')
		go_get_sp(chop, parser);
	else if (chop[0][0] == 'p' && chop[0][1] == 'l')
		go_get_pl(chop, parser);
	else if (chop[0][0] == 'c' && chop[0][1] == 'y')
		go_get_cy(chop, parser);
	else if (chop[0][0] == 'c' && chop[0][1] == 'o')
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_getinfo_get_info.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:21:59 by psaeyang          #+#    #+#             */
/*   Updated: 2023/07/27 15:55:45 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_line(char *line, t_vars *parser)
{
	char	**chop;

	printf("\ninfo: %s", line);
	chop = split_blank(line);
	if (chop == NULL)
		return ;
	if (chop[0] == NULL)
			erase_split(chop);
	if (chop[0] == NULL)
			return ;
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
	erase_split(chop);
}

void	get_info(t_vars *parser, char *av)
{
	int			fd;
	// int			i;
	char		*line;
	// static int	cnt;

	// i = 0;
	fd = open(av, O_RDONLY);
	line = get_next_line(fd);
	// cnt = ft_splitcntt(line);
	while (line != NULL )//&& i < cnt)
	{
		get_line(line, parser);
		free(line);
		// i++;
		line = get_next_line(fd);
		// cnt = ft_splitcntt(line);
		// i = 0;
	}
		free(line);
}

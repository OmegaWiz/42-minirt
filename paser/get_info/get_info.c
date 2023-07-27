/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:21:59 by psaeyang          #+#    #+#             */
/*   Updated: 2023/07/27 10:44:14 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../paser.h"

void	get_line(char *line, t_vars *paser)
{
	char	**chop;
	chop = split_blank(line);
	if (chop[0][0] == 'A')
		go_get_a(chop, paser);
	else if (chop[0][0] == 'C')
		go_get_c(chop, paser);
	else if (chop[0][0] == 'L')
		go_get_l(chop, paser);
	else if (chop[0][0] == 's' && chop[0][1] == 'p')
		go_get_sp(chop, paser);
	else if (chop[0][0] == 'p' && chop[0][1] == 'l')
		go_get_pl(chop, paser);
	else if (chop[0][0] == 'c' && chop[0][1] == 'y')
		go_get_cy(chop, paser);
	erase_split(chop);
}

void	get_info(t_vars *paser, char *av)
{
	int			fd;
	int			i;
	char		*line;
	static int	cnt;

	i = 0;
	fd = open(av, O_RDONLY);
	line = get_next_line(fd);
	cnt = ft_splitcntt(line);
	while (line != NULL && i < cnt)
	{
		get_line(line, paser);
		free(line);
		i++;
		line = get_next_line(fd);
		cnt = ft_splitcntt(line);
		i = 0;
	}
	free(line);
}

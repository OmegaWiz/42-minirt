/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:13:19 by psaeyang          #+#    #+#             */
/*   Updated: 2023/07/17 01:26:38 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../paser.h"

void	verify_len(char **line, int len)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	if (i != len)
		error(BYEL"--len not correct--"RESET, 0);
	printf(BMAG"--len correct--\n"RESET);
}

void	verify_line(char *line)
{
	char	**chopchop;

	chopchop = split_blank(line);
	if (chopchop[0][0] == 'A')
		verify_a(chopchop);
	else if (chopchop[0][0] == 'C')
		verify_c(chopchop);
	else if (chopchop[0][0] == 'L')
		verify_l(chopchop);
	else if (chopchop[0][0] == 's' && chopchop[0][1] == 'p')
		verify_sp(chopchop);
	else if (chopchop[0][0] == 'p' && chopchop[0][1] == 'l')
		verify_pl(chopchop);
	else if (chopchop[0][0] == 'c' && chopchop[0][1] == 'y')
		verify_cy(chopchop);
	else
		error(BRED"info wrong"RESET, 0);
}

void	goinfile(int fd)
 {
	int 		i;
	char		*gotline;
	static int	cnt;

	i = 0;
	gotline = get_next_line(fd);
	if (gotline == NULL)
		error(BRED"cannot get_line"RESET, 0);
	cnt = ft_splitcntt(gotline);
	while (gotline && i < cnt)
	{
		// printf(BMAG"this is len gotline [%d]\n"RESET, cnt);
		// if (gotline[0] == 0)
		// 	error(BRED"line wrong"RESET,0);
		// else
		// {
			verify_line(gotline);
			i++;
			gotline = get_next_line(fd);
			cnt = ft_splitcntt(gotline);
			i = 0;
			// break ;
		// }
	}

 }

void	verify_file(char **av)
{
	int		fd;
	char	*rt;

	rt = ft_strrchr(av[1], '.');
	if (!(rt && ft_strncmp(ft_strrchr(av[1], '.'), ".rt", 4) == 0))
		error(BRED"file not correct Σ(￣ロ￣lll)"RESET, 0);
	else
	{
		printf(BBLU"file .rt correct (─‿‿─)\n"RESET);
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
			error(BRED"cannot open file Σ(￣ロ￣lll)"RESET, 0);
		goinfile(fd);
		close(fd);
	}
}

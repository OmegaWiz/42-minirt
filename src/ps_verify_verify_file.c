/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_verify_verify_file.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:13:19 by psaeyang          #+#    #+#             */
/*   Updated: 2023/07/28 03:14:53 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	verify_len(char **line, int len)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (i_c_comment(line[i]) == 1)
			break ;
		i++;
	}
	if (i != len)
		free_error(BYEL"--len not correct--"RESET, line);
	// printf(BMAG"--len correct--\n"RESET);
}

void	verify_line(char *line)
{
	char	**chopchop;

	chopchop = split_blank(line);
	if (chopchop[0] == NULL)
	{
		free(chopchop);
		return ;
	}
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
		error(BRED"info wrong"RESET);
	erase_split(chopchop);
}

void	cnt_ambi_camera(char *line, int *cnt_a, int *cnt_c)
{
	if (line[0] == 'A')
		*cnt_a += 1;
	else if (line[0] == 'C')
		*cnt_c += 1;
	else
		return ;
}

void	goinfile(int fd)
{
	int			i;
	int			cnt_a;
	int			cnt_c;
	char		*gotline;

	i = 0;
	cnt_a = 0;
	cnt_c = 0;
	gotline = get_next_line(fd);
	if (gotline == NULL)
		error(BRED"cannot get_line"RESET);
	while (gotline)
	{
		if (gotline[0] != '#')
			verify_line(gotline);
		i++;
		cnt_ambi_camera(gotline, &cnt_a, &cnt_c);
		free(gotline);
		gotline = get_next_line(fd);
		i = 0;
	}
	if (!(cnt_a == 1 || cnt_a == 0))
		error(BRED"ambi should be 0 or 1"RESET);
	else if (cnt_c != 1)
		error(BRED"camera only 1"RESET);
}

void	verify_file(char **av)
{
	int		fd;
	char	*rt;

	rt = ft_strrchr(av[1], '.');
	if (!(rt && ft_strncmp(ft_strrchr(av[1], '.'), ".rt", 4) == 0))
		error(BRED"file not correct Σ(￣ロ￣lll)"RESET);
	else
	{
		printf(BBLU"file .rt correct (─‿‿─)\n"RESET);
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
			error(BRED"cannot open file Σ(￣ロ￣lll)"RESET);
		goinfile(fd);
		close(fd);
	}
} 

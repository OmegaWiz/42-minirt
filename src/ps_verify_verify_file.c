/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_verify_verify_file.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:13:19 by psaeyang          #+#    #+#             */
/*   Updated: 2023/08/01 14:59:58 by psaeyang         ###   ########.fr       */
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
	if (ft_strncmp(chopchop[0], "A", 2) == 0)
		verify_a(chopchop);
	else if (ft_strncmp(chopchop[0], "C", 2) == 0)
		verify_c(chopchop);
	else if (ft_strncmp(chopchop[0], "L", 2) == 0)
		verify_l(chopchop);
	else if (ft_strncmp(chopchop[0], "sp", 3) == 0)
		verify_sp(chopchop);
	else if (ft_strncmp(chopchop[0], "pl", 3) == 0)
		verify_pl(chopchop);
	else if (ft_strncmp(chopchop[0], "cy", 3) == 0)
		verify_cy(chopchop);
	else if (ft_strncmp(chopchop[0], "co", 3) == 0)
		verify_cy(chopchop);
	else
		error(BRED"invalid identifier"RESET);
	erase_split(chopchop);
}

void	cnt_ambi_camera(char *line, int *cnt_a, int *cnt_c, int *cnt_l)
{
	if (line[0] == 'A')
		*cnt_a += 1;
	else if (line[0] == 'C')
		*cnt_c += 1;
	else if (line[0] == 'L')
		*cnt_l += 1;
	else
		return ;
}

void	goinfile(int fd)
{
	int			i;
	int			cnt_a;
	int			cnt_c;
	int			cnt_l;
	char		*gotline;

	i = 0;
	cnt_a = 0;
	cnt_c = 0;
	cnt_l = 0;
	gotline = get_next_line(fd);
	if (gotline == NULL)
		error(BRED"empty file"RESET);
	while (gotline)
	{
		if (gotline[0] != '#')
			verify_line(gotline);
		i++;
		cnt_ambi_camera(gotline, &cnt_a, &cnt_c, &cnt_l);
		free(gotline);
		gotline = get_next_line(fd);
		i = 0;
	}
	error_a_c_l(cnt_a, cnt_c, cnt_l);
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
		printf(BBLU"valid file name (─‿‿─)\n"RESET);
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
			error(BRED"cannot open file Σ(￣ロ￣lll)"RESET);
		goinfile(fd);
		close(fd);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:08:48 by psaeyang          #+#    #+#             */
/*   Updated: 2023/08/01 14:15:48 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	error_a_c_l(int cnt_a, int cnt_c, int cnt_l)
{
	if (!(cnt_a == 1 || cnt_a == 0))
		error(BRED"invalid number of ambience"RESET);
	else if (cnt_c != 1)
		error(BRED"invalid number of camera"RESET);
	else if (cnt_l != 1)
		error(BRED"invalid number of light"RESET);
	else
		return ;
}

void	erase_split(char **av)
{
	int	i;

	i = 0;
	if (av == NULL)
		return ;
	while (av[i] != NULL)
	{
		free(av[i]);
		i++;
	}
	free(av);
}

void	free_error(char *s, char **free)
{
	erase_split(free);
	error(s);
}

void	error(char *s)
{
	ft_putendl_fd(BRED"Error"RESET, 2);
	ft_putendl_fd(s, 2);
	ft_putchar_fd('\n', 2);
	ft_putendl_fd(BBLU"Usage:", 2);
	ft_putendl_fd("./miniRT [file].rt"RESET, 2);
	ft_putendl_fd(BGRN"[file].rt format:", 2);
	ft_putendl_fd("{identifier} {parameter(s)} {line break}"RESET, 2);
	ft_putendl_fd(BCYN"identifier:", 2);
	ft_putendl_fd("A {ratio} {R,G,B}", 2);
	ft_putendl_fd("C {origin} {normal} {FOV}", 2);
	ft_putendl_fd("L {origin} {ratio}", 2);
	ft_putendl_fd("sp {origin} {diameter} {R,G,B}", 2);
	ft_putendl_fd("pl {origin} {normal} {R,G,B}", 2);
	ft_putendl_fd("cy {origin} {normal} {diameter} {height} {R,G,B}", 2);
	ft_putendl_fd("co {origin} {normal} {diameter} {height} {R,G,B}"RESET, 2);
	exit(1);
}

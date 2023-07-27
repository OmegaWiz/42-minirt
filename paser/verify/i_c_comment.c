/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_c_comment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:32:53 by psaeyang          #+#    #+#             */
/*   Updated: 2023/07/24 23:08:52 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../paser.h"

int	empty_line(char *line)
{
	if (line[0] == '\n')
		return (1);
	return (0);
}

int	i_c_comment(char *line)
{
	if (ft_strchr(line, '#') != NULL)
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_verify_i_c_comment.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:32:53 by psaeyang          #+#    #+#             */
/*   Updated: 2023/07/27 14:08:51 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

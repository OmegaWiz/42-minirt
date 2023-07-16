/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 01:36:09 by psaeyang          #+#    #+#             */
/*   Updated: 2023/07/17 01:27:20 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../paser.h"

int	str_is_digit(char **str)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (str[++i])
	{
		j = 0;
		// while (ft_isspace(str[i][j]))
		// 	j++;
		if (str[i][j] == '-' || str[i][j] == '+')
			j++;
		while (ft_isdigit(str[i][j]))
			j++;
		if (str[i][j] == '.')
			j++;
		while (ft_isdigit(str[i][j]))
			j++;
		if (ft_strlen(str[i]) != j)
			return (0);
	}
	return (1);
}
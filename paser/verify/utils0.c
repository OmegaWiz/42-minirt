/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 01:36:09 by psaeyang          #+#    #+#             */
/*   Updated: 2023/07/24 02:40:56 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../paser.h"

int	twod_is_decimal(char **str)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (str[++i])
	{
		j = 0;
		if (str[i][j] == '-' || str[i][j] == '+')
			j++;
		while (ft_isdigit(str[i][j]))
			j++;
		if (str[i][j] == '.')
			j++;
		while (ft_isdigit(str[i][j]))
			j++;
		if (ft_strlen(str[i]) != j || str[i][0] == '.')
			return (0);
	}
	return (1);
}

int	str_is_decimal(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == '.')
	{
		i++;
		if (!ft_isdigit(str[i]))
			return (0);
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]) || str[0] == '.')
			return (0);
		i++;
	}
	return (1);
}

int	twod_is_digit(char **str)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (str[++i])
	{
		j = 0;
		if (str[i][j] == '-' || str[i][j] == '+')
			j++;
		while (ft_isdigit(str[i][j]))
			j++;
		while (ft_isdigit(str[i][j]))
			j++;
		if (ft_strlen(str[i]) != j)
			return (0);
	}
	return (1);
}

int	str_is_digit(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_verify_utils0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 01:36:09 by psaeyang          #+#    #+#             */
/*   Updated: 2023/08/01 18:03:32 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
		if ((!ft_isdigit(str[i]) || str[0] == '.') && str[i] != '\n')
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
		if (str[i][j] == '\n')
			j++;
		if (ft_strlen(str[i]) != j)
		{
			return (0);
		}
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

int	tuple_cnt(char *str, char c, int expect)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] == c)
			cnt++;
		i++;
	}
	if (cnt != expect)
		error("Invalid tuple");
	return (1);
}

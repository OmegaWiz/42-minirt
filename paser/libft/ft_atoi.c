/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:51:48 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/07/15 21:09:03 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isblank(char c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	if (c == '\n')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	size_t		neg;
	long long	num;
	size_t		i;

	neg = 0;
	num = 0;
	i = 0;
	while (ft_isblank(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			neg++;
		i++;
	}
	while ('0' <= nptr[i] && nptr[i] <= '9')
		num = (num * 10) + (nptr[i++] - '0');
	if (neg % 2)
		num *= -1;
	return (num);
}

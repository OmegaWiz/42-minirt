/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:30:41 by psaeyang          #+#    #+#             */
/*   Updated: 2023/07/24 05:10:12 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	decimal(const char *str, double ans)
{
	double	dot;

	dot = 0.1;
	while (*str && *str >= '0' && *str <= '9')
	{
		ans += (dot * (*str - '0'));
		dot /= 10;
		str++;
	}
	return (ans);
}

double	ft_atof(const char *str)
{
	double	ans;
	double	neg;

	ans = 0;
	neg = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		ans = ans * 10 + (*str - '0');
		str++;
	}
	if (*str++ == '.')
		ans = decimal(str, ans);
	return (ans * neg);
}

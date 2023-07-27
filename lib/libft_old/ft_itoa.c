/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:12:00 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/02/17 16:35:27 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isize(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		if (n == -2147483648)
			return (11);
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ft_isize(n);
	str = malloc((i + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[i--] = 0;
	while (ft_abs(n) > 9)
	{
		str[i--] = (ft_abs(n) % 10) + '0';
		n /= 10;
	}
	str[i--] = ft_abs(n) + '0';
	if (n < 0)
		str[i] = '-';
	return (str);
}

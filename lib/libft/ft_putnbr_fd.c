/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:55:14 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/02/16 18:13:27 by kkaiyawo         ###   ########.fr       */
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
		{
			return (11);
		}
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

static int	ft_asb(int n)
{
	if (n < 0)
	{
		return (n * -1);
	}
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	str[13];
	int		i;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	i = ft_isize(n);
	str[i--] = 0;
	while (ft_asb(n) > 9)
	{
		str[i--] = (ft_asb(n) % 10) + '0';
		n /= 10;
	}
	str[i--] = ft_asb(n) + '0';
	if (n < 0)
		str[i] = '-';
	write(fd, str, ft_strlen(str));
}

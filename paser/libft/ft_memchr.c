/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:49:07 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/02/15 10:18:49 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	u;

	i = 0;
	u = c;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == u)
		{
			return ((void *)(s + i));
		}
		i++;
	}
	return (NULL);
}

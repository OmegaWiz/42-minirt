/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:45:58 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/02/17 17:26:13 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	c %= 256;
	ptr = NULL;
	i = -1;
	while (s[++i])
	{
		if (s[i] == c)
			ptr = ((char *)(s + i));
	}
	if (c == 0)
		return ((char *)(s + i));
	return (ptr);
}

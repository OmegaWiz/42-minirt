/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:20:15 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/02/16 16:14:38 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != 0 && s2[i] != 0 && i < n)
	{
		if ((unsigned char) s1[i] > (unsigned char) s2[i])
			return ((int)(unsigned char) s1[i] - (unsigned char) s2[i]);
		if ((unsigned char) s1[i] < (unsigned char) s2[i])
			return ((int)(unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	if (i == n)
		i--;
	if ((unsigned char) s1[i] > (unsigned char) s2[i])
		return ((int)(unsigned char) s1[i] - (unsigned char) s2[i]);
	if ((unsigned char) s1[i] < (unsigned char) s2[i])
		return ((int)(unsigned char) s1[i] - (unsigned char) s2[i]);
	return (0);
}

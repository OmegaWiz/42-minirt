/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:17:43 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/07/11 15:30:52 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;
	size_t	i;

	if (nmemb >= __SIZE_MAX__ && size >= __SIZE_MAX__)
		return (NULL);
	s = malloc(nmemb * size);
	if (!s)
		return (NULL);
	i = 0;
	*(char *)(s + i) = 0;
	return (s);
}

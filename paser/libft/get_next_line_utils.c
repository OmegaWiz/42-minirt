/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:22:50 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/04/05 09:46:20 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>
#include <limits.h>

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

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s || s == NULL || s == 0)
		return (0);
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0 && src != NULL)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	if (src)
	{
		while (src[i])
			i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	if (!s1)
		return (NULL);
	str = (char *) ft_calloc(ft_strlen(s1) + 1, 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	c %= 256;
	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == c)
		return ((char *)(s + i));
	return (NULL);
}

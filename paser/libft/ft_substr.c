/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:35:41 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/02/16 11:09:25 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	n;

	if (s == NULL)
		return (NULL);
	n = ft_strlen(s);
	if (start >= n)
	{
		str = malloc(sizeof(char));
		ft_strlcpy(str, "", 1);
		return (str);
	}
	if (len > n - start)
		len = n - start;
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, (s + start), len + 1);
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moonegg <moonegg@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:49:48 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/03/01 09:59:57 by moonegg          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		i;
	int		j;
	int		k;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL || *set == '\0')
		return (ft_strdup(s1));
	i = 0;
	j = 0;
	k = ft_strlen(s1);
	while (ft_strchr(set, s1[j]) && s1[j])
		j++;
	while (ft_strrchr(set, s1[k]) && k >= j)
		k--;
	new = (char *)ft_calloc(k - j + 2, sizeof(char));
	if (new == NULL)
		return (NULL);
	while (j < k + 1)
		new[i++] = s1[j++];
	return (new);
}

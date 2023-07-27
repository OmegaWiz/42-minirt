/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:51:44 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/02/17 17:07:49 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_newsplit(char const *s, int *i, int *j)
{
	char	*tmp;

	tmp = (char *)malloc((*i - *j + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	ft_memcpy(tmp, s + *j, (*i - *j) * sizeof(char));
	tmp[*i - *j] = 0;
	*j = *i + 1;
	return (tmp);
}

static int	ft_splitcnt(char const *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (++i <= (int) ft_strlen(s))
	{
		while (s[j] == c && s[j])
			j++;
		if (((s[i] == c || !s[i]) && s[i - 1] != c) && i - j > 0)
		{
			k++;
			j = i + 1;
		}
	}
	return (k);
}

static void	ft_zero(int *i, int *j, int *k)
{
	*i = 0;
	*j = 0;
	*k = 0;
}

static char	**ft_cleararr(char **arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
		free(arr[i++]);
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		len;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	arr = (char **)malloc((ft_splitcnt(s, c) + 1) * sizeof (char *));
	if (!arr)
		return (NULL);
	ft_zero(&i, &j, &len);
	while (++i <= (int) ft_strlen(s))
	{
		while (s[j] == c && s[j])
			j++;
		if (((s[i] == c || !s[i]) && s[i - 1] != c) && i - j > 0)
		{
			arr[len++] = ft_newsplit(s, &i, &j);
			if (!arr[len - 1])
				return (ft_cleararr(arr, len));
		}
	}
	arr[len] = NULL;
	return (arr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_blank.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:45:08 by psaeyang          #+#    #+#             */
/*   Updated: 2023/08/01 18:27:13 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_newsplitt(char const *s, int *i, int *j)
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

int	ft_splitcntt(char const *s)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (++i <= (int) ft_strlen(s))
	{
		while (s[j] == 32 && s[j])
			j++;
		if (((s[i] == 32 || !s[i]))
			&& (s[i - 1] != 32
				&& i - j > 0))
		{
			k++;
			j = i + 1;
		}
	}
	return (k);
}

static void	ft_zeroo(int *i, int *j, int *k)
{
	*i = 0;
	*j = 0;
	*k = 0;
}

static char	**ft_cleararrr(char **arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
		free(arr[i++]);
	free(arr);
	return (NULL);
}

char	**split_blank(char const *s)
{
	char	**arr;
	int		len;
	int		ij[2];

	if (s == NULL)
		return (NULL);
	arr = (char **)malloc((ft_splitcntt(s) + 1) * sizeof (char *));
	if (!arr)
		return (NULL);
	ft_zeroo(&ij[0], &ij[1], &len);
	while (++ij[0] <= (int) ft_strlen(s))
	{
		while (ft_isspace(s[ij[1]]) && s[ij[1]])
			ij[1]++;
		if ((s[ij[0]] == 32 || !s[ij[0]])
			&& (s[ij[0] - 1] != 32) && ij[0] - ij[1] > 0)
		{
			arr[len++] = ft_newsplitt(s, &ij[0], &ij[1]);
			if (!arr[len - 1])
				return (ft_cleararrr(arr, len));
		}
	}
	arr[len] = NULL;
	return (arr);
}

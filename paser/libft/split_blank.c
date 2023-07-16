/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_blank.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:45:08 by psaeyang          #+#    #+#             */
/*   Updated: 2023/07/16 04:24:07 by psaeyang         ###   ########.fr       */
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
		while ((s[j] == 32 || (s[j] >= 9 && s[j] <= 13)) && s[j])
			j++;
		if ((((s[i] == 32 || (s[i] >= 9 && s[i] <= 13) || !s[i])) &&
		(s[i - 1] != 32 || ((s[i - 1] >= 9 && s[i - 1] <= 13))) && i - j > 0))
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
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	arr = (char **)malloc((ft_splitcntt(s) + 1) * sizeof (char *));
	if (!arr)
		return (NULL);
	ft_zeroo(&i, &j, &len);
	while (++i <= (int) ft_strlen(s))
	{
		while (ft_isspace(s[j]) && s[j])
		// while (s[j] == 32 || ((s[j] >= 9 && s[j] <= 13) && s[j]))
			j++;
		if (((s[i] == 32 || (s[i] >= 9 && s[i] <= 13) || !s[i]) &&
		(s[i - 1] != 32 || (s[i - 1] >= 9 && s[i - 1] <= 13))) && i - j > 0)
		{
			arr[len++] = ft_newsplitt(s, &i, &j);
			if (!arr[len - 1])
				return (ft_cleararrr(arr, len));
		}
	}
	arr[len] = NULL;
	return (arr);
}

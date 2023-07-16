/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 07:48:13 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/02/17 16:35:37 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (*lst != NULL)
	{
		ptr = *lst;
		while (ptr->next != NULL)
			ptr = ptr->next;
		if (ptr != NULL)
		{
			ptr->next = new;
			return ;
		}
	}
	*lst = new;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 08:07:17 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/02/17 18:12:58 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*new;

	ptr = lst;
	new = NULL;
	while (ptr != NULL)
	{
		ft_lstadd_back(&new, ft_lstnew(f(ptr->content)));
		ptr = ptr->next;
	}
	if (ft_lstsize(new) != ft_lstsize(lst))
	{
		ft_lstclear(&new, del);
		return (NULL);
	}
	return (new);
}

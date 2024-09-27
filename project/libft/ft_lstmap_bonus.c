/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayoub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 22:59:04 by tayoub            #+#    #+#             */
/*   Updated: 2024/06/20 23:24:13 by tayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*helper(t_list **result, t_list *itr, t_list *new_node)
{
	if (!(*result))
	{
		*result = new_node;
		return (*result);
	}
	else
	{
		itr->next = new_node;
		return (itr->next);
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list			*result;
	t_list			*itr;
	t_list			*new_node;
	unsigned char	*t;

	result = NULL;
	itr = NULL;
	while (lst)
	{
		t = (unsigned char *)f(lst->content);
		new_node = ft_lstnew((void *)t);
		if (!new_node)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		itr = helper(&result, itr, new_node);
		lst = lst->next;
	}
	return (result);
}

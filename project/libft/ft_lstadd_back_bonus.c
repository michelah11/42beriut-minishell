/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayoub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 22:28:35 by tayoub            #+#    #+#             */
/*   Updated: 2024/06/20 22:35:35 by tayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*nlst;

	if (!new || !lst)
		return ;
	if (!(*lst))
	{
		ft_lstadd_front(lst, new);
		return ;
	}
	nlst = ft_lstlast(*lst);
	nlst->next = new;
}

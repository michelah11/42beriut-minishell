/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkn_add_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:24:06 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/09/27 17:33:16 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tkn_add_back(t_token **tokens, t_token *token)
{
	t_token	*temp;

	temp = *tokens;
	if (!temp)
		(*tokens) = token;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = token;
	}
}
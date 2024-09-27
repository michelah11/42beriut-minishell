/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkn_last.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 08:11:12 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/09/27 08:27:04 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*tkn_last(t_token *token)
{
	t_token	*tkn;

	tkn = token;
	while (token->next)
		tkn = token->next;
	return (tkn);
}

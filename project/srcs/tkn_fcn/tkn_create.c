/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkn_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 07:00:43 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/09/27 08:28:48 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*tkn_create(char *token, int flag)
{
	t_token	*tkn;

	tkn = malloc(sizeof(t_token));
	if (!tkn)
		error(NULL);
	tkn->token = token;
	if (!flag)
		tkn->type = check_token_type(token);
	else
		tkn->type = WORD;
	tkn->next = NULL;
	return (tkn);
}

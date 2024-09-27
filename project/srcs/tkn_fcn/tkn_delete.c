/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkn_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 08:31:00 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/09/27 08:40:55 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tkn_delete(t_parser *parser, char *token_to_find)
{
	t_token	*temp;
	t_token	*last;
	size_t	size;

	temp = parser->tokens;
	last = NULL;
	size = ft_strlen(token_to_find);
	while (temp)
	{
		if (!ft_strncmp(temp->token, token_to_find, size))
		{
			if (!last)
				parser->tokens = temp->next;
			else
				last->next = temp->next;
			free(temp->token);
			free(temp);
		}
		last = temp;
		temp = temp->next;
	}
}

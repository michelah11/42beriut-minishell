/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkn_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 08:41:23 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/09/27 08:49:44 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	tkn_len(t_parser *parser)
{
	size_t	len;

	len = 0;
	while (parser->tokens)
	{
		len++;
		parser->tokens->next;
	}
	return (len);
}

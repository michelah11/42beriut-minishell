/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkn_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 07:18:46 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/09/27 08:27:43 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*tkn_dup(t_token *src)
{
	t_token	*dup;

	dup = malloc(sizeof(t_token));
	if (!dup)
		error(NULL);
	dup->token = ft_strdup(src->token);
	dup->type = src->type;
	dup->next = NULL;
	return (src);
}

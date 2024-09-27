/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:59:20 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/09/27 08:29:25 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENS_H
# define TOKENS_H

# include "minishell.h"

# define SEPARATOR "|><\n"

enum e_tkn_type
{
	WORD,
	ASSIGN_WORD,
	LESS,
	D_LESS,
	GREAT,
	D_GREAT
};

typedef struct s_token
{
	char			*token;
	int				type;
	struct s_token	*next;
}				t_token;

typedef struct s_parser
{
	char	*input;
	t_token	*tokens;
}			t_parser;

#endif
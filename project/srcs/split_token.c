/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 05:00:00 by yourname          #+#    #+#             */
/*   Updated: 2024/09/24 19:29:50 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tokens.h"

int	check_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\v' || c == '\r');
}

int	is_separator(char *str, int i)
{
	char	*charset;
	int		j;

	charset = SEPARATOR;
	j = 0;
	while (charset[j])
	{
		if (str[i] == charset[j])
			return (1);
		j++;
	}
	return (0);
}

int	skip_spaces(char *str, int i)
{
	while (str[i] && check_space(str[i]))
		i++;
	return (i);
}

int	handle_quotes(char *str, int i, char *in_quote, int *handled)
{
	*handled = 0;
	if (str[i] == '\\' && str[i + 1])
	{
		i += 2;
		*handled = 1;
		return (i);
	}
	if (str[i] == '"' || str[i] == '\'')
	{
		if (*in_quote == 0)
			*in_quote = str[i++];
		else if (*in_quote == str[i])
		{
			*in_quote = 0;
			i++;
		}
		else
			i++;
		*handled = 1;
		return (i);
	}
	return (i);
}

int	get_token(char *str, int i, char **token)
{
	int		start;
	char	in_quote;
	int		handled;

	start = i;
	in_quote = 0;
	while (str[i])
	{
		i = handle_quotes(str, i, &in_quote, &handled);
		if (handled)
			continue ;
		if (!in_quote && (check_space(str[i]) || is_separator(str, i)))
			break ;
		i++;
	}
	*token = strndup(&str[start], i - start);
	return (i);
}

int	get_separator(char *str, int i, char **token)
{
	int		start;

	start = i;
	while (str[i] && is_separator(str, i))
		i++;
	*token = strndup(&str[start], i - start);
	return (i);
}

int	add_token(t_token_data *data, char *token)
{
	data->tokens[data->count++] = token;
	if (data->count >= data->size)
	{
		data->size *= 2;
		data->tokens = realloc(data->tokens, data->size * sizeof(char *));
		if (!data->tokens)
			return (0);
	}
	return (1);
}

int	process_next_token(char *str, int i, t_token_data *data)
{
	char	*token;

	i = skip_spaces(str, i);
	if (!str[i])
		return (i);
	if (is_separator(str, i))
		i = get_separator(str, i, &token);
	else
		i = get_token(str, i, &token);
	if (!add_token(data, token))
		return (-1);
	return (i);
}

char	**split(char *str)
{
	int				i;
	int				j;
	t_token_data	data;

	i = 0;
	j = 0;
	data.size = 10;
	data.count = 0;
	data.tokens = malloc(data.size * sizeof(char *));
	if (!data.tokens)
		return (NULL);
	while (str[i])
	{
		i = process_next_token(str, i, &data);
		if (i == -1)
		{
			while (j < data.count)
				free(data.tokens[j++]);
			free(data.tokens);
			return (NULL);
		}
	}
	data.tokens[data.count] = NULL;
	return (data.tokens);
}

int	main(void)
{
	char	**tokens;
	int		i;

	char *str = "abc abc<<abc|abc&>abc;|abc";
	tokens = split(str);
	i = 0;
	if (!tokens)
	{
		fprintf(stderr, "Memory allocation failed\n");
		return (1);
	}
	while (tokens[i])
	{
		printf("Token %d: '%s'\n", i + 1, tokens[i]);
		free(tokens[i]);
		i++;
	}
	free(tokens);
	return (0);
}


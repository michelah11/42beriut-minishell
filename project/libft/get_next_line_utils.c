/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayoub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 21:04:17 by tayoub            #+#    #+#             */
/*   Updated: 2024/06/27 21:55:39 by tayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;
	size_t		j;

	str = (char *) malloc(sizeof(*s) * (len + 1));
	if (str == 0)
	{
		return (NULL);
	}
	i = start;
	j = 0;
	while (s[i] && j < len)
	{
		str[j] = s[i];
		j++;
		i++;
	}
	str[j] = 0;
	return (str);
}

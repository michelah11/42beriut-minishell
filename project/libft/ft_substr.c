/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayoub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:00:32 by tayoub            #+#    #+#             */
/*   Updated: 2024/06/19 20:13:58 by tayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*arr;
	unsigned int	src_len;

	src_len = ft_strlen(s);
	if (!s)
		return (0);
	if (start >= src_len)
		return (ft_strdup(""));
	if (src_len - start < len)
		len = src_len - start;
	arr = malloc((len + 1) * sizeof(char));
	if (!arr)
		return (arr);
	ft_strlcpy(arr, s + start, len + 1);
	return (arr);
}

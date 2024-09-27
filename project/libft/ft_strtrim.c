/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayoub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 22:20:30 by tayoub            #+#    #+#             */
/*   Updated: 2024/06/19 22:43:14 by tayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*arr;
	int		len;
	int		start;

	if (!set)
		return (ft_strdup(s1));
	if (!s1)
		return (ft_strdup(""));
	start = 0;
	len = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[start]) && start <= len)
		start++;
	if (start > len)
		return (ft_strdup(s1 + len + 1));
	while (ft_strchr(set, s1[len]) && len >= 0)
		len--;
	arr = malloc(len - start + 2);
	if (!arr)
		return (NULL);
	ft_strlcpy(arr, s1 + start, len - start + 2);
	return (arr);
}		

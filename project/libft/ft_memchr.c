/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayoub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 01:16:16 by tayoub            #+#    #+#             */
/*   Updated: 2024/06/19 01:16:19 by tayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*arr;

	arr = (unsigned char *) str;
	i = 0;
	if (c > 256)
		c = c % 256;
	while (i < n)
	{
		if (arr[i] == c)
			return (arr + i);
		i++;
	}
	return (NULL);
}

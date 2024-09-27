/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayoub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 23:08:15 by tayoub            #+#    #+#             */
/*   Updated: 2024/06/11 23:09:13 by tayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_char;
	unsigned char	*src_char;
	size_t			diff;

	diff = dest - src;
	dest_char = (unsigned char *) dest;
	src_char = (unsigned char *) src;
	if (src < dest && (diff < n))
	{
		while (n > 0)
		{
			dest_char[n - 1] = src_char[n - 1];
			n--;
		}
		return (dest);
	}
	else
		return (ft_memcpy(dest, src, n));
}

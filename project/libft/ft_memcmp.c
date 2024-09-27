/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayoub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 01:32:25 by tayoub            #+#    #+#             */
/*   Updated: 2024/06/19 01:32:29 by tayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	size_t			i;
	unsigned char	*ptr1_char;
	unsigned char	*ptr2_char;

	ptr1_char = (unsigned char *) ptr1;
	ptr2_char = (unsigned char *) ptr2;
	i = 0;
	while (i < n)
	{
		if (ptr1_char[i] != ptr2_char[i])
			return ((int)(ptr1_char[i] - ptr2_char[i]));
		i++;
	}
	return (0);
}		

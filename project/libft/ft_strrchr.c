/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayoub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 00:03:00 by tayoub            #+#    #+#             */
/*   Updated: 2024/06/19 00:03:02 by tayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*res;
	char	*p;
	char	tmp;

	tmp = (char)c;
	res = (char *)s;
	len = 0;
	p = NULL;
	if (c == '\0')
		return (res + ft_strlen(s));
	while (res[len])
	{
		if (res[len] == tmp)
			p = &res[len];
		len++;
	}
	return (p);
}

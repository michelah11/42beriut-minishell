/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayoub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:41:45 by tayoub            #+#    #+#             */
/*   Updated: 2024/06/19 19:41:48 by tayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	int		i;
	int		j;

	i = ft_strlen(s);
	j = 0;
	p = (char *)malloc((i + 1) * sizeof(char));
	if (!p)
		return (0);
	while (j < i)
	{
		p[j] = s[j];
		j++;
	}
	p[j] = '\0';
	return (p);
}

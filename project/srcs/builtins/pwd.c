/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 20:39:11 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/09/25 21:06:37 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int pwd(void)
{
    char    *buffer;

    buffer = NULL;
    buffer = getcwd(buffer, 1024);
    if (buffer)
    {
        printf("%s\n", buffer);
        free(buffer);
        return (0);
    }
    return (errno);
}

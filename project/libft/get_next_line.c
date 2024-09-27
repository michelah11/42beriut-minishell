/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayoub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 22:04:18 by tayoub            #+#    #+#             */
/*   Updated: 2024/06/28 00:08:23 by tayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*handle_str(char *buf, char *str)
{
	char	*temp;

	if (!str)
		str = ft_strdup("");
	temp = str;
	str = ft_strjoin(temp, buf);
	free(temp);
	return (str);
}

static char	*parse(int fd, char *buf, char **str)
{
	int	bytes_read;

	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			if (*str)
			{
				free(*str);
				*str = NULL;
			}
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buf[bytes_read] = 0;
		*str = handle_str(buf, *str);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (*str);
}

static char	*extract(char *line)
{
	size_t	i;
	char	*str;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
		return (0);
	str = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (str && !(*str))
	{
		free(str);
		str = NULL;
	}
	line[i + 1] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (str)
		{
			free(str);
			str = NULL;
		}
		return (NULL);
	}
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = parse(fd, buf, &str);
	free(buf);
	if (!line)
		return (NULL);
	str = extract(line);
	return (line);
}

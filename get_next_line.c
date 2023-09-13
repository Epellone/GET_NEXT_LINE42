/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epellone <epellone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:29:53 by epellone          #+#    #+#             */
/*   Updated: 2023/03/16 15:33:33 by epellone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_file(int fd, char *str_read)
{
	char	*buff;
	int		bytes_read;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(str_read, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes_read] = '\0';
		str_read = ft_strjoin(str_read, buff);
	}
	free(buff);
	return (str_read);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*saved;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saved = ft_read_file(fd, saved);
	if (!saved)
		return (NULL);
	line = ft_extract_line(saved);
	saved = ft_backup(saved);
	return (line);
}

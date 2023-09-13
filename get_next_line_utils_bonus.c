/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epellone <epellone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:26:04 by epellone          #+#    #+#             */
/*   Updated: 2023/03/16 15:26:10 by epellone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str_read, int c)
{
	if (!str_read)
		return (NULL);
	while (*str_read != (unsigned char)c)
	{
		if (*str_read == '\0')
			return (NULL);
		str_read++;
	}
	return (str_read);
}

char	*ft_strjoin(char *str_read, char *buff)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	if (!str_read)
	{
		str_read = malloc(sizeof(char) * 1);
		str_read[0] = '\0';
	}
	if (!buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(str_read) + ft_strlen(buff)) + 2));
	if (!str)
		return (NULL);
	len1 = -1;
	len2 = 0;
	while (str_read && str_read[++len1] != '\0')
		str[len1] = str_read[len1];
	while (buff[len2] != '\0')
		str[len1++] = buff[len2++];
	str[ft_strlen(str_read) + ft_strlen(buff)] = '\0';
	free(str_read);
	return (str);
}

char	*ft_extract_line(char *saved)
{
	int		i;
	char	*str;

	if (!saved[0])
		return (NULL);
	i = 0;
	while (saved[i] && saved[i] != '\n')
		i++;
	if (saved[i] == '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (saved[i] && saved[i] != '\n')
	{
		str[i] = saved[i];
		i++;
	}
	if (saved[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*ft_backup(char *backup)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if (!backup[i])
	{
		free(backup);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(backup) - i));
	if (!str)
		return (NULL);
	while (backup[++i])
		str[j++] = backup[i];
	str[j] = '\0';
	free(backup);
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epellone <epellone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:32:20 by epellone          #+#    #+#             */
/*   Updated: 2023/03/16 16:05:53 by epellone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_read_file(int fd, char *str_read);
char	*ft_strchr(char *str_read, int c);
char	*ft_strjoin(char *backup, char *buff);
size_t	ft_strlen(const char *str);
char	*ft_extract_line(char *saved);
char	*ft_backup(char *backup);

#endif
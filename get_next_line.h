/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdfaddo <abdfaddo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 02:41:39 by abdfaddo          #+#    #+#             */
/*   Updated: 2025/11/25 21:27:38 by abdfaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>

size_t	ft_strlen(const char *s);
ssize_t	ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*new_line(char *temp, ssize_t *i);
char	*chiyata(char *temp, ssize_t *i);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
char	*read_chunk(int fd, char **buffer, ssize_t *n);
char	*process_temp(char **temp, ssize_t *i);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

#endif

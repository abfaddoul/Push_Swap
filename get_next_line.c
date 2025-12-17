/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdfaddo <abdfaddo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 02:52:44 by abdfaddo          #+#    #+#             */
/*   Updated: 2025/11/26 01:31:49 by abdfaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;

	i = 0;
	if (!s1)
		return (NULL);
	while (s1[i])
		i++;
	s2 = malloc(sizeof(char) * (i + 1));
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s3;

	size_t len1, (len2), (i), (j);
	i = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s3 = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!s3)
		return (NULL);
	while (i < len1)
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len2)
		s3[i++] = s2[j++];
	return (s3[i] = '\0', s3);
}

char	*process_temp(char **temp, ssize_t *i)
{
	char	*line;
	char	*old;

	if (!*temp || (*temp)[0] == '\0')
	{
		free(*temp);
		*temp = NULL;
		return (NULL);
	}
	*i = ft_strchr(*temp, '\n');
	if (*i != -1)
	{
		line = new_line(*temp, i);
		old = *temp;
		*temp = chiyata(*temp, i);
		free(old);
		return (line);
	}
	line = ft_strdup(*temp);
	free(*temp);
	*temp = NULL;
	return (line);
}

char	*read_chunk(int fd, char **buffer, ssize_t *n)
{
	*buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!*buffer)
		return (NULL);
	*n = read(fd, *buffer, BUFFER_SIZE);
	if (*n <= 0)
	{
		free(*buffer);
		if (*n < 0)
			return (NULL);
		return (NULL);
	}
	(*buffer)[*n] = '\0';
	return (*buffer);
}

char	*get_next_line(int fd)
{
	static char	*temp;

	char *(buffer), *(old);
	ssize_t n, (i);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	n = 1;
	while (n != 0)
	{
		i = ft_strchr(temp, '\n');
		if (i != -1)
			break ;
		if (!read_chunk(fd, &buffer, &n))
			return (process_temp(&temp, &i));
		old = temp;
		temp = ft_strjoin(temp, buffer);
		free(old);
		free(buffer);
		if (!temp)
			return (NULL);
	}
	return (process_temp(&temp, &i));
}

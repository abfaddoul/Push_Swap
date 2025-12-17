/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdfaddo <abdfaddo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 23:20:36 by abdfaddo          #+#    #+#             */
/*   Updated: 2025/11/25 02:08:44 by abdfaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

ssize_t	ft_strchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*s2;

	size_t i, (j), (all_size);
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
		i++;
	if (start >= i)
		all_size = 0;
	else if (len > i - start)
		all_size = i - start;
	else
		all_size = len;
	s2 = malloc(sizeof(char) * (all_size + 1));
	if (!s2)
		return (NULL);
	while (j < all_size)
	{
		s2[j] = s[j + start];
		j++;
	}
	s2[j] = '\0';
	return (s2);
}

char	*new_line(char *temp, ssize_t *i)
{
	*i = ft_strchr(temp, '\n');
	return (ft_substr(temp, 0, *i + 1));
}

char	*chiyata(char *temp, ssize_t *i)
{
	size_t	len;
	ssize_t	start;

	len = ft_strlen(temp);
	start = *i + 1;
	if ((size_t)start >= len)
		return (NULL);
	return (ft_substr(temp, (size_t)start, len - (size_t)start));
}

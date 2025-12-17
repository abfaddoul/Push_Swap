/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdfaddo <abdfaddo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 05:48:50 by abdfaddo          #+#    #+#             */
/*   Updated: 2025/12/17 16:23:49 by abdfaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int	count_words_ws(const char *s)
{
	int	i;
	int	in;
	int	count;

	i = 0;
	in = 0;
	count = 0;
	while (s[i])
	{
		if (!is_ws(s[i]) && in == 0)
		{
			in = 1;
			count++;
		}
		else if (is_ws(s[i]))
			in = 0;
		i++;
	}
	return (count);
}

char	*dup_word(const char *s, int start, int end)
{
	char	*to;
	int		i;

	to = malloc((end - start + 1) * sizeof(char));
	if (!to)
		return (NULL);
	i = 0;
	while (start < end)
		to[i++] = s[start++];
	to[i] = '\0';
	return (to);
}

char	**fill_words_ws(char **full, const char *s)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && is_ws(s[i]))
			i++;
		start = i;
		while (s[i] && !is_ws(s[i]))
			i++;
		if (i > start)
		{
			full[j] = dup_word(s, start, i);
			if (!full[j])
				return (free_split(full), NULL);
			j++;
		}
	}
	full[j] = NULL;
	return (full);
}

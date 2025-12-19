/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdfaddo <abdfaddo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 05:48:40 by abdfaddo          #+#    #+#             */
/*   Updated: 2025/12/17 16:23:26 by abdfaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	**ft_split_ws(const char *s)
{
	char	**full;
	int		wc;

	if (!s)
		return (NULL);
	wc = count_words_ws(s);
	full = malloc((wc + 1) * sizeof(char *));
	if (!full)
		return (NULL);
	full[0] = NULL;
	return (fill_words_ws(full, s));
}

int	is_only_ws(const char *s)
{
	int	i;

	if (!s || !s[0])
		return (1);
	i = 0;
	while (s[i])
	{
		if (!(s[i] == ' ' || (s[i] >= 9 && s[i] <= 13)))
			return (0);
		i++;
	}
	return (1);
}

void	free_tokens(char **t)
{
	int	i;

	if (!t)
		return ;
	i = 0;
	while (t[i])
		free(t[i++]);
	free(t);
}

void	add_value_or_error(t_stack *a, char **tok, int value)
{
	t_node	*n;

	n = new_node(value);
	if (!n)
	{
		ps_error_exit(a, NULL, tok);
	}
	stack_add_bottom(a, n);
}

void	parse_tokens_to_stack(t_stack *a, char **tok)
{
	int	j;
	int	value;

	j = 0;
	while (tok[j])
	{
		if (!ps_atoi(tok[j], &value))
		{
			ps_error_exit(a, NULL, tok);
		}
		add_value_or_error(a, tok, value);
		j++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdfaddo <abdfaddo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 05:48:14 by abdfaddo          #+#    #+#             */
/*   Updated: 2025/12/17 16:19:08 by abdfaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicates(t_stack *a)
{
	t_node	*cur;
	t_node	*cmp;

	if (!a)
		return ;
	cur = a->top;
	while (cur)
	{
		cmp = cur->next;
		while (cmp)
		{
			if (cmp->value == cur->value)
				ps_error();
			cmp = cmp->next;
		}
		cur = cur->next;
	}
}

int	is_only_spaces(const char *s)
{
	int	i;

	if (!s || !s[0])
		return (1);
	i = 0;
	while (s[i])
	{
		if (s[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	is_ws(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdfaddo <abdfaddo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 05:47:43 by abdfaddo          #+#    #+#             */
/*   Updated: 2025/12/19 02:52:31 by abdfaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	build_stack_a(t_stack *a, int ac, char **av)
{
	int		i;
	char	**tok;

	i = 1;
	while (i < ac)
	{
		if (is_only_ws(av[i]))
			ps_error_exit(a, NULL, NULL);
		tok = ft_split_ws(av[i]);
		if (!tok || !tok[0])
			(ps_error_exit(a, NULL, tok));
		parse_tokens_to_stack(a, tok);
		free_tokens(tok);
		i++;
	}
}

int	find_min_pos(t_stack *a)
{
	t_node	*cur;
	int		min;
	int		pos;
	int		best;

	cur = a->top;
	min = cur->value;
	pos = 0;
	best = 0;
	while (cur)
	{
		if (cur->value < min)
		{
			min = cur->value;
			best = pos;
		}
		cur = cur->next;
		pos++;
	}
	return (best);
}

void	bring_pos_to_top(t_stack *a, int pos)
{
	if (pos <= a->size / 2)
	{
		while (pos-- > 0)
			ra(a);
	}
	else
	{
		while (pos++ < a->size)
			rra(a);
	}
}

void	sort_5(t_stack *a, t_stack *b)
{
	int	pos;

	if (!a || a->size <= 1 || is_sorted(a))
		return ;
	while (a->size > 3)
	{
		pos = find_min_pos(a);
		bring_pos_to_top(a, pos);
		pb(a, b);
	}
	sort_3(a);
	while (b->size > 0)
		pa(a, b);
}

void	assign_index(t_stack *a)
{
	t_node	*cur;
	t_node	*cmp;
	int		rank;

	if (!a || a->size == 0)
		return ;
	cur = a->top;
	while (cur)
	{
		rank = 0;
		cmp = a->top;
		while (cmp)
		{
			if (cmp->value < cur->value)
				rank++;
			cmp = cmp->next;
		}
		cur->index = rank;
		cur = cur->next;
	}
}

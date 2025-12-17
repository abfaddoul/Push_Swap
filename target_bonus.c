/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdfaddo <abdfaddo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 05:48:04 by abdfaddo          #+#    #+#             */
/*   Updated: 2025/12/17 16:18:48 by abdfaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push_to_b(t_stack *a, t_stack *b)
{
	int	total;
	int	pivot;
	int	i;

	if (!a || !b)
		return ;
	total = a->size;
	pivot = total / 2;
	i = 0;
	while (a->size > 3 && i < total)
	{
		if (a->top->index <= pivot)
		{
			pb(a, b);
			if (b->top && b->top->index <= pivot / 2)
				rb(b);
		}
		else
			ra(a);
		i++;
	}
	while (a->size > 3)
		pb(a, b);
}

t_node	*get_target_in_a(t_stack *a, int b_index)
{
	t_node	*cur;
	t_node	*target;

	if (!a || !a->top)
		return (NULL);
	cur = a->top;
	target = NULL;
	while (cur)
	{
		if (cur->index > b_index)
		{
			if (!target || cur->index < target->index)
				target = cur;
		}
		cur = cur->next;
	}
	if (!target)
		target = min_index_node(a);
	return (target);
}

void	set_targets(t_stack *a, t_stack *b)
{
	t_node	*cur;

	if (!a || !b)
		return ;
	cur = b->top;
	while (cur)
	{
		cur->target = get_target_in_a(a, cur->index);
		cur = cur->next;
	}
}

void	set_costs(t_stack *a, t_stack *b)
{
	t_node	*cur;

	if (!a || !b)
		return ;
	cur = b->top;
	while (cur)
	{
		cur->cost_b = cost_to_top(b, cur);
		cur->cost_a = cost_to_top(a, cur->target);
		cur = cur->next;
	}
}

t_node	*get_cheapest(t_stack *b)
{
	t_node	*cur;
	t_node	*best;
	int		best_cost;
	int		cost;

	if (!b || !b->top)
		return (NULL);
	cur = b->top;
	best = cur;
	best_cost = ps_abs(cur->cost_a) + ps_abs(cur->cost_b);
	while (cur)
	{
		cost = ps_abs(cur->cost_a) + ps_abs(cur->cost_b);
		if (cost < best_cost)
		{
			best_cost = cost;
			best = cur;
		}
		cur = cur->next;
	}
	return (best);
}

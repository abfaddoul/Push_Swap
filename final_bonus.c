/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdfaddo <abdfaddo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 05:47:54 by abdfaddo          #+#    #+#             */
/*   Updated: 2025/12/17 16:08:17 by abdfaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate_both(t_stack *a, t_stack *b, int *ca, int *cb)
{
	while (*ca > 0 && *cb > 0)
	{
		rr(a, b);
		(*ca)--;
		(*cb)--;
	}
	while (*ca < 0 && *cb < 0)
	{
		rrr(a, b);
		(*ca)++;
		(*cb)++;
	}
}

void	rotate_a(t_stack *a, int *ca)
{
	while (*ca > 0)
	{
		ra(a);
		(*ca)--;
	}
	while (*ca < 0)
	{
		rra(a);
		(*ca)++;
	}
}

void	rotate_b(t_stack *b, int *cb)
{
	while (*cb > 0)
	{
		rb(b);
		(*cb)--;
	}
	while (*cb < 0)
	{
		rrb(b);
		(*cb)++;
	}
}

void	exec_move(t_stack *a, t_stack *b, t_node *x)
{
	int	ca;
	int	cb;

	if (!a || !b || !x)
		return ;
	ca = x->cost_a;
	cb = x->cost_b;
	rotate_both(a, b, &ca, &cb);
	rotate_a(a, &ca);
	rotate_b(b, &cb);
	pa(a, b);
}

void	final_rotate(t_stack *a)
{
	t_node	*min;
	int		cost;

	if (!a || !a->top)
		return ;
	min = min_index_node(a);
	cost = cost_to_top(a, min);
	while (cost > 0)
	{
		ra(a);
		cost--;
	}
	while (cost < 0)
	{
		rra(a);
		cost++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdfaddo <abdfaddo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 05:48:21 by abdfaddo          #+#    #+#             */
/*   Updated: 2025/12/17 16:19:40 by abdfaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ps_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

t_node	*min_index_node(t_stack *s)
{
	t_node	*cur;
	t_node	*min;

	if (!s || !s->top)
		return (NULL);
	cur = s->top;
	min = cur;
	while (cur)
	{
		if (cur->index < min->index)
			min = cur;
		cur = cur->next;
	}
	return (min);
}

t_node	*max_index_node(t_stack *s)
{
	t_node	*cur;
	t_node	*max;

	if (!s || !s->top)
		return (NULL);
	cur = s->top;
	max = cur;
	while (cur)
	{
		if (cur->index > max->index)
			max = cur;
		cur = cur->next;
	}
	return (max);
}

int	stack_pos(t_stack *s, t_node *n)
{
	t_node	*cur;
	int		pos;

	if (!s || !n)
		return (-1);
	cur = s->top;
	pos = 0;
	while (cur)
	{
		if (cur == n)
			return (pos);
		cur = cur->next;
		pos++;
	}
	return (-1);
}

int	cost_to_top(t_stack *s, t_node *n)
{
	int	pos;

	if (!s || !n || s->size < 2)
		return (0);
	pos = stack_pos(s, n);
	if (pos < 0)
		return (0);
	if (pos <= s->size / 2)
		return (pos);
	return (-(s->size - pos));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdfaddo <abdfaddo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 20:00:17 by abdfaddo          #+#    #+#             */
/*   Updated: 2025/12/17 16:12:57 by abdfaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	swap_stack(t_stack *s)
{
	t_node	*first;
	t_node	*second;
	int		tmp;

	if (!s || s->size < 2)
		return (0);
	first = s->top;
	second = first->next;
	tmp = first->value;
	first->value = second->value;
	second->value = tmp;
	tmp = first->index;
	first->index = second->index;
	second->index = tmp;
	return (1);
}

int	push_stack(t_stack *dst, t_stack *src)
{
	t_node	*tmp;

	if (!dst || !src || src->size == 0)
		return (0);
	tmp = src->top;
	src->top = tmp->next;
	src->size--;
	tmp->next = dst->top;
	dst->top = tmp;
	dst->size++;
	return (1);
}

int	rotate_stack(t_stack *s)
{
	t_node	*first;
	t_node	*last;

	if (!s || s->size < 2)
		return (0);
	first = s->top;
	s->top = first->next;
	first->next = NULL;
	last = s->top;
	while (last->next)
		last = last->next;
	last->next = first;
	return (1);
}

int	reverse_rotate_stack(t_stack *s)
{
	t_node	*prev;
	t_node	*last;

	if (!s || s->size < 2)
		return (0);
	prev = NULL;
	last = s->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (prev)
		prev->next = NULL;
	last->next = s->top;
	s->top = last;
	return (1);
}

void	sa(t_stack *a)
{
	swap_stack(a);
}

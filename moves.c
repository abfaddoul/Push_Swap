/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdfaddo <abdfaddo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 20:00:17 by abdfaddo          #+#    #+#             */
/*   Updated: 2025/12/14 20:00:22 by abdfaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap_stack(t_stack *s)
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


static int	push_stack(t_stack *dst, t_stack *src)
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

static int	rotate_stack(t_stack *s)
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

static int	reverse_rotate_stack(t_stack *s)
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
	if (swap_stack(a))
		write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	if (swap_stack(b))
		write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	int	da;
	int	db;

	da = swap_stack(a);
	db = swap_stack(b);
	if (da && db)
		write(1, "ss\n", 3);
	else if (da)
		write(1, "sa\n", 3);
	else if (db)
		write(1, "sb\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	if (push_stack(a, b))
		write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	if (push_stack(b, a))
		write(1, "pb\n", 3);
}

void	ra(t_stack *a)
{
	if (rotate_stack(a))
		write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	if (rotate_stack(b))
		write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	int	da;
	int	db;

	da = rotate_stack(a);
	db = rotate_stack(b);
	if (da && db)
		write(1, "rr\n", 3);
	else if (da)
		write(1, "ra\n", 3);
	else if (db)
		write(1, "rb\n", 3);
}

void	rra(t_stack *a)
{
	if (reverse_rotate_stack(a))
		write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	if (reverse_rotate_stack(b))
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	int	da;
	int	db;

	da = reverse_rotate_stack(a);
	db = reverse_rotate_stack(b);
	if (da && db)
		write(1, "rrr\n", 4);
	else if (da)
		write(1, "rra\n", 4);
	else if (db)
		write(1, "rrb\n", 4);
}

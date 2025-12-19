/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdfaddo <abdfaddo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 05:47:34 by abdfaddo          #+#    #+#             */
/*   Updated: 2025/12/19 02:53:55 by abdfaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_error_exit(t_stack *a, t_stack *b, char **tok)
{
	if (tok)
		free_tokens(tok);
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

t_node	*new_node(int value)
{
	t_node	*n;

	n = malloc(sizeof(t_node));
	if (!n)
		return (NULL);
	n->value = value;
	n->index = -1;
	n->cost_a = 0;
	n->cost_b = 0;
	n->target = NULL;
	n->next = NULL;
	return (n);
}

void	stack_add_bottom(t_stack *stack, t_node *new)
{
	t_node	*cur;

	if (!stack || !new)
		return ;
	if (!stack->top)
	{
		stack->top = new;
	}
	else
	{
		cur = stack->top;
		while (cur->next)
			cur = cur->next;
		cur->next = new;
	}
	stack->size++;
}

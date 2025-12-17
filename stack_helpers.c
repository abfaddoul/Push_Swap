/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdfaddo <abdfaddo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 19:17:10 by abdfaddo          #+#    #+#             */
/*   Updated: 2025/12/17 19:17:13 by abdfaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(t_stack *a, t_stack *b)
{
	a->top = NULL;
	a->size = 0;
	b->top = NULL;
	b->size = 0;
}

void	free_stack(t_stack *s)
{
	t_node	*tmp;

	while (s && s->top)
	{
		tmp = s->top->next;
		free(s->top);
		s->top = tmp;
	}
	if (s)
		s->size = 0;
}

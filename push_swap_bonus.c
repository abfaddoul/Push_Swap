/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdfaddo <abdfaddo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 19:55:24 by abdfaddo          #+#    #+#             */
/*   Updated: 2025/12/17 16:15:23 by abdfaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push_swap(t_stack *a, t_stack *b)
{
	t_node	*x;
	t_node	*c;

	if (!a || a->size < 2 || is_sorted(a))
		return ;
	assign_index(a);
	c = a->top;
	if (a->size <= 5)
	{
		sort_5(a, b);
		return ;
	}
	push_to_b(a, b);
	sort_3(a);
	while (b->size > 0)
	{
		set_targets(a, b);
		set_costs(a, b);
		x = get_cheapest(b);
		exec_move(a, b, x);
	}
	final_rotate(a);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac < 2)
		return (0);
	init_stacks(&a, &b);
	build_stack_a(&a, ac, av);
	check_duplicates(&a);
	if (!is_sorted(&a))
		push_swap(&a, &b);
	free_stack(&a);
	return (0);
}

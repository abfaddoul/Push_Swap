/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdfaddo <abdfaddo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:23:01 by abdfaddo          #+#    #+#             */
/*   Updated: 2025/12/17 16:23:03 by abdfaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

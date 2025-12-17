/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdfaddo <abdfaddo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:13:39 by abdfaddo          #+#    #+#             */
/*   Updated: 2025/12/17 16:13:41 by abdfaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

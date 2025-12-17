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

#include "checker.h"

void	sb(t_stack *b)
{
	swap_stack(b);
}

void	ss(t_stack *a, t_stack *b)
{
	swap_stack(a);
	swap_stack(b);
}

void	pa(t_stack *a, t_stack *b)
{
	push_stack(a, b);
}

void	pb(t_stack *a, t_stack *b)
{
	push_stack(b, a);
}

void	ra(t_stack *a)
{
	rotate_stack(a);
}

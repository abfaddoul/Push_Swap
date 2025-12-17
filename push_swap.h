/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdfaddo <abdfaddo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 19:55:30 by abdfaddo          #+#    #+#             */
/*   Updated: 2025/12/11 19:55:32 by abdfaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
#include <limits.h>
#include <stdio.h>

typedef struct s_node
{
	int				value;
	int				index;
	int				cost_a;
	int				cost_b;
	struct s_node	*target;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
    t_node  *top;
    int     size;
}   t_stack;

/* stack utils */
static int	parse_number(const char *s, int i, int sign, int *out);
void    build_stack_a(t_stack *a, int ac, char **av);
void    ps_error(void);
t_node *new_node(int value);
void    stack_add_bottom(t_stack *stack, t_node *new);
char	**ft_split_ws(const char *s);
void	sort_5(t_stack *a, t_stack *b);
void	assign_index(t_stack *a);
void	turk_sort(t_stack *a, t_stack *b);

/* checks */
int     is_sorted(t_stack *a);
int	ps_atoi(const char *s, int *out);
void	sort_2(t_stack *a);
void	sort_3(t_stack *a);
void	check_duplicates(t_stack *a);


/* operations */
void    sa(t_stack *a);
void    sb(t_stack *b);
void    ss(t_stack *a, t_stack *b);
void    pa(t_stack *a, t_stack *b);
void    pb(t_stack *a, t_stack *b);
void    ra(t_stack *a);
void    rb(t_stack *b);
void    rr(t_stack *a, t_stack *b);
void    rra(t_stack *a);
void    rrb(t_stack *b);
void    rrr(t_stack *a, t_stack *b);

#endif
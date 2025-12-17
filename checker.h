/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdfaddo <abdfaddo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 19:17:24 by abdfaddo          #+#    #+#             */
/*   Updated: 2025/12/17 19:18:17 by abdfaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

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
	int		size;
	t_node	*top;
}	t_stack;

int		is_sorted(t_stack *a);
int		ps_atoi(const char *s, int *out);
int		parse_number(const char *s, int i, int sign, int *out);
int		is_space(char c);
int		is_digit(char c);
int		is_only_spaces(const char *s);
int		is_ws(char c);
int		is_only_ws(const char *s);
int		find_min_pos(t_stack *a);
int		ps_abs(int x);
int		count_words_ws(const char *s);
int		stack_pos(t_stack *s, t_node *n);
int		cost_to_top(t_stack *s, t_node *n);
int		reverse_rotate_stack(t_stack *s);
int		rotate_stack(t_stack *s);
int		push_stack(t_stack *dst, t_stack *src);
int		swap_stack(t_stack *s);
int		exec_instruction(char *line, t_stack *a, t_stack *b);
char	**ft_split_ws(const char *s);
char	*dup_word(const char *s, int start, int end);
char	**fill_words_ws(char **full, const char *s);
t_node	*new_node(int value);
t_node	*min_index_node(t_stack *s);
t_node	*max_index_node(t_stack *s);
t_node	*get_target_in_a(t_stack *a, int b_index);
t_node	*get_cheapest(t_stack *b);
void	build_stack_a(t_stack *a, int ac, char **av);
void	ps_error(void);
void	stack_add_bottom(t_stack *stack, t_node *new);
void	sort_5(t_stack *a, t_stack *b);
void	assign_index(t_stack *a);
void	push_swap(t_stack *a, t_stack *b);
void	free_split(char **arr);
void	free_tokens(char **t);
void	add_value_or_error(t_stack *a, char **tok, int value);
void	parse_tokens_to_stack(t_stack *a, char **tok);
void	build_stack_a(t_stack *a, int ac, char **av);
void	bring_pos_to_top(t_stack *a, int pos);
void	push_to_b(t_stack *a, t_stack *b);
void	set_targets(t_stack *a, t_stack *b);
void	set_costs(t_stack *a, t_stack *b);
void	rotate_both(t_stack *a, t_stack *b, int *ca, int *cb);
void	rotate_a(t_stack *a, int *ca);
void	rotate_b(t_stack *b, int *cb);
void	exec_move(t_stack *a, t_stack *b, t_node *x);
void	final_rotate(t_stack *a);
void	sort_2(t_stack *a);
void	sort_3(t_stack *a);
void	check_duplicates(t_stack *a);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	free_stack(t_stack *s);
void	init_stacks(t_stack *a, t_stack *b);
void	read_and_exec(t_stack *a, t_stack *b);
void	print_result(t_stack *a, t_stack *b);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdfaddo <abdfaddo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:19:09 by abdfaddo          #+#    #+#             */
/*   Updated: 2025/12/11 20:19:10 by abdfaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int  is_space(char c)
{
    return (c == ' ' || (c >= 9 && c <= 13));
}

static int  is_digit(char c)
{
    return (c >= '0' && c <= '9');
}
static int	parse_number(const char *s, int i, int sign, int *out)
{
	long long	n;

	if (!is_digit(s[i]))
		return (0);
	n = 0;
	while (is_digit(s[i]))
	{
		n = n * 10 + (s[i] - '0');
		if ((sign == 1 && n > INT_MAX)
			|| (sign == -1 && -n < INT_MIN))
			return (0);
		i++;
	}
	while (is_space(s[i]))
		i++;
	if (s[i])
		return (0);
	*out = (int)(sign * n);
	return (1);
}
int	ps_atoi(const char *s, int *out)
{
	int	i;
	int	sign;

	if (!s || !s[0])
		return (0);
	i = 0;
	while (is_space(s[i]))
		i++;
	sign = 1;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	return (parse_number(s, i, sign, out));
}
void    ps_error(void)
{
    write(2, "Error\n", 6);
    _exit(1);
}
t_node	*new_node(int value)
{
	t_node	*n;

	n = malloc(sizeof(t_node));
	if (!n)
		return (NULL);
	n->value = value;
	n->index = -1;
	n->next = NULL;
	return (n);
}
void    stack_add_bottom(t_stack *stack, t_node *new)
{
    t_node *cur;

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
int	is_sorted(t_stack *a)
{
	t_node	*cur;

	if (!a || a->size < 2)
		return (1);
	cur = a->top;
	while (cur->next)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}
void	sort_2(t_stack *a)
{
	if (a->size < 2)
		return ;
	if (a->top->value > a->top->next->value)
		sa(a);
}
void	sort_3(t_stack *a)
{
	int	x, y, z;

	if (a->size != 3)
		return ;
	x = a->top->value;
	y = a->top->next->value;
	z = a->top->next->next->value;
	if (x > y && y < z && x < z)
		sa(a);                /* 2 1 3 */
	else if (x > y && y > z)
	{
        sa(a);
        rra(a);
    }                         /* 3 2 1 */
	else if (x > y && y < z && x > z)
		ra(a);                /* 3 1 2 */
	else if (x < y && y > z && x < z)
	{
        sa(a);
        ra(a);
    }                         /* 1 3 2 */
	else if (x < y && y > z && x > z)
		rra(a);               /* 2 3 1 */
}
void	check_duplicates(t_stack *a)
{
	t_node	*cur;
	t_node	*cmp;

	if (!a)
		return ;
	cur = a->top;
	while (cur)
	{
		cmp = cur->next;
		while (cmp)
		{
			if (cmp->value == cur->value)
				ps_error();
			cmp = cmp->next;
		}
		cur = cur->next;
	}
}
static int	is_only_spaces(const char *s)
{
	int	i;

	if (!s || !s[0])
		return (1);
	i = 0;
	while (s[i])
	{
		if (s[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
static int	is_ws(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}
static void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
static int	count_words_ws(const char *s)
{
	int	i;
	int	in;
	int	count;

	i = 0;
	in = 0;
	count = 0;
	while (s[i])
	{
		if (!is_ws(s[i]) && in == 0)
		{
			in = 1;
			count++;
		}
		else if (is_ws(s[i]))
			in = 0;
		i++;
	}
	return (count);
}
static char	*dup_word(const char *s, int start, int end)
{
	char	*to;
	int		i;

	to = malloc((end - start + 1) * sizeof(char));
	if (!to)
		return (NULL);
	i = 0;
	while (start < end)
		to[i++] = s[start++];
	to[i] = '\0';
	return (to);
}
static char	**fill_words_ws(char **full, const char *s)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && is_ws(s[i]))
			i++;
		start = i;
		while (s[i] && !is_ws(s[i]))
			i++;
		if (i > start)
		{
			full[j] = dup_word(s, start, i);
			if (!full[j])
				return (free_split(full), NULL);
			j++;
		}
	}
	full[j] = NULL;
	return (full);
}
char	**ft_split_ws(const char *s)
{
	char	**full;
	int		wc;

	if (!s)
		return (NULL);
	wc = count_words_ws(s);
	full = malloc((wc + 1) * sizeof(char *));
	if (!full)
		return (NULL);
	full[0] = NULL;
	return (fill_words_ws(full, s));
}
static int	is_only_ws(const char *s)
{
	int	i;

	if (!s || !s[0])
		return (1);
	i = 0;
	while (s[i])
	{
		if (!(s[i] == ' ' || (s[i] >= 9 && s[i] <= 13)))
			return (0);
		i++;
	}
	return (1);
}
static void	free_tokens(char **t)
{
	int	i;

	if (!t)
		return ;
	i = 0;
	while (t[i])
		free(t[i++]);
	free(t);
}
static void	add_value_or_error(t_stack *a, char **tok, int value)
{
	t_node	*n;

	n = new_node(value);
	if (!n)
	{
		free_tokens(tok);
		ps_error();
	}
	stack_add_bottom(a, n);
}
static void	parse_tokens_to_stack(t_stack *a, char **tok)
{
	int	j;
	int	value;

	j = 0;
	while (tok[j])
	{
		if (!ps_atoi(tok[j], &value))
		{
			free_tokens(tok);
			ps_error();
		}
		add_value_or_error(a, tok, value);
		j++;
	}
}
void	build_stack_a(t_stack *a, int ac, char **av)
{
	int		i;
	char	**tok;

	i = 1;
	while (i < ac)
	{
		if (is_only_ws(av[i]))
			ps_error();
		tok = ft_split_ws(av[i]);
		if (!tok || !tok[0])
			(free_tokens(tok), ps_error());
		parse_tokens_to_stack(a, tok);
		free_tokens(tok);
		i++;
	}
}
static int	find_min_pos(t_stack *a)
{
	t_node	*cur;
	int		min;
	int		pos;
	int		best;

	cur = a->top;
	min = cur->value;
	pos = 0;
	best = 0;
	while (cur)
	{
		if (cur->value < min)
		{
			min = cur->value;
			best = pos;
		}
		cur = cur->next;
		pos++;
	}
	return (best);
}
static void	bring_pos_to_top(t_stack *a, int pos)
{
	if (pos <= a->size / 2)
	{
		while (pos-- > 0)
			ra(a);
	}
	else
	{
		while (pos++ < a->size)
			rra(a);
	}
}
void	sort_5(t_stack *a, t_stack *b)
{
	int	pos;

	if (!a || a->size <= 1 || is_sorted(a))
		return ;
	while (a->size > 3)
	{
		pos = find_min_pos(a);
		bring_pos_to_top(a, pos);
		pb(a, b);
	}
	sort_3(a);
	while (b->size > 0)
		pa(a, b);
}
void	assign_index(t_stack *a)
{
	t_node	*cur;
	t_node	*cmp;
	int		rank;

	if (!a || a->size == 0)
		return ;
	cur = a->top;
	while (cur)
	{
		rank = 0;
		cmp = a->top;
		while (cmp)
		{
			if (cmp->value < cur->value)
				rank++;
			cmp = cmp->next;
		}
		cur->index = rank;
		cur = cur->next;
	}
}
int	ps_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}
t_node	*min_index_node(t_stack *s)
{
	t_node	*cur;
	t_node	*min;

	if (!s || !s->top)
		return (NULL);
	cur = s->top;
	min = cur;
	while (cur)
	{
		if (cur->index < min->index)
			min = cur;
		cur = cur->next;
	}
	return (min);
}
t_node	*max_index_node(t_stack *s)
{
	t_node	*cur;
	t_node	*max;

	if (!s || !s->top)
		return (NULL);
	cur = s->top;
	max = cur;
	while (cur)
	{
		if (cur->index > max->index)
			max = cur;
		cur = cur->next;
	}
	return (max);
}
int	stack_pos(t_stack *s, t_node *n)
{
	t_node	*cur;
	int		pos;

	if (!s || !n)
		return (-1);
	cur = s->top;
	pos = 0;
	while (cur)
	{
		if (cur == n)
			return (pos);
		cur = cur->next;
		pos++;
	}
	return (-1);
}
int	cost_to_top(t_stack *s, t_node *n)
{
	int	pos;

	if (!s || !n || s->size < 2)
		return (0);
	pos = stack_pos(s, n);
	if (pos < 0)
		return (0);
	if (pos <= s->size / 2)
		return (pos);
	return (-(s->size - pos));
}

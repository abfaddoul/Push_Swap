/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdfaddo <abdfaddo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:19:09 by abdfaddo          #+#    #+#             */
/*   Updated: 2025/12/17 16:18:15 by abdfaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	parse_number(const char *s, int i, int sign, int *out)
{
	long long	n;

	if (!is_digit(s[i]))
		return (0);
	n = 0;
	while (is_digit(s[i]))
	{
		n = n * 10 + (s[i] - '0');
		if ((sign == 1 && n > INT_MAX)
			|| (sign == -1 && (-n) < INT_MIN))
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_is_valid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 10:59:21 by messalih          #+#    #+#             */
/*   Updated: 2022/05/21 11:09:08 by messalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(t_stack *s)
{
	s->top_a = 0;
	s->top_h = 0;
	s->top_i = 0;
	s->top_b = 0;
	s->top_i_b = 0;
	s->stack_h = ft_calloc(sizeof(int), (s->s_len + 1));
	if (s->stack_h == NULL)
		return ;
	s->stack_a = ft_calloc(sizeof(int), (s->s_len + 1));
	if (s->stack_a == NULL)
		return ;
	s->stack_index = ft_calloc(sizeof(int), (s->s_len + 1));
	if (s->stack_index == NULL)
		return ;
	s->stack_b = ft_calloc(sizeof(int), (s->s_len + 1));
	if (s->stack_b == NULL)
		return ;
	s->stack_i_b = ft_calloc(sizeof(int), (s->s_len + 1));
	if (s->stack_i_b == NULL)
		return ;
}

int	check_if_dup(t_stack *s)
{
	int	i;
	int	j;

	i = 0;
	while (i < s->s_len)
	{
		j = 0;
		while (j < s->s_len)
		{
			if (s->stack_a[i] == s->stack_a[j] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	if_is_sorted(t_stack *s)
{
	int	x;
	int	i;

	sort_int_tab(s->stack_h, s->s_len);
	i = s->s_len;
	x = 0;
	while (i--)
	{
		if (s->stack_h[i] != s->stack_a[x])
			return (1);
		x++;
	}
	exit(0);
}

int	len_split(t_stack *s, int i)
{
	int	j;

	j = 0;
	s->split = ft_split(s->table[i], ' ');
	while (s->split[j])
		j++;
	return (j);
}

int	check_if_is_valid(t_stack *s, int i, int j)
{
	long	t;

	init_stacks(s);
	i = 0;
	while (s->table[i])
		i++;
	while (i--)
	{
		j = len_split(s, i);
		while (j--)
		{
			t = ft_atoi(s->split[j]);
			if (t >= 2147483647 || t <= -2147483648)
				return (0);
			push_to_stack_a(s, (int)t);
			push_to_stack_h(s, (int)t);
			free(s->split[j]);
		}
		free(s->split);
	}
	if (check_if_dup(s) == 0 || if_is_sorted(s) == 0)
		return (0);
	return (1);
}

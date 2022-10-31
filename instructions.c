/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:25:56 by messalih          #+#    #+#             */
/*   Updated: 2022/05/21 11:26:06 by messalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *s)
{
	int	i;
	int	temp_i;
	int	temp_a;

	i = 0;
	temp_a = s->stack_a[0];
	temp_i = s->stack_index[0];
	while (i < s->top_i - 1)
	{
		s->stack_index[i] = s->stack_index[i + 1];
		s->stack_a[i] = s->stack_a[i + 1];
		i++;
	}
	s->stack_index[s->top_i - 1] = temp_i;
	s->stack_a[s->top_a - 1] = temp_a;
	write(1, "rra\n", 4);
}

void	ra(t_stack *s)
{
	int	temp_i;
	int	temp_a;
	int	i;
	int	x;

	i = s->top_i - 1;
	x = s->top_a - 1;
	temp_a = s->stack_a[s->top_a - 1];
	temp_i = s->stack_index[s->top_i - 1];
	while (i > 0)
	{
		s->stack_index[i] = s->stack_index[i - 1];
		s->stack_a[x] = s->stack_a[x - 1];
		x--;
		i--;
	}
	s->stack_index[0] = temp_i;
	s->stack_a[0] = temp_a;
	write(1, "ra\n", 3);
}

void	sa(t_stack *s)
{
	int	top_i;
	int	top_a;
	int	next_to_top_i;
	int	next_to_top_a;

	top_i = s->stack_index[s->top_i - 1];
	next_to_top_i = s->stack_index[s->top_i - 2];
	top_a = s->stack_a[s->top_a - 1];
	next_to_top_a = s->stack_a[s->top_a - 2];
	s->stack_index[s->top_i - 1] = next_to_top_i;
	s->stack_index[s->top_i - 2] = top_i;
	s->stack_a[s->top_a - 1] = next_to_top_a;
	s->stack_a[s->top_a - 2] = top_a;
	write(1, "sa\n", 3);
}

void	pa(t_stack *s)
{
	push_to_stack_index(s, s->stack_b[s->top_b - 1]);
	push_to_stack_a(s, s->stack_i_b[s->top_i_b - 1]);
	s->top_b--;
	s->top_i_b--;
	write(1, "pa\n", 3);
}

void	pb(t_stack *s)
{
	push_to_stack_b(s, s->stack_index[s->top_i - 1]);
	push_to_stack_i_b(s, s->stack_a[s->top_a - 1]);
	s->top_i--;
	s->top_a--;
	write(1, "pb\n", 3);
}

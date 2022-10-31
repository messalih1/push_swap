/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:26:40 by messalih          #+#    #+#             */
/*   Updated: 2022/05/21 11:27:35 by messalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_stack_a(t_stack *s, int data)
{
	if (s->top_a == s->s_len)
		return ;
	s->stack_a[s->top_a] = data;
	s->top_a++;
}

void	push_to_stack_h(t_stack *s, int data)
{
	if (s->top_h == s->s_len)
		return ;
	s->stack_h[s->top_h] = data;
	s->top_h++;
}

void	push_to_stack_index(t_stack *s, int data)
{
	if (s->top_i == s->s_len)
		return ;
	s->stack_index[s->top_i] = data;
	s->top_i++;
}

void	push_to_stack_b(t_stack *s, int data)
{
	if (s->top_b == s->s_len)
		return ;
	s->stack_b[s->top_b] = data;
	s->top_b++;
}

void	push_to_stack_i_b(t_stack *s, int data)
{
	if (s->top_i_b == s->s_len)
		return ;
	s->stack_i_b[s->top_i_b] = data;
	s->top_i_b++;
}

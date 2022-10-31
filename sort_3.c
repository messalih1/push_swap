/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:28:05 by messalih          #+#    #+#             */
/*   Updated: 2022/05/21 11:28:14 by messalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	s_a(t_stack *s)
{
	int	index1;
	int	index2;

	index2 = s->stack_a[2];
	index1 = s->stack_a[1];
	s->stack_a[2] = index1;
	s->stack_a[1] = index2;
	index2 = s->stack_index[2];
	index1 = s->stack_index[1];
	s->stack_index[2] = index1;
	s->stack_index[1] = index2;
	write(1, "sa\n", 3);
}

static	void	r_a(t_stack *s)
{
	int	index0;
	int	index1;
	int	index2;

	index0 = s->stack_a[0];
	index1 = s->stack_a[1];
	index2 = s->stack_a[2];
	s->stack_a[0] = index2;
	s->stack_a[1] = index0;
	s->stack_a[2] = index1;
	index0 = s->stack_index[0];
	index1 = s->stack_index[1];
	index2 = s->stack_index[2];
	s->stack_index[0] = index2;
	s->stack_index[1] = index0;
	s->stack_index[2] = index1;
	write(1, "ra\n", 3);
}

static	void	rr_a(t_stack *s)
{
	int	index0;
	int	index1;
	int	index2;

	index0 = s->stack_a[0];
	index1 = s->stack_a[1];
	index2 = s->stack_a[2];
	s->stack_a[2] = index0;
	s->stack_a[1] = index2;
	s->stack_a[0] = index1;
	index0 = s->stack_index[0];
	index1 = s->stack_index[1];
	index2 = s->stack_index[2];
	s->stack_index[2] = index0;
	s->stack_index[1] = index2;
	s->stack_index[0] = index1;
	write(1, "rra\n", 4);
}

void	sort_3(t_stack *s)
{
	if (s->stack_a[0] < s->stack_a[1] && s->stack_a[0] < s->stack_a[2]
		&& s->stack_a[2] > s->stack_a[1])
	{
		r_a(s);
		s_a(s);
	}
	else if (s->stack_a[1] < s->stack_a[0] && s->stack_a[1] < s->stack_a[2])
		s_a(s);
	else if (s->stack_a[2] < s->stack_a[0] && s->stack_a[2] < s->stack_a[1])
	{
		rr_a(s);
		s_a(s);
	}
	else if (s->stack_a[2] < s->stack_a[1] && s->stack_a[2] > s->stack_a[0])
		rr_a(s);
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:28:28 by messalih          #+#    #+#             */
/*   Updated: 2022/05/21 11:28:36 by messalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	probability_five(t_stack *s, int i)
{
	if (i < 2)
	{
		if (i == 1)
		{
			rra(s);
			rra(s);
		}
		else
			rra(s);
	}
	else
	{
		if (i == 3)
			ra(s);
		if (i == 2)
		{
			ra(s);
			ra(s);
		}
	}
}

static	void	probability_five_1(t_stack *s, int i)
{
	if (i < 2)
	{
		if (i == 1)
		{
			rra(s);
			rra(s);
		}
		else
			rra(s);
	}
	else if (i == 2)
		ra(s);
}

static	void	check_if_1(t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->s_len - 1)
	{
		if (s->stack_index[i] == 1)
		{
			if (i != s->top_i - 1)
				probability_five_1(s, i);
			pb(s);
			break ;
		}
		i++;
	}
}

void	sort_5(t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->s_len)
	{
		if (s->stack_index[i] == 0)
		{
			if (i != s->top_i - 1)
				probability_five(s, i);
			pb(s);
			check_if_1(s);
			break ;
		}
		i++;
	}
	sort_3(s);
	pa(s);
	pa(s);
}

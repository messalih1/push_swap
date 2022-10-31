/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:28:46 by messalih          #+#    #+#             */
/*   Updated: 2022/05/21 11:28:54 by messalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	sort_list(t_stack *s, int max_bits, int i, int l)
{
	int	*j;

	j = ft_calloc(s->s_len, sizeof(int));
	if (j == NULL)
		return ;
	while (l < max_bits)
	{
		i = s->top_i;
		while (i--)
			j[i] = (s->stack_index[i] >> l) & 1;
		i = s->top_i;
		while (i--)
		{
			if (j[i] == 0)
				pb(s);
			else
				ra(s);
		}
		while (s->top_b != 0)
			pa(s);
		l++;
	}
	free(j);
}

void	sort(t_stack *s)
{
	int	max_num;
	int	max_bits;
	int	i;

	max_num = s->s_len - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		++max_bits;
	i = 0;
	sort_list(s, max_bits, i, 0);
}

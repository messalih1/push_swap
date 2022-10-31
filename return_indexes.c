/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_indexes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:27:47 by messalih          #+#    #+#             */
/*   Updated: 2022/05/21 11:27:55 by messalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n > 0)
	{
		*str++ = '\0';
		n--;
	}
}

static	void	swap_values(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	int				swapped;

	swapped = 1;
	while (swapped == 1)
	{
		i = 1;
		swapped = 0;
		while (i < size)
		{
			if (tab[i - 1] > tab[i])
			{
				swap_values(&tab[i - 1], &tab[i]);
				swapped = 1;
			}
			++i;
		}
	}
}

void	return_indexs(t_stack *s)
{
	int	i;
	int	x;

	x = 0;
	i = 0;
	while (i < s->s_len)
	{
		while (x < s->s_len)
		{
			if (s->stack_h[x] == s->stack_a[i])
			{
				push_to_stack_index(s, x);
				break ;
			}
			x++;
		}
		x = 0;
		i++;
	}
}

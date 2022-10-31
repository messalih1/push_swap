/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 10:56:56 by messalih          #+#    #+#             */
/*   Updated: 2022/05/21 11:05:48 by messalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_stack *s)
{
	if (s->s_len <= 3)
	{
		sort_3(s);
		ft_free_stacks(s);
	}
	else if (s->s_len <= 5)
	{
		sort_5(s);
		ft_free_stacks(s);
	}
	else
	{
		sort(s);
		ft_free_stacks(s);
	}
}

int	main(int ac, char **av)
{
	t_stack	t;
	t_stack	*s;

	s = &t;
	if (ac == 1)
		exit(0);
	if (handle_params(ac, av, s) == 0)
	{
		write(1, "error\n", 6);
		return (0);
	}
	return_indexs(s);
	sorting(s);
}

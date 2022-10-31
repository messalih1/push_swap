/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:24:28 by messalih          #+#    #+#             */
/*   Updated: 2022/05/21 11:24:39 by messalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alloc_args(int ac, char **av, t_stack *s)
{
	int	i;

	s->table = ft_calloc(sizeof(char *), ac);
	i = 0;
	while (i < ac)
	{
		s->table[i] = av[i + 1];
		i++;
	}
	s->table[i] = NULL;
}

void	free_split(t_stack *s)
{
	int	i;

	i = 0;
	while (s->split[i])
	{
		free(s->split[i]);
		i++;
	}
	free(s->split);
}

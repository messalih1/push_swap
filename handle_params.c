/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:09:12 by messalih          #+#    #+#             */
/*   Updated: 2022/05/21 11:24:07 by messalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (ft_isdigit(str[i]))
	{
		while (str[i])
		{
			if (!(str[i] >= '0' && str[i] <= '9'))
				return (0);
			i++;
		}
		return (1);
	}
	else
		return (0);
}

static	int	check_num(char **table, t_stack *s)
{
	int	i;

	i = 0;
	while (table[i])
	{
		if (ft_check(table[i]) == 0)
			return (0);
		i++;
	}
	s->s_len += i;
	return (1);
}

static int	check_espace(t_stack *s)
{
	int	j;
	int	i;

	i = 0;
	while (s->table[i])
	{
		j = 0;
		while (s->table[i][j] == ' ')
			j++;
		if (j == (int)ft_strlen(s->table[i]))
			return (0);
		i++;
	}
	return (1);
}

static	int	if_is_numeric(t_stack *s)
{
	int	i;

	s->s_len = 0;
	i = 0;
	if (check_espace(s) == 0)
		return (0);
	while (s->table[i])
	{
		s->split = ft_split(s->table[i], ' ');
		if (check_num(s->split, s) == 0)
		{
			free_split(s);
			return (0);
		}
		free_split(s);
		i++;
	}
	return (1);
}

int	handle_params(int ac, char **av, t_stack *s)
{
	int	i;

	s->s_len = 0;
	i = 0;
	alloc_args(ac, av, s);
	if (if_is_numeric(s) == 0)
	{
		free(s->table);
		return (0);
	}
	if (check_if_is_valid(s, 0, 0) == 0)
		return (0);
	free(s->table);
	return (1);
}

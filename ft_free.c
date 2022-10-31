/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:23:48 by messalih          #+#    #+#             */
/*   Updated: 2022/05/21 11:24:13 by messalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	free_table(t_stack *s)
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

void	ft_free_1(t_stack *s)
{
	free(s->stack_h);
	free(s->stack_a);
	free(s->stack_index);
}

void	ft_free_stacks(t_stack *s)
{
	free(s->stack_a);
	free(s->stack_h);
	free(s->stack_index);
	free(s->stack_i_b);
	free(s->stack_b);
}

void	*ft_calloc(size_t count, size_t size)
{
	void		*ptr;

	ptr = malloc(size * count);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

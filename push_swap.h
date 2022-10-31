/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:29:09 by messalih          #+#    #+#             */
/*   Updated: 2022/05/21 11:29:19 by messalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct stack{
	int		s_len;
	int		top_a;
	int		top_b;
	int		top_i;
	int		top_h;
	int		top_i_b;
	int		*stack_a;
	int		*stack_b;
	int		*stack_h;
	int		*stack_i_b;
	int		*stack_index;
	char	**split;
	char	**table;
	int		*table1;
	int		*table2;
}t_stack;

void	sort(t_stack *s);
void	sort_3(t_stack *s);
void	sort_5(t_stack *s);
void	sort_int_tab(int *tab, unsigned int size);
void	push_to_stack_index(t_stack *s, int data);
void	return_indexs(t_stack *s);
void	push_to_stack_i_b(t_stack *s, int data);
void	push_to_stack_h(t_stack *s, int data);
void	push_to_stack_a(t_stack *s, int data);
int		check_if_is_valid(t_stack *s, int i, int j);
void	push_to_stack_b(t_stack *s, int data);
int		handle_params(int ac, char **av, t_stack *s);
void	ft_free_stacks(t_stack *s);
void	sa(t_stack *s);
void	rra(t_stack *s);
void	ra(t_stack *s);
void	pb(t_stack *s);
void	pa(t_stack *s);
long	ft_atoi(char *str);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t count, size_t size);
void	free_split(t_stack *s);
void	alloc_args(int ac, char **av, t_stack *s);
#endif

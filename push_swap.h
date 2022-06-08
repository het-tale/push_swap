/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:43:15 by het-tale          #+#    #+#             */
/*   Updated: 2022/06/08 12:40:03 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

typedef struct s_list
{
	t_stack	*head;
	t_stack	*top;
}	t_list;

typedef struct s_vars
{
	int		key_nbr;
	int		*copy;
	int		key;
	int		*inter;
}	t_vars;

t_stack	*new_node(int data);
t_list	*new_list(void);
int		is_empty(t_list *stack);
void	swap_stack(t_list *a);
void	swap_stack_a(t_list *a);
void	swap_stack_b(t_list *b);
void	swap_two_stacks(t_list *a, t_list *b);
void	push_stack(t_list *stack, t_stack *n);
void	push_at_first(t_list *stack, t_stack *n);
void	pop_stack(t_list *stack);
t_stack	*remove_first(t_list *stack);
void	push_a(t_list *a, t_list *b);
void	push_b(t_list *a, t_list *b);
void	rotate(t_list *a);
void	rotate_a(t_list *a);
void	rotate_b(t_list *a);
void	rotate_two(t_list *a, t_list *b);
void	rev_rotate(t_list *a);
void	rev_rotate_a(t_list *a);
void	rev_rotate_b(t_list *b);
void	rev_rotate_two(t_list *a, t_list *b);
void	traverse_stack(t_list *stack);
int		ft_isinteger(char *s);
void	check_error(int argc, char *argv[]);
t_list	*get_stack(int argc, char *argv[], t_list *stack);
void	ft_is_duplicated(t_list *stack);
int		is_sorted(t_list *stack);
int		ft_only_one(t_list *stack);
t_list	*three_elements(t_list *a);
t_list	*five_element(t_list *a, t_list *b, int size);
int		get_min_index(t_list *a, t_stack *min);
t_stack	*get_min(t_list *a);
t_stack	*get_max(t_list *a);
int		*copy_stack(t_list *a, int *k);
int		lst_size(t_list *stack);
int		*bubble_sort(int *k, int size);
int		get_key_nbr(int *k, int size, int j);
void	sort_small_stack(t_list *stack_a, t_list *stack_b, int size_a);
t_list	*sort_100(t_list *a, t_list *b, int size, int chunk);
void	send_to_a(t_list *a, t_list *b, int size);
void	sort_a(t_list *a, t_list *b, int size);
void	rotate_conditions(t_list *a, t_list *b, int index, int size);
#endif

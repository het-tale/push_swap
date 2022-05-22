/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:43:15 by het-tale          #+#    #+#             */
/*   Updated: 2022/05/22 03:59:13 by het-tale         ###   ########.fr       */
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

#endif

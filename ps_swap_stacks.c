/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 23:31:08 by het-tale          #+#    #+#             */
/*   Updated: 2022/06/12 17:48:57 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_list *a)
{
	t_stack	*temp;
	t_stack	*parent;

	parent = NULL;
	temp = a->head;
	while (temp != NULL)
	{
		if (temp->next == a->top)
		{
			temp->next = NULL;
			a->top->next = temp;
			if (parent)
				parent->next = a->top;
			else
				a->head = a->top;
			a->top = temp;
			break ;
		}
		parent = temp;
		temp = temp->next;
	}
}

void	swap_stack_a(t_list *a)
{
	if (!is_empty(a) || !ft_only_one(a))
		swap_stack(a);
}

void	swap_stack_b(t_list *b)
{
	if (!is_empty(b) || !ft_only_one(b))
		swap_stack(b);
}

void	swap_two_stacks(t_list *a, t_list *b)
{
	if ((!is_empty(a) || !ft_only_one(a)) || (!is_empty(b) || !ft_only_one(b)))
	{
		swap_stack(a);
		swap_stack(b);
	}
}

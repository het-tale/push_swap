/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 23:31:08 by het-tale          #+#    #+#             */
/*   Updated: 2022/05/21 23:31:46 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_list *a)
{
	t_stack	*temp;

	temp = a->head;
	while (temp != NULL)
	{
		if (temp->next->next == a->top)
		{
			a->top->next = temp->next;
			temp->next->next = NULL;
			temp->next = a->top;
			break ;
		}
		temp = temp->next;
	}
}

void	swap_stack_a(t_list *a)
{
	swap_stack(a);
	write(1, "sa\n", 3);
}

void	swap_stack_b(t_list *b)
{
	swap_stack(b);
	write(1, "sb\n", 3);
}

void	swap_two_stacks(t_list *a, t_list *b)
{
	swap_stack(a);
	swap_stack(b);
	write(1, "ss\n", 3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 23:31:08 by het-tale          #+#    #+#             */
/*   Updated: 2022/05/24 22:25:31 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_list *a)
{
	t_stack	*temp;
	t_stack	*middle;

	temp = a->head;
	middle = temp->next;
	while (temp != NULL)
	{
		if (temp->next->next == a->top)
		{
			a->top->next = temp->next;
			temp->next->next = NULL;
			temp->next = a->top;
			a->top = middle;
			break ;
		}
		temp = temp->next;
	}
}

void	swap_stack_a(t_list *a)
{
	if (!is_empty(a) || !ft_only_one(a))
	{
		swap_stack(a);
		write(1, "sa\n", 3);
	}
}

void	swap_stack_b(t_list *b)
{
	if (!is_empty(b) || !ft_only_one(b))
	{
		swap_stack(b);
		write(1, "sb\n", 3);
	}
}

void	swap_two_stacks(t_list *a, t_list *b)
{
	if ((!is_empty(a) || !ft_only_one(a)) || (!is_empty(b) || !ft_only_one(b)))
	{
		swap_stack(a);
		swap_stack(b);
		write(1, "ss\n", 3);
	}
}

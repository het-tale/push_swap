/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 23:32:14 by het-tale          #+#    #+#             */
/*   Updated: 2022/05/21 23:32:51 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_list *stack, t_stack *n)
{
	if (is_empty(stack))
	{
		stack->head = n;
		stack->top = n;
	}
	else
	{
		stack->top->next = n;
		stack->top = n;
		n->next = NULL;
	}
}

void	push_at_first(t_list *stack, t_stack *n)
{
	if (is_empty(stack))
	{
		stack->head = n;
		stack->top = n;
	}
	else
	{
		n->next = stack->head;
		stack->head = n;
	}
}

void	pop_stack(t_list *stack)
{
	t_stack	*temp;

	temp = stack->head;
	while (temp != NULL)
	{
		if (temp->next == stack->top)
		{
			temp->next = NULL;
			stack->top = temp;
		}
		temp = temp->next;
	}
}

t_stack	*remove_first(t_list *stack)
{
	t_stack	*temp;

	temp = stack->head;
	stack->head = temp->next;
	return (temp);
}

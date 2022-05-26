/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 23:29:35 by het-tale          #+#    #+#             */
/*   Updated: 2022/05/26 18:28:22 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int data)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	node->data = data;
	node->next = NULL;
	return (node);
}

t_list	*new_list(void)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	list->head = NULL;
	list->top = NULL;
	return (list);
}

int	is_empty(t_list *stack)
{
	if (stack->top == NULL)
		return (1);
	return (0);
}

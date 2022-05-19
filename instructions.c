/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:19:43 by het-tale          #+#    #+#             */
/*   Updated: 2022/05/19 22:51:57 by het-tale         ###   ########.fr       */
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

t_list	*new_list()
{
	t_list *list;

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

void	swap_stack_a(t_list *a)
{
	t_stack *temp;

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
	write(1, "sa\n", 3);
}

void	swap_stack_b(t_list *b)
{
	t_stack *temp;

	temp = b->head;
	while (temp != NULL)
	{
		if (temp->next->next == b->top)
		{
			b->top->next = temp->next;
			temp->next->next = NULL;
			temp->next = b->top;
			break ;
		}
		temp = temp->next;
	}
	write(1, "sb\n", 3);
}

void	swap_two_stacks(t_list *a, t_list *b)
{
	swap_stack_a(a);
	swap_stack_b(b);
	write(1, "ss\n", 3);
}

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
void push_a(t_list *a, t_list *b)
{
	push_stack(a, b->top);
	pop_stack(b);
	write(1, "pa\n", 3);
}

void push_b(t_list *a, t_list *b)
{
	push_stack(b, a->top);
	pop_stack(a);
	write(1, "pb\n", 3);
}

void rotate_a(t_list *a)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = a->head;
	while (temp != NULL)
	{
		a->top->next = temp->next;
		temp->next->next = temp; 
		temp->next = NULL;
		a->top = temp;
		temp = temp->next;
	}
}

void	traverse_stack(t_list *stack)
{
	t_stack	*temp;

	temp = stack->head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	t_list *stack_a;
	t_list *stack_b;
	t_stack *n1;
	t_stack *n2;
	t_stack *n3;
	t_stack *temp;

	stack_a = new_list();
	stack_b = new_list();
	n1 = new_node(3);
	n2 = new_node(2);
	n3 = new_node(5);
	stack_a->head = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = NULL;
	stack_a->top = n3;
	traverse_stack(stack_a);
	//swap_stack_a(stack_a);
	//traverse_stack(stack_a);
	//push_a(stack_a, stack_b);
	//traverse_stack(stack_b);
	rotate_a(stack_a);
	traverse_stack(stack_a);
	return (0);
}

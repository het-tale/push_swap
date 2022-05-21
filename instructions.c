/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:19:43 by het-tale          #+#    #+#             */
/*   Updated: 2022/05/21 01:09:38 by het-tale         ###   ########.fr       */
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
void swap_two(t_list *a, t_stack *node1, t_stack *node2)
{
  t_stack *prev1 = NULL;
  t_stack *prev2 = NULL;
  t_stack *curr1 = a->head;
  t_stack *curr2 = a->head;
  while (curr1 && curr1 != node1)
  {
    prev1 = curr1;
    curr1 = curr1->next;
  }
   while (curr2 && curr2 != node2)
  {
    prev2 = curr2;
    curr2 = curr2->next;
  }
  if (prev1 != NULL)
        prev1->next = curr2;
    else // Else make y as new head
        a->head = curr2;
 
    // If y is not head of linked list
    if (prev2 != NULL)
        prev2->next = curr1;
    else // Else make x as new head
        a->head = curr1;
 
    // Swap next pointers
    t_stack *temp = curr2->next;
    curr2->next = curr1->next;
    curr1->next = temp;
  
}

void rotate(t_list *a)
{
    t_stack    *temp;
    t_stack    *temp2;

    temp = a->head;
    while (temp != NULL)
    {
        swap_two(a, temp, a->top);
        temp2 = a->top;
        a->top = temp;
        temp = temp2;
        temp = temp->next;
    }
}

void rotate_a(t_list *a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void rotate_b(t_list *a)
{
	rotate(a);
	write(1, "rb\n", 3);
}

void	rotate_two(t_list *a, t_list *b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
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
	//traverse_stack(stack_a);
	//swap_stack_a(stack_a);
	//traverse_stack(stack_a);
	//push_a(stack_a, stack_b);
	//traverse_stack(stack_b);
	rotate_two(stack_a, stack_a);
	traverse_stack(stack_a);
	return (0);
}

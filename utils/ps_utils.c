/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:19:43 by het-tale          #+#    #+#             */
/*   Updated: 2022/05/21 23:29:42 by het-tale         ###   ########.fr       */
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

void	push_a(t_list *a, t_list *b)
{
	push_stack(a, b->top);
	pop_stack(b);
	write(1, "pa\n", 3);
}

void	push_b(t_list *a, t_list *b)
{
	push_stack(b, a->top);
	pop_stack(a);
	write(1, "pb\n", 3);
}

void	rotate(t_list *a)
{
	push_at_first(a, a->top);
	pop_stack(a);
}

void	rotate_a(t_list *a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_list *a)
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

void	rev_rotate(t_list *a)
{
	t_stack	*temp;

	temp = remove_first(a);
	push_stack(a, temp);
}

void	rev_rotate_a(t_list *a)
{
	rev_rotate(a);
	write(1, "rra\n", 4);
}

void	rev_rotate_b(t_list *b)
{
	rev_rotate(b);
	write(1, "rrb\n", 4);
}

void	rev_rotate_two(t_list *a, t_list *b)
{
	rev_rotate(a);
	rev_rotate(b);
	write(1, "rrr\n", 4);
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

/*int main()
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
	//rotate_a(stack_a);
	//remove_first(stack_a);
	rev_rotate_a(stack_a);
	traverse_stack(stack_a);
	return (0);
}*/

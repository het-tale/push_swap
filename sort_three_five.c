/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:24:10 by het-tale          #+#    #+#             */
/*   Updated: 2022/06/12 18:02:07 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

t_stack	*get_min(t_list *a)
{
	int		min;
	t_stack	*temp;
	t_stack	*small;

	min = a->head->data;
	temp = a->head->next;
	small = a->head;
	while (temp != NULL)
	{
		if (temp->data < min)
		{
			min = temp->data;
			small = temp;
		}
		temp = temp->next;
	}
	return (small);
}

int	get_min_index(t_list *a, t_stack *min)
{
	int		index;
	t_stack	*temp;

	index = 0;
	temp = a->head;
	while (temp != NULL)
	{
		if (min->data == temp->data)
			break ;
		index++;
		temp = temp->next;
	}
	return (index);
}

t_list	*three_elements(t_list *a)
{
	if (a->top->data > a->head->next->data
		&& a->head->next->data < a->head->data && a->head->data > a->top->data)
	{
		swap_stack_a(a);
		print_inst("sa\n");
	}
	else if (a->top->data > a->head->next->data
		&& a->head->next->data > a->head->data && a->top->data > a->head->data)
	{
		swap_stack_a(a);
		print_inst("sa\n");
		rev_rotate_a(a);
		print_inst("rra\n");
	}
	else if (a->top->data > a->head->next->data
		&& a->head->next->data < a->head->data && a->top->data > a->head->data)
	{
		rotate_a(a);
		print_inst("ra\n");
	}
	else if (a->top->data < a->head->next->data
		&& a->head->next->data > a->head->data && a->head->data > a->top->data)
	{
		swap_stack_a(a);
		print_inst("sa\n");
		rotate_a(a);
		print_inst("ra\n");
	}
	else
	{
		rev_rotate_a(a);
		print_inst("rra\n");
	}
	return (a);
}

static void	rotate_boucle(t_list *a, int size, int index, int i)
{
	if (size / 2 > index)
	{
		while (i < index + 1)
		{
			rev_rotate_a(a);
			print_inst("rra\n");
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < size - index - 1)
		{
			rotate_a(a);
			print_inst("ra\n");
			i++;
		}
	}
}

t_list	*five_element(t_list *a, t_list *b, int size)
{
	t_stack	*min;
	int		index;
	int		i;
	int		j;
	int		loop;

	j = 0;
	loop = size - 3;
	while (j < loop)
	{
		min = get_min(a);
		index = get_min_index(a, min);
		i = 0;
		rotate_boucle(a, size, index, i);
		push_b(a, b);
		print_inst("pb\n");
		size--;
		j++;
	}
	if (!is_sorted(a))
		three_elements(a);
	j = 0;
	while (j++ < loop)
	{
		push_a(a, b);
		print_inst("pa\n");
	}
	return (a);
}

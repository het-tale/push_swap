/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 20:10:26 by het-tale          #+#    #+#             */
/*   Updated: 2022/05/25 23:05:50 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

t_list	*three_elements(t_list *a)
{
	if (a->top->data > a->head->next->data
		&& a->head->next->data < a->head->data && a->head->data > a->top->data)
		swap_stack_a(a);
	else if (a->top->data > a->head->next->data
		&& a->head->next->data > a->head->data && a->top->data > a->head->data)
	{
		swap_stack_a(a);
		rev_rotate_a(a);
	}
	else if (a->top->data > a->head->next->data
		&& a->head->next->data < a->head->data && a->top->data > a->head->data)
		rotate_a(a);
	else if (a->top->data < a->head->next->data
		&& a->head->next->data > a->head->data && a->head->data > a->top->data)
	{
		swap_stack_a(a);
		rotate_a(a);
	}
	else
		rev_rotate_a(a);
	return (a);
}

t_list	*five_elements(t_list *a, t_list *b, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	push_b(a, b);
	push_b(a, b);
	if (!is_sorted(a))
		three_elements(a);
	while (j < 2)
	{
		if (b->top->data < a->top->data)
			push_a(a, b);
		else
		{
			if (b->top->data < a->head->next->data)
			{
				push_a(a, b);
				swap_stack_a(a);
			}
			else
			{
				if (b->top->data < a->head->data)
				{
					i = 0;
					push_a(a, b);
					while (i < size)
					{
						rotate_a(a);
						i++;
					}
					i = 0;
					swap_stack_a(a);
					while (i < size - 1)
					{
						rotate_a(a);
						i++;
					}
				}
				else
				{
					push_a(a, b);
					rotate_a(a);
				}
			}
		}
		j++;
	}
	return (a);
}

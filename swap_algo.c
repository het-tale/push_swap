/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 20:10:26 by het-tale          #+#    #+#             */
/*   Updated: 2022/05/27 01:27:14 by het-tale         ###   ########.fr       */
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

void	conditions(t_list *a, t_list *b, int size, int *d)
{
	if (size == 5)
		push_b(a, b);
	else
		*d = 1;
	if (!is_sorted(a))
		three_elements(a);
}

t_list	*five_elements(t_list *a, t_list *b, int size)
{
	int	i;
	int	j;
	int	d;

	j = 0;
	d = 0;
	push_b(a, b);
	conditions(a, b, size, &d);
	while (j < (size / 2) - d)
	{
		if (b->top->data < a->top->data)
			push_a(a, b);
		else if (b->top->data < a->head->next->next->data)
		{
			push_a(a, b);
			swap_stack_a(a);
		}
		else if (b->top->data < a->head->next->data)
		{
			i = 0;
			while (i < (size / 2) + j - 1)
			{
				rotate_a(a);
				i++;
			}
			push_a(a, b);
			i = 0;
			while (i < (size / 2) + j - 1)
			{
				rev_rotate_a(a);
				i++;
			}
		}
		else if (b->top->data < a->head->data)
		{
			rev_rotate_a(a);
			push_a(a, b);
			i = 0;
			while (i < (size / 2))
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
		j++;
	}
	return (a);
}

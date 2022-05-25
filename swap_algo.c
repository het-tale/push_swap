/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 20:10:26 by het-tale          #+#    #+#             */
/*   Updated: 2022/05/25 03:16:16 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

t_list	*three_elements(t_list *a, t_list *b)
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

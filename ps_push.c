/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 23:36:36 by het-tale          #+#    #+#             */
/*   Updated: 2022/05/23 22:47:04 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list *a, t_list *b)
{
	if (!is_empty(b))
	{
		push_stack(a, b->top);
		pop_stack(b);
		write(1, "pa\n", 3);
	}
}

void	push_b(t_list *a, t_list *b)
{
	if (!is_empty(a))
	{
		push_stack(b, a->top);
		pop_stack(a);
		write(1, "pb\n", 3);
	}
}

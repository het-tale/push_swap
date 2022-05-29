/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 23:33:40 by het-tale          #+#    #+#             */
/*   Updated: 2022/05/29 20:29:13 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list *a)
{
	t_stack	*top;

	top = a->top;
	pop_stack(a);
	push_at_first(a, top);
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

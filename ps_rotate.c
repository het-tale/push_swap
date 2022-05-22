/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 23:33:40 by het-tale          #+#    #+#             */
/*   Updated: 2022/05/21 23:35:40 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

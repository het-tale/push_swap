/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 23:37:16 by het-tale          #+#    #+#             */
/*   Updated: 2022/05/31 07:48:03 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_list *a)
{
	t_stack	*temp;

	temp = remove_first(a);
	push_stack(a, temp);
}

void	rev_rotate_a(t_list *a)
{
	if (ft_only_one(a))
		return ;
	rev_rotate(a);
	write(1, "rra\n", 4);
}

void	rev_rotate_b(t_list *b)
{
	if (ft_only_one(b))
		return ;
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

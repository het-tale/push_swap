/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 21:09:15 by het-tale          #+#    #+#             */
/*   Updated: 2022/06/06 01:52:39 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

t_stack	*get_max(t_list *a)
{
	int		max;
	t_stack	*temp;
	t_stack	*big;

	max = a->head->data;
	temp = a->head->next;
	big = a->head;
	while (temp != NULL)
	{
		if (temp->data > max)
		{
			max = temp->data;
			big = temp;
		}
		temp = temp->next;
	}
	return (big);
}

void	rotate_conditions(t_list *a, t_list *b, int index, int size)
{
	int	i;

	i = 0;
	if (size / 2 > index)
	{
		i = 0;
		while (i < index + 1)
		{
			rev_rotate_b(b);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < size - index - 1)
		{
			rotate_b(b);
			i++;
		}
	}
	push_a(a, b);
}

int	*interval(int key_nbr, int *copy, int size)
{
	int	start;
	int	end;
	int	*inter;
	int	mid;

	mid = size / 2;
	inter = malloc(2 * sizeof(int));
	if (mid - key_nbr < 0)
			start = copy[0];
	else
		start = copy[mid - key_nbr];
	if (mid + key_nbr > size - 1)
		end = copy[size - 1];
	else
		end = copy[mid + key_nbr];
	inter[0] = start;
	inter[1] = end;
	return (inter);
}

void	send_to_b(t_list *a, t_list *b, t_vars vars, int size)
{
	while (lst_size(b) < 2 * vars.key_nbr)
	{
		if (a->top->data >= vars.inter[0]
			&& a->top->data <= vars.inter[1])
		{
			push_b(a, b);
			if (b->top->data < vars.copy[size / 2])
				rotate_b(b);
		}
		else
			rotate_a(a);
	}
}

t_list	*sort_100(t_list *a, t_list *b, int size)
{
	t_vars	vars;

	vars.copy = malloc(size * sizeof(int));
	vars.copy = copy_stack(a, vars.copy);
	vars.copy = bubble_sort(vars.copy, size);
	vars.key_nbr = size / 8;
	vars.key = vars.key_nbr;
	while (!is_empty(a))
	{
		vars.inter = interval(vars.key_nbr, vars.copy, size);
		if (size / 2 - vars.key_nbr < 0 && size / 2 + vars.key_nbr > size - 1)
		{
			while (!is_empty(a))
			{
				push_b(a, b);
				if (b->top->data < vars.copy[size / 2])
					rotate_b(b);
			}
			break ;
		}
		send_to_b(a, b, vars, size);
		vars.key_nbr += vars.key;
	}
	send_to_a(a, b, lst_size(b));
	return (a);
}

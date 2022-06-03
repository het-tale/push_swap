/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 21:09:15 by het-tale          #+#    #+#             */
/*   Updated: 2022/06/03 22:42:10 by het-tale         ###   ########.fr       */
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

void	send_to_a(t_list *a, t_list *b, int size)
{
	t_stack	*max;
	int		index;
	int		j;
	int		s;

	j = 0;
	s = size;
	while (j < s)
	{
		max = get_max(b);
		index = get_min_index(b, max);
		if (b->top->data == max->data)
			push_a(a, b);
		else if (max->next->data == b->top->data)
		{
			swap_stack_b(b);
			push_a(a, b);
		}
		else
			rotate_conditions(a, b, index, size);
		size--;
		j++;
		if (is_empty(b))
			break ;
	}
}

t_list	*sort_100(t_list *a, t_list *b, int size)
{
	int		key_nbr;
	int		*copy;
	int		start;
	int		end;
	int		key;

	copy = malloc(size * sizeof(int));
	copy = copy_stack(a, copy);
	copy = bubble_sort(copy, size);
	key_nbr = size / 8;
	key = key_nbr;
	while (!is_empty(a))
	{
		if (size / 2 - key_nbr < 0)
			start = copy[0];
		else
			start = copy[size / 2 - key_nbr];
		if (size / 2 + key_nbr > size - 1)
			end = copy[size - 1];
		else
			end = copy[size / 2 + key_nbr];
		if (size / 2 - key_nbr < 0 && size / 2 + key_nbr > size - 1)
		{
			while (!is_empty(a))
			{
				push_b(a, b);
				if (b->top->data < copy[size / 2])
					rotate_b(b);
			}
			break ;
		}
		while (lst_size(b) < 2 * key_nbr)
		{
			is_exist(b, a->top, copy, start, end, a);
			if (a->top->data >= start && a->top->data <= end)
			{
				push_b(a, b);
				if (b->top->data < copy[size / 2])
					rotate_b(b);
			}
			else
				rotate_a(a);
		}
		key_nbr += key;
	}
	send_to_a(a, b, lst_size(b));
	return (a);
}

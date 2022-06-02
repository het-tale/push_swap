/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 21:09:15 by het-tale          #+#    #+#             */
/*   Updated: 2022/06/02 04:28:10 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	send_to_b(t_list *a, t_list *b, int key_nbr, int size)
{
	t_stack	*temp;
	t_stack	*tmp;
	int		index;
	int		i;
	int		j;
	int		s;

	temp = a->head;
	tmp = a->head;
	index = 0;
	i = 0;
	j = 0;
	s = size;
	while (j < s && temp)
	{
		if (temp->data <= key_nbr)
		{
			index = get_min_index(a, temp);
			if (index < size / 2)
			{
				i = 0;
				while (i < index + 1)
				{
					rev_rotate_a(a);
					i++;
				}
			}
			else
			{
				i = 0;
				while (i < size - index - 1)
				{
					rotate_a(a);
					i++;
				}
			}
			push_b(a, b);
			tmp = a->head;
			size--;
		}
		else
			tmp = temp->next;
		temp = temp->next;	
		temp = tmp;
		j++;
	}
}

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

void	send_to_a(t_list *a, t_list *b, int size)
{
	t_stack	*max;
	int		i;
	int		index;
	int		j;
	int		s;

	i = 0;
	j = 0;
	s = size;
	while (j < s)
	{
		max = get_max(b);
		index = get_min_index(b, max);
		if (b->top->data == max->data)
			push_a(a, b);
		else
		{
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
		size--;
		j++;
		if (is_empty(b))
			break ;
	}
}

void sort_a(t_list *a, t_list *b, int size)
{
	t_stack	*min;
	int		j;
	int		s;
	int		index;
	int		i;

	j = 0;
	index = 0;
	s = size;
	i = 0;
	while (j < s)
	{
		min = get_min(a);
		index = get_min_index(a, min);
		if (a->top->data == min->data)
			push_b(a, b);
		else
		{
			if (size / 2 > index)
			{
				i = 0;
				while (i < index + 1)
				{
					rev_rotate_a(a);
					i++;
				}
			}
			else
			{
				i = 0;
				while (i < size - index - 1)
				{
					rotate_a(a);
					i++;
				}
			}
			push_b(a, b);
		}
		size--;
		j++;
		if (is_empty(a))
			break ;
	}
}

t_list	*sort_100(t_list *a, t_list *b, int size)
{
	int		key_nbr;
	int		*copy;
	int		i;
	int		k;
	t_list	*stack_b;
	int		s;

	i = 0;
	k = 1;
	s = size;
	stack_b = new_list();
	copy = malloc(size * sizeof(int));
	copy = copy_stack(a, copy);
	copy = bubble_sort(copy, s);
	while (i < 3)
	{
		key_nbr = get_key_nbr(copy, s, k);
		k++;
		send_to_b(a, b, key_nbr, s);
		i++;
	}
	size = lst_size(a);
	sort_a(a, b, size);
	send_to_a(a, b, lst_size(b));
	return (a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_algo_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:24:10 by het-tale          #+#    #+#             */
/*   Updated: 2022/05/27 19:09:05 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

t_stack	*get_min(t_list *a)
{
	int	min;
	int	index;
	t_stack	*temp;
	t_stack	*small;

	index = 0;
	min = a->head->data;
	temp = a->head->next;
	small = a->head;
	while (temp != NULL)
	{
		if (temp->data < min)
		{
			min = temp->data;
			small = temp;
		}
		temp = temp->next;
	}
	return (small);
}

int	get_min_index(t_list *a, t_stack *min)
{
	int	index;
	t_stack	*temp;

	index = 0;
	temp = a->head;
	while (temp != NULL)
	{
		if (min->data == temp->data)
			break ;
		index++;
		temp = temp->next;
	}
	return (index);
}
t_list	*five_element(t_list *a, t_list *b, int size)
{
	t_stack	*min;
	int	index;
	int	i;
	int	j;

	j = 0;
	while (j < 2)
	{
		min = get_min(a);
		index = get_min_index(a, min);
		i = 0;
		if (size / 2 > index)
		{
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
		size--;
		j++;
	}
	if (!is_sorted(a))
		three_elements(a);
	push_a(a, b);
	push_a(a, b);
	return (a);
}
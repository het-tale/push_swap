/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 02:23:05 by het-tale          #+#    #+#             */
/*   Updated: 2022/06/12 15:20:03 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	*copy_stack(t_list *a, int *k)
{
	t_stack	*temp;
	int		i;

	temp = a->head;
	i = 0;
	while (temp != NULL)
	{
		k[i] = temp->data;
		temp = temp->next;
		i++;
	}
	return (k);
}

int	*bubble_sort(int *k, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (k[j] > k[j + 1])
				swap(&k[j], &k[j + 1]);
			j++;
		}
		i++;
	}
	return (k);
}

int	get_key_nbr(int *k, int size, int j)
{
	int	key_nbr;
	int	index;
	int	i;

	index = (size * j) / 4;
	i = 0;
	key_nbr = 0;
	if (index == size)
		index--;
	while (i < size)
	{
		if (index == i)
		{
			key_nbr = k[i];
			break ;
		}
		i++;
	}
	return (key_nbr);
}

int	get_index(t_list *a, int min)
{
	int		index;
	t_stack	*temp;

	index = 0;
	temp = a->head;
	while (temp != NULL)
	{
		if (min == temp->data)
			return (index);
		index++;
		temp = temp->next;
	}
	index = -1;
	return (index);
}

void	send_to_a(t_list *a, t_list *b, int size, t_vars vars)
{
	int		in;
	int		index;
	int		j;

	j = 0;
	in = 0;
	index = size - 1;
	while (index >= 0)
	{
		if (b->top && b->top->data == vars.copy[index])
		{
			push_a(a, b);
			index--;
			size--;
		}
		else if (a->head && j != 0 && a->head->data == vars.copy[index])
		{
			rev_rotate_a(a);
			j--;
			index--;
		}
		else if (j == 0 ||
			(b->top && a->head && b->top->data > a->head->data && j != 0))
		{
			push_a(a, b);
			rotate_a(a);
			j++;
			size--;
		}
		else
		{
			in = get_index(b, vars.copy[index]);
			if (in < lst_size(b) / 2)
			{
				while (b->top->data != vars.copy[index])
					rev_rotate_b(b);
				push_a(a, b);
				size--;
				index--;
			}
			else
			{
				while (b->top->data != vars.copy[index])
					rotate_b(b);
				push_a(a, b);
				size--;
				index--;			
			}
		}
	}
}
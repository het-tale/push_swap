/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 02:23:05 by het-tale          #+#    #+#             */
/*   Updated: 2022/06/13 11:37:09 by het-tale         ###   ########.fr       */
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
	t_ind	ind;

	ind.j = 0;
	ind.in = 0;
	ind.index = size - 1;
	while (ind.index >= 0)
	{
		if (check_conditions(a, b, &ind, vars) == 1)
			b_rotation(a, b, &ind, vars);
	}
}

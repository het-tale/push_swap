/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 02:23:05 by het-tale          #+#    #+#             */
/*   Updated: 2022/06/02 04:20:53 by het-tale         ###   ########.fr       */
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
	
  while(i < size)
  {
	j = 0;
    while (j < size-i-1)
	{
		if (k[j] > k[j+1])
			swap(&k[j], &k[j+1]);
		j++;
    }
	i++;
  }
  return(k);
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
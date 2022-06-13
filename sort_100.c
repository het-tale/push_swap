/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 21:09:15 by het-tale          #+#    #+#             */
/*   Updated: 2022/06/13 11:01:33 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

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
			print_inst("rrb\n");
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < size - index - 1)
		{
			rotate_b(b);
			print_inst("rb\n");
			i++;
		}
	}
	push_a(a, b);
	print_inst("pa\n");
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
	while (lst_size(b) < (2 * vars.key_nbr) - vars.index)
	{
		if (check_max_three(a, &vars, size) == 0)
		{
			if (a->top->data >= vars.inter[0]
				&& a->top->data <= vars.inter[1])
			{
				push_b(a, b);
				print_inst("pb\n");
				if (b->top->data < vars.copy[size / 2])
				{
					rotate_b(b);
					print_inst("rb\n");
				}
			}
			else
			{
				rotate_a(a);
				print_inst("ra\n");
			}
		}
	}
}

void	sort_and_send(t_list *a, t_list *b, t_vars vars)
{
	if (!is_sorted(a))
		three_elements(a);
	send_to_a(a, b, lst_size(b), vars);
	free(vars.copy);
}

t_list	*sort_100(t_list *a, t_list *b, int size, int chunk)
{
	t_vars	vars;

	get_copy_stack(a, &vars, size, chunk);
	while (lst_size(a) > 3)
	{
		vars.inter = interval(vars.key_nbr, vars.copy, size);
		if (size / 2 - vars.key_nbr < 0 && size / 2 + vars.key_nbr > size - 1)
		{
			if (check_max_three(a, &vars, size) == 0)
			{
				push_b(a, b);
				print_inst("pb\n");
				if (b->top->data < vars.copy[size / 2])
				{
					rotate_b(b);
					print_inst("rb\n");
				}
			}
		}
		send_to_b(a, b, vars, size);
		vars.key_nbr += vars.key;
		free(vars.inter);
	}
	sort_and_send(a, b, vars);
	return (a);
}

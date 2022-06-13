/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack_utils2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:01:13 by het-tale          #+#    #+#             */
/*   Updated: 2022/06/13 11:57:46 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	check_max_three(t_list *a, t_vars *vars, int size)
{
	int	d;

	d = 0;
	if (a->top->data >= vars->copy[size - 3]
		&& a->top->data <= vars->copy[size - 1]
		&& (a->top->data >= vars->inter[0] && a->top->data <= vars->inter[1]))
			vars->index++;
	if (a->top->data >= vars->copy[size - 3]
		&& a->top->data <= vars->copy[size - 1])
	{
		rotate_a(a);
		print_inst("ra\n");
		d = 1;
	}
	return (d);
}

void	b_rotation(t_list *a, t_list *b, t_ind *ind, t_vars vars)
{
	ind->in = get_index(b, vars.copy[ind->index]);
	if (ind->in < lst_size(b) / 2)
	{
		while (b->top->data != vars.copy[ind->index])
		{
			rev_rotate_b(b);
			print_inst("rrb\n");
		}
		push_a(a, b);
		print_inst("pa\n");
		ind->index--;
	}
	else
	{
		while (b->top->data != vars.copy[ind->index])
		{
			rotate_b(b);
			print_inst("rb\n");
		}
		push_a(a, b);
		print_inst("pa\n");
		ind->index--;
	}
}

int	check_conditions(t_list *a, t_list *b, t_ind *ind, t_vars vars)
{
	if (b->top && b->top->data == vars.copy[ind->index])
	{
		push_a(a, b);
		print_inst("pa\n");
		ind->index--;
	}
	else if (a->head && ind->j != 0 && a->head->data == vars.copy[ind->index])
	{
		rev_rotate_a(a);
		print_inst("rra\n");
		ind->j--;
		ind->index--;
	}
	else if (ind->j == 0
		|| (b->top && a->head && b->top->data > a->head->data && ind->j != 0))
	{
		push_a(a, b);
		print_inst("pa\n");
		rotate_a(a);
		print_inst("ra\n");
		ind->j++;
	}
	else
		return (1);
	return (0);
}

void	instructions(t_list *a, int d)
{
	if (d == 0)
	{
		swap_stack_a(a);
		print_inst("sa\n");
	}
	else if (d == 1)
	{
		swap_stack_a(a);
		print_inst("sa\n");
		rev_rotate_a(a);
		print_inst("rra\n");
	}
	else if (d == 2)
	{
		rotate_a(a);
		print_inst("ra\n");
	}
	else if (d == 3)
	{
		swap_stack_a(a);
		print_inst("sa\n");
		rotate_a(a);
		print_inst("ra\n");
	}
}

void	sort_push_5(t_list *a, t_list *b, int loop)
{
	int	j;

	j = 0;
	if (!is_sorted(a))
		three_elements(a);
	while (j++ < loop)
	{
		push_a(a, b);
		print_inst("pa\n");
	}
}

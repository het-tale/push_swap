/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 15:39:51 by het-tale          #+#    #+#             */
/*   Updated: 2022/06/14 11:47:28 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	compare_instruction(char *instruction, t_list *a, t_list *b)
{
	if (ft_strcmp(instruction, "sa\n") == 0)
		swap_stack_a(a);
	else if (ft_strcmp(instruction, "sp\n") == 0)
		swap_stack_b(b);
	else if (ft_strcmp(instruction, "ss\n") == 0)
		swap_two_stacks(a, b);
	else if (ft_strcmp(instruction, "pa\n") == 0)
		push_a(a, b);
	else if (ft_strcmp(instruction, "pb\n") == 0)
		push_b(a, b);
	else if (ft_strcmp(instruction, "ra\n") == 0)
		rotate_a(a);
	else if (ft_strcmp(instruction, "rb\n") == 0)
		rotate_b(b);
	else if (ft_strcmp(instruction, "rr\n") == 0)
		rotate_two(a, b);
	else if (ft_strcmp(instruction, "rra\n") == 0)
		rev_rotate_a(a);
	else if (ft_strcmp(instruction, "rrb\n") == 0)
		rev_rotate_b(b);
	else if (ft_strcmp(instruction, "rrr\n") == 0)
		rev_rotate_two(a, b);
	else
		ft_error();
}

int	main(int argc, char *argv[])
{
	char	*instruction;
	t_list	*a;
	t_list	*b;

	a = new_list();
	b = new_list();
	if (argc > 1)
	{
		check_error(argc, argv);
		a = get_stack(argc, argv, a);
		ft_is_duplicated(a);
		instruction = get_next_line(0);
		while (instruction)
		{
			free(instruction);
			compare_instruction(instruction, a, b);
			instruction = get_next_line(0);
		}
		if (is_sorted(a) && is_empty(b))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	return (0);
}

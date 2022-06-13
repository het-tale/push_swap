/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 03:40:53 by het-tale          #+#    #+#             */
/*   Updated: 2022/06/13 12:12:29 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	ft_free(t_list *stack)
{
	t_stack	*temp;

	while (stack->head)
	{
		temp = stack->head;
		stack->head = stack->head->next;
		free(temp);
	}
}

void	sort_small_stack(t_list *stack_a, t_list *stack_b, int size_a)
{
	if (size_a == 2)
	{
		swap_stack_a(stack_a);
		print_inst("sa\n");
	}
	else if (size_a == 3)
		stack_a = three_elements(stack_a);
	else if (size_a >= 4 && size_a <= 10)
		stack_a = five_element(stack_a, stack_b, size_a);
}

void	sort_big_stack(t_list *stack_a, t_list *stack_b, int size_a)
{
	int	chunk;

	chunk = 0;
	if (size_a > 10 && size_a <= 100)
	{
		chunk = size_a / 8;
		sort_100(stack_a, stack_b, size_a, chunk);
	}
	else
	{
		chunk = size_a / 18;
		sort_100(stack_a, stack_b, size_a, chunk);
	}
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size_a;

	stack_a = new_list();
	stack_b = new_list();
	if (argc > 1)
	{
		check_error(argc, argv);
		stack_a = get_stack(argc, argv, stack_a);
		ft_is_duplicated(stack_a);
		size_a = lst_size(stack_a);
		if (!is_sorted(stack_a) && !is_empty(stack_a) && !ft_only_one(stack_a))
		{
			if (size_a >= 2 && size_a <= 10)
				sort_small_stack(stack_a, stack_b, size_a);
			else
				sort_big_stack(stack_a, stack_b, size_a);
		}
	}
	ft_free(stack_a);
	free(stack_a);
	ft_free(stack_b);
	free(stack_b);
	return (0);
}

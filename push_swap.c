/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 03:40:53 by het-tale          #+#    #+#             */
/*   Updated: 2022/05/25 03:18:28 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

t_list	*get_stack(int argc, char *argv[], t_list *stack)
{
	int		i;
	int		j;
	char	**split;
	int		atoi;
	t_stack	*temp;

	j = 1;
	while (j < argc)
	{
		split = ft_split(argv[j], ' ');
		i = 0;
		while (split[i])
		{
			atoi = ft_atoi(split[i]);
			temp = new_node(atoi);
			push_at_first(stack, temp);
			free(split[i]);
			i++;
		}
		j++;
		free(split);
	}
	return (stack);
}

void	ft_free(t_list *stack)
{
	t_stack	*temp;

	temp = stack->head;
	while (temp != NULL)
	{
		free(temp);
		temp = temp->next;
	}
}

int	lst_size(t_list *stack)
{
	int		size;
	t_stack	*temp;

	temp = stack->head;
	size = 0;
	while (temp != NULL)
	{
		size++;
		temp = temp->next;
	}
	return (size);
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
			if (size_a == 3)
				stack_a = three_elements(stack_a, stack_b);
		}
		traverse_stack(stack_a);
	}
	ft_free(stack_a);
	free(stack_a);
	return (0);
}

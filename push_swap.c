/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 03:40:53 by het-tale          #+#    #+#             */
/*   Updated: 2022/05/23 02:14:10 by het-tale         ###   ########.fr       */
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
			i++;
		}
		j++;
	}
	return (stack);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = new_list();
	stack_b = new_list();
	if (argc > 1)
	{
		check_error(argc, argv);
		stack_a = get_stack(argc, argv, stack_a);
		ft_is_duplicated(stack_a);
		if (!is_sorted(stack_a) && !is_empty(stack_a) && !ft_only_one(stack_a))
		{
			printf("NONE OF THE ABOVE\n");
		}
		traverse_stack(stack_a);
	}
	return (0);
}

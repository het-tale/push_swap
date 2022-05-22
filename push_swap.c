/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 03:40:53 by het-tale          #+#    #+#             */
/*   Updated: 2022/05/22 18:54:15 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	ft_isinteger(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_error(int argc, char *argv[])
{
	int		j;
	int		i;
	char	**split;

	j = 1;
	while (j < argc)
	{
		split = ft_split(argv[j], ' ');
		i = 0;
		while (split[i])
		{
			if (!ft_isinteger(split[i]) || ft_atoi(split[i]) == -2)
			{
				write(2, "Error\n", 6);
				exit(0);
			}
			i++;
		}
		j++;
	}
}

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
 
void	ft_is_duplicated(t_list *stack)
{
	t_stack	*temp;
	t_stack *temp2;

	temp2 = stack->head;
	while (temp2 != NULL)
	{
		temp = temp2->next;
		while (temp != NULL)
		{
			if (temp->data == temp2->data)
			{
				write(2, "Error\n", 6);
				exit(0);
			}
			temp = temp->next;
		}
		temp2 = temp2->next;
	}
}

int	is_sorted(t_list *stack)
{
	t_stack	*temp;

	temp = stack->head;
	while (temp->next != NULL)
	{
		if (temp->data < temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int ft_only_one(t_list *stack)
{
	if (stack->head == stack->top)
		return (1);
	return (0);
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
		traverse_stack(stack_a);
		if (!is_sorted(stack_a) || !is_empty(stack_a) || !ft_only_one(stack_a))
		{
			printf("NONE OF THE ABOVE\n");
		}
	}
	return (0);
}

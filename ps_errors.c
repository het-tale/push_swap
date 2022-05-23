/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 19:35:46 by het-tale          #+#    #+#             */
/*   Updated: 2022/05/23 23:18:44 by het-tale         ###   ########.fr       */
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
		if (s[i] == '-')
			i++;
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
			if (!ft_isinteger(split[i]))
			{
				write(2, "Error\n", 6);
				exit(0);
			}
			free(split[i]);
			i++;
		}
		j++;
		free(split);
	}
}

void	ft_is_duplicated(t_list *stack)
{
	t_stack	*temp;
	t_stack	*temp2;

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
	if (is_empty(stack))
		return (0);
	while (temp->next != NULL)
	{
		if (temp->data < temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	ft_only_one(t_list *stack)
{
	if (stack->head == stack->top)
		return (1);
	return (0);
}

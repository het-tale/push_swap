/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 17:24:23 by het-tale          #+#    #+#             */
/*   Updated: 2022/06/12 17:45:26 by het-tale         ###   ########.fr       */
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

void	print_inst(char *instruction)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(instruction);
	i = 0;
	while (i < len)
	{
		write(1, &instruction[i], 1);
		i++;
	}
}
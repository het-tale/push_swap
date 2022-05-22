/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 03:40:53 by het-tale          #+#    #+#             */
/*   Updated: 2022/05/22 04:54:31 by het-tale         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	char **split;
	int	i;
	int	j;
	int	atoi;

	j = 1;
	if (argc > 1)
	{
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
				i++;
			}
			i = 0;
			while (split[i])
			{
				atoi = ft_atoi(split[i]);
				printf("%d\n", atoi);
				i++;
			}
			j++;
		}
	}
	return (0);
}

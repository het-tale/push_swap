/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:03:17 by het-tale          #+#    #+#             */
/*   Updated: 2022/06/14 00:46:50 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_isspace(const char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v')
		i++;
	return (i);
}

void	ft_error2(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				d;
	unsigned long	res;

	i = 0;
	d = 1;
	res = 0;
	i = ft_isspace(str, i);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			d = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + (str[i] - 48);
		if (res > 2147483647)
			ft_error2();
		i++;
	}
	return ((int)res * d);
}

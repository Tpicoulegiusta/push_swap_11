/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:22:41 by tpicoule          #+#    #+#             */
/*   Updated: 2023/03/31 16:26:40 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str)
{
	long	i;
	long	result;
	long	signe;

	result = 0;
	i = 0;
	signe = 1;
	while (is_space(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] && ft_isdigit(str[i + 1]) != 1)
			return (3000000000);
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result *= 10;
		result += (str[i] - 48);
		i++;
	}
	return (result * signe);
}

int	ft_isdigit(int i)
{
	if ((i >= '0' && i <= '9'))
	{
		return (1);
	}
	return (0);
}

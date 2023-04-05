/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instrct_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:14:51 by tpicoule          #+#    #+#             */
/*   Updated: 2023/04/04 10:52:11 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_smallest(t_dblist *pilea)
{
	t_node	*node;
	int		tmp;
	int		i;

	i = 0;
	node = pilea->top;
	tmp = pilea->top->value;
	while (i < pilea->length)
	{
		if (tmp >= node->value)
			tmp = node->value;
		node = node->next;
		i++;
	}
	return (tmp);
}

void	ft_smallest_at_2(t_dblist *pilea, t_dblist *pileb)
{
	ft_ra(pilea);
	ft_ra(pilea);
	ft_pb(pilea, pileb);
}

void	ft_smallest_at_3(t_dblist *pilea, t_dblist *pileb)
{
	ft_rra(pilea);
	ft_rra(pilea);
	ft_pb(pilea, pileb);
}

int	ft_find_biggest(t_dblist *pileb)
{
	int		i;
	int		tmp;
	t_node	*node;

	i = 0;
	tmp = pileb->top->value;
	node = pileb->top;
	while (i < pileb->length)
	{
		if (node->value >= tmp)
			tmp = node->value;
		node = node->next;
		i++;
	}
	return (tmp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_number_100.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:48:21 by tpicoule          #+#    #+#             */
/*   Updated: 2023/03/31 15:50:07 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_chunk(t_dblist *pilea, t_dblist *pileb, int chunksize)
{
	int	tmp;
	int	i;
	int	j;
	int	k;
	int	l;

	if (pilea->top == NULL)
		return ;
	l = pilea->length;
	i = 1;
	k = ft_find_smallest(pilea);
	while (i < chunksize)
	{
		j = ft_find_next_smallest(pilea, k);
		k = j;
		i++;
	}
	i = 0;
	while (i < chunksize && !ft_is_empty(pilea))
	{
		tmp = pilea->top->value;
		if (tmp <= j)
		{
			ft_pb(pilea, pileb);
			i++;
		}
		else
			ft_ra(pilea);
	}
}

void	ft_sort(t_dblist *pilea, t_dblist *pileb, int chunksize)
{
	int i;

	while (pilea->length > 0)
		ft_chunk(pilea, pileb, chunksize);
	while (pileb->length != 0)
	{
		i = ft_find_index(pileb, ft_find_biggest(pileb));
		if (i >= pileb->length / 2)
		{
			i = pileb->length - i;
			while (i-- > 0)
				ft_rrb(pileb);
		}
		else
		{
			while (i-- > 0)
				ft_rb(pileb);
		}
		ft_pa(pilea, pileb);
	}
}

int	ft_find_index(t_dblist *pilea, int value)
{
	int		i;
	int		tmp;
	t_node	*node;

	node = pilea->top;
	tmp = pilea->top->value;
	i = 0;
	while (i != pilea->length)
	{
		if (tmp == value)
			return (i);
		if (node->next != NULL)
		{
			node = node->next;
			tmp = node->value;
		}
		i++;
	}
	return (-1);
}

int	ft_find_next_smallest(t_dblist *pilea, int smallest)
{
	t_node	*node;
	int		tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	node = pilea->top;
	tmp = INT_MAX;
	while (i < pilea->length)
	{
		if (tmp > node->value && node->value > smallest)
		{
			tmp = node->value;
			j = i;
		}
		node = node->next;
		i++;
	}
	return (tmp);
}
	
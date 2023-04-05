/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:39:43 by tpicoule          #+#    #+#             */
/*   Updated: 2023/04/05 09:17:14 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dblist	*ft_two(t_dblist *pilea)
{
	if (pilea->top->value > pilea->bot->value)
		ft_swap_a(pilea->top, pilea->top->next);
	return (pilea);
}

t_dblist	*ft_tree(t_dblist *pilea)
{
	int	first;
	int	mid;
	int	last;

	first = pilea->top->value;
	mid = pilea->top->next->value;
	last = pilea->bot->value;
	if (first > mid && mid < last && last > first)
		ft_swap_a(pilea->top, pilea->top->next);
	else if (first > mid && mid > last && last < first)
	{
		ft_swap_a(pilea->top, pilea->top->next);
		ft_rra(pilea);
	}
	else if (first > mid && mid < last && last < first)
		ft_ra(pilea);
	else if (first < mid && mid > last && last > first)
	{
		ft_swap_a(pilea->top, pilea->top->next);
		ft_ra(pilea);
	}
	else if (first < mid && mid > last && last < first)
		ft_rra(pilea);
	return (pilea);
}

t_dblist	*ft_five(t_dblist *pilea, t_dblist *pileb)
{
	int	i;

	if (!pileb)
		return (pilea);
	while (pilea->length != 3)
	{
		i = ft_find_index(pilea, ft_find_smallest(pilea));
		if (i == 0)
			ft_pb(pilea, pileb);
		else if (i == 1)
			ft_sa_pb(pilea, pileb);
		else if (i == 2)
			ft_smallest_at_2(pilea, pileb);
		else if (i == 3 && pilea->length == 5)
			ft_smallest_at_3(pilea, pileb);
		else if (i == 4 || i == 3)
		{
			ft_rra(pilea);
			ft_pb(pilea, pileb);
		}
	}
	ft_tree(pilea);
	ft_pa_pa(pilea, pileb);
	return (pilea);
}

void	ft_pa_pa(t_dblist *pilea, t_dblist *pileb)
{
	if (pileb->length == 2)
	{
		ft_pa(pilea, pileb);
		ft_pa(pilea, pileb);
	}
	else
		ft_pa(pilea, pileb);
}

void	ft_sa_pb(t_dblist *pilea, t_dblist *pileb)
{
	ft_swap_a(pilea->top, pilea->top->next);
	ft_pb(pilea, pileb);
}

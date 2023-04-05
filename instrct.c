/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instrct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:38:27 by tpicoule          #+#    #+#             */
/*   Updated: 2023/04/04 11:31:31 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_node *a, t_node *b)
{
	int	tmp;

	if (!a || !b)
		return ;
	tmp = a->value;
	a->value = b->value;
	b->value = tmp;
	write(1, "sa\n", 3);
}

void	ft_pa(t_dblist *pilea, t_dblist *pileb)
{
	if (!pileb || ft_is_empty(pileb))
		return ;
	pilea = ft_add_top(pilea, pileb->top->value);
	pileb = ft_del_top_list(pileb);
	write(1, "pa\n", 3);
}

void	ft_pb(t_dblist *pilea, t_dblist *pileb)
{
	if (!pilea || ft_is_empty(pilea))
		return ;
	pileb = ft_add_top(pileb, pilea->top->value);
	pilea = ft_del_top_list(pilea);
	write(1, "pb\n", 3);
}

void	ft_ra(t_dblist *pilea)
{
	if (!pilea || ft_is_empty(pilea))
		return ;
	ft_add_bot(pilea, pilea->top->value);
	ft_del_top_list(pilea);
	write(1, "ra\n", 3);
}

void	ft_rb(t_dblist *pileb)
{
	if (!pileb || ft_is_empty(pileb))
		return ;
	ft_add_bot(pileb, pileb->top->value);
	ft_del_top_list(pileb);
	write(1, "rb\n", 3);
}

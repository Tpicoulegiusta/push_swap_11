/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:56:56 by tpicoule          #+#    #+#             */
/*   Updated: 2023/04/05 15:47:02 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			i;
	t_dblist	*pilea;
	t_dblist	*pileb;

	if (ft_return_check(argc, argv) != 0)
		return (0);
	if (argc <= 2)
		return (0);
	i = 1;
	pilea = dlist_new();
	pileb = dlist_new();
	while (argv[i])
	{
		pilea = ft_add_bot(pilea, ft_atoi(argv[i]));
		i++;
	}
	if (ft_order(pilea) != 0)
		return (0);
	ft_algo(argc, pilea, pileb);
	ft_free_pile(pileb);
	ft_free_pile(pilea);
	// system("leaks push_swap");
	return (0);
}

int	ft_algo(int argc, t_dblist *pilea, t_dblist *pileb)
{
	if (argc == 3)
		ft_two(pilea);
	else if (argc == 4)
		ft_tree(pilea);
	else if (argc == 5 || argc == 6)
		ft_five(pilea, pileb);
	else if (pilea->length <= 100)
		ft_sort(pilea, pileb, 18);
	else if (pilea->length <= 500)
		ft_sort(pilea, pileb, 50);
	else if (pilea->length > 500)
		ft_sort(pilea, pileb, 50);
	//system("leaks a.out");
	return (0);
}

void	ft_free_pile(t_dblist *pilea)
{
	t_node	*node;
	t_node	*next;

	node = pilea->top;
	while (node != NULL)
	{
		next = node->next;
		free(node);
		node = next;
	}
	free(pilea);
}

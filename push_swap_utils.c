/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:00:49 by tpicoule          #+#    #+#             */
/*   Updated: 2023/04/04 11:28:26 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dblist	*dlist_new(void)
{
	t_dblist	*new;

	new = malloc(sizeof(t_dblist));
	if (!new)
		return (NULL);
	if (new != NULL)
	{
		new->length = 0;
		new->top = NULL;
		new->bot = NULL;
	}
	return (new);
}

t_dblist	*ft_add_bot(t_dblist *list, int value)
{
	struct s_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	new->prev = NULL;
	if (list->top == NULL)
	{
		list->length = 0;
		list->top = new;
		list->bot = new;
	}
	else
	{
		list->bot->next = new;
		new->prev = list->bot;
		list->bot = new;
	}
	list->length++;
	return (list);
}

t_dblist	*ft_add_top(t_dblist *list, int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new || !list)
		return (NULL);
	new->value = value;
	new->next = NULL;
	new->prev = NULL;
	if (list->top == NULL)
	{
		list->length = 0;
		list->top = new;
		list->bot = new;
	}
	else
	{
		list->top->prev = new;
		new->next = list->top;
		list->top = new;
	}
	list->length++;
	return (list);
}

void	ft_print_pile(t_dblist *list)
{
	t_node	*tmp;

	if (!list || !list->top || !list->bot || list == NULL)
	{
		puts("liste vide\n");
		return ;
	}
	tmp = list->top;
	while (tmp)
	{
		printf("[%d]\n", tmp->value);
		tmp = tmp->next;
	}
}

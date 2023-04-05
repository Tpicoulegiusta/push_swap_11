/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:52:17 by tpicoule          #+#    #+#             */
/*   Updated: 2023/04/05 14:13:38 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;
	int	signe;

	result = 0;
	i = 0;
	signe = 1;
	while (is_space(str[i]) == 1)
		i++;
	if (str[i] == '-')
	{
		signe *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		result *= 10;
		result += (str[i] - 48);
		i++;
	}
	return (result * signe);
}

int	ft_is_empty(t_dblist *list)
{
	if (!list->bot && !list->top)
		return (1);
	return (0);
}

t_dblist	*ft_del_bot_list(t_dblist *list)
{
	t_node	*tmp;

	if (!list || ft_is_empty(list))
		return (NULL);
	if (list->top == list->bot)
	{
		free(list->bot);
		list->top = NULL;
		list->bot = NULL;
		list->length = 0;
		return (list);
	}
	tmp = list->bot;
	list->bot = list->bot->prev;
	list->bot->next = NULL;
	tmp->next = NULL;
	tmp->prev = NULL;
	free(tmp);
	tmp = NULL;
	list->length--;
	return (list);
}

t_dblist	*ft_del_top_list(t_dblist *list)
{
	t_node	*tmp;

	if (!list || ft_is_empty(list))
		return (NULL);
	if (list->top == list->bot)
	{
		free(list->top);
		list->bot = NULL;
		list->top = NULL;
		list->length = 0;
		return (list);
	}
	tmp = list->top;
	list->top = list->top->next;
	list->top->prev = NULL;
	tmp->next = NULL;
	tmp->prev = NULL;
	free(tmp);
	tmp = NULL;
	list->length--;
	return (list);
}

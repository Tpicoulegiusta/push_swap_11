/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:59:30 by tpicoule          #+#    #+#             */
/*   Updated: 2023/04/05 14:13:16 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;

}	t_node;

typedef struct s_dblist
{
	int				length;
	struct s_node	*top;
	struct s_node	*bot;
}	t_dblist;

t_dblist	*dlist_new(void);
t_dblist	*ft_add_top(t_dblist *list, int value);
t_dblist	*ft_add_bot(t_dblist *list, int value);
void		ft_swap_a(t_node *a, t_node *b);
int			is_space(char c);
int			ft_atoi(char *str);
long		ft_atol(char *str);
void		ft_print_pile(t_dblist *list);
t_dblist	*ft_del_bot_list(t_dblist *list);
t_dblist	*ft_del_top_list(t_dblist *list);
void		ft_pa(t_dblist *pilea, t_dblist *pileb);
void		ft_pb(t_dblist *pilea, t_dblist *pileb);
void		ft_ra(t_dblist *pilea);
void		ft_rb(t_dblist *pileb);
void		ft_rra(t_dblist *pilea);
void		ft_rrb(t_dblist *pileb);
t_dblist	*ft_two(t_dblist *pilea);
t_dblist	*ft_tree(t_dblist *pilea);
t_dblist	*ft_five(t_dblist *pilea, t_dblist *pileb);
int			ft_find_smallest(t_dblist *pilea);
void		ft_smallest_at_2(t_dblist *pilea, t_dblist *pileb);
void		ft_smallest_at_3(t_dblist *pilea, t_dblist *pileb);
char		**ft_split(char *s, char c);
char		**ft_countj(char **tabtab, char *s, char c);
size_t		ft_counti(char *s, char c);
int			ft_check_args(char **argv);
char		*ft_substr(char *s, int start, int end);
int			ft_check_args_2(int argc, char **argv);
void		ft_pa_pa(t_dblist *pilea, t_dblist *pileb);
int			ft_isdigit(int i);
int			ft_check_args_3(char **argv);
int			ft_find_next_smallest(t_dblist *pilea, int smallest);
int			ft_find_index(t_dblist *pilea, int value);
void		ft_sort(t_dblist *pilea, t_dblist *pileb, int chunksize);
int			ft_is_empty(t_dblist *list);
int			ft_find_biggest(t_dblist *pileb);
int			ft_algo(int argc, t_dblist *pilea, t_dblist *pileb);
void		ft_free_pile(t_dblist *pilea);
int			ft_return_check(int argc, char **argv);
void		ft_sa_pb(t_dblist *pilea, t_dblist *pileb);
int			ft_order(t_dblist *pilea);

#endif
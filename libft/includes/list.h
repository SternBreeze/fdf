/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:15:31 by jjacobso          #+#    #+#             */
/*   Updated: 2019/04/19 20:23:44 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H

# define LIST_H

typedef struct				s_list
{
	void					*data;
	struct s_list			*next;
	struct s_list			*prev;
}							t_list;

t_list						*l_create(void *data, t_list *prev);
int							ld_push_back(t_list **l, void *data);
int							ld_push_front(t_list **l, void *data);
int							l_push_front(t_list **l, t_list *e);
int							l_push_back(t_list **l, t_list *e);
void						*l_get_data(t_list **l, int n);
int							l_destroy(t_list **l);
size_t						l_size(t_list *l);
int							l_int_find(t_list *l, int t);
t_list						*l_pop_front(t_list **l);
t_list						*l_pop_back(t_list **l);
int							l_int_min(t_list *l);
int							l_int_max(t_list *l);
int							l_int_sort(t_list *l);
size_t						l_int_positon(t_list *l, int e);
void						l_remove(t_list **cur);
t_list						*l_last(t_list *l);
t_list						*l_copy(t_list *a);
void						l_reverse(t_list **l);
#endif

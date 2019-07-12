/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:15:31 by jjacobso          #+#    #+#             */
/*   Updated: 2018/12/24 15:19:40 by jjacobso         ###   ########.fr       */
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
int							l_push_back(t_list **l, void *data);
int							l_push_front(t_list **l, void *data);
void						*l_get_data(t_list **l, int n);
int							l_destroy(t_list **l);
int							l_size(t_list *l);
#endif

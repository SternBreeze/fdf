/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmors-um <gmors-um@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:15:38 by jjacobso          #+#    #+#             */
/*   Updated: 2018/12/25 21:13:37 by gmors-um         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list						*l_create(void *data, t_list *prev)
{
	t_list					*lst;

	if (!(lst = (t_list*)malloc(sizeof(t_list))))
		return ((t_list*)ft_ptr_free(&data));
	lst->next = NULL;
	lst->prev = prev;
	lst->data = data;
	return (lst);
}

int							l_push_back(t_list **l, void *data)
{
	t_list					*t;

	if (!l || !data)
		return (0);
	if (!*l)
		return ((*l = l_create(data, NULL)) != NULL);
	t = *l;
	while (t->next)
		t = t->next;
	if (!(t->next = l_create(data, t)))
		return (0);
	return (1);
}

int							l_push_front(t_list **l, void *data)
{
	t_list					*t;

	if (!l || !data)
		return (0);
	if (!*l)
		return ((*l = l_create(data, NULL)) != NULL);
	t = *l;
	*l = l_create(data, NULL);
	(*l)->next = t;
	return (1);
}

void						*l_get_data(t_list **l, int n)
{
	t_list					*t;

	if (!l || !*l || n <= 0)
		return (NULL);
	t = *l;
	while (n-- >= 0 && t)
		t = t->next;
	return (t->data);
}

int							l_destroy(t_list **l)
{
	if (!l)
		return (0);
	if (!*l)
		return (1);
	free((*l)->data);
	return (l_destroy(&(*l)->next) && ft_int_free((void**)l, 1));
}

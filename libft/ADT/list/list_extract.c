/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_extract.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 18:31:59 by jjacobso          #+#    #+#             */
/*   Updated: 2019/02/19 16:12:58 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list						*l_pop_front(t_list **l)
{
	t_list					*res;

	if (!l || !*l)
		return (NULL);
	res = *l;
	*l = (*l)->next;
	res->next = NULL;
	return (res);
}

t_list						*l_pop_back(t_list **l)
{
	t_list					*res;
	t_list					*prev;

	if (!l || !*l)
		return (NULL);
	res = *l;
	prev = 0;
	while (res->next)
	{
		prev = res;
		res = res->next;
	}
	if (!prev)
	{
		*l = 0;
		return (res);
	}
	prev->next = 0;
	res->next = NULL;
	return (res);
}

void						*l_get_data(t_list **l, int n)
{
	t_list					*t;

	if (!l || !*l || n < 0)
		return (NULL);
	t = *l;
	while (n-- >= 0 && t)
		t = t->next;
	if (n > 0)
		return (NULL);
	return (t->data);
}

void						l_remove(t_list **cur)
{
	t_list					*b;
	t_list					*prev;

	prev = (*cur)->prev;
	if (!prev)
	{
		b = (*cur)->next;
		ft_memdel((void **)&(*cur)->data);
		ft_memdel((void **)cur);
		*cur = b;
		b ? (*cur)->prev = 0 : b;
	}
	else
	{
		b = (*cur)->next;
		prev->next = b;
		ft_memdel((void **)&(*cur)->data);
		ft_memdel((void **)cur);
		*cur = prev;
		if (b)
		{
			*cur = b;
			(*cur)->prev = prev;
		}
	}
}

int							l_destroy(t_list **l)
{
	t_list					*b;

	if (!l)
		return (0);
	if (!*l)
		return (1);
	while (*l)
	{
		b = *l;
		*l = (*l)->next;
		ft_memdel((void **)&b->data);
		ft_memdel((void **)&b);
	}
	*l = NULL;
	return (1);
}

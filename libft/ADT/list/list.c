/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:15:38 by jjacobso          #+#    #+#             */
/*   Updated: 2019/04/22 19:27:40 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t						l_size(t_list *lst)
{
	size_t					res;

	res = 0;
	while (lst)
	{
		res++;
		lst = lst->next;
	}
	return (res);
}

t_list						*l_last(t_list *l)
{
	while (l->next)
		l = l->next;
	return (l);
}

void						l_reverse(t_list **l)
{
	t_list					*t;
	t_list					*next;

	t = *l;
	while (t)
	{
		next = t->next;
		t->next = t->prev;
		if (next)
			t = next;
		else
			break ;
	}
	*l = t;
}

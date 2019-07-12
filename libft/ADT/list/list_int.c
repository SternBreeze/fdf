/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 15:48:13 by jjacobso          #+#    #+#             */
/*   Updated: 2019/02/08 18:49:55 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int							l_int_find(t_list *l, int t)
{
	if (!l)
		return (0);
	while (l)
	{
		if (*(int *)l->data == t)
			return (1);
		l = l->next;
	}
	return (0);
}

int							l_int_min(t_list *l)
{
	int						min;

	if (!l)
		return (INT_MAX);
	min = *(int *)l->data;
	while (l)
	{
		if (min > *(int *)l->data)
			min = *(int *)l->data;
		l = l->next;
	}
	return (min);
}

int							l_int_max(t_list *l)
{
	int						max;

	if (!l)
		return (INT_MAX);
	max = *(int *)l->data;
	while (l)
	{
		if (max < *(int *)l->data)
			max = *(int *)l->data;
		l = l->next;
	}
	return (max);
}

size_t						l_int_positon(t_list *l, int e)
{
	int				i;

	i = 0;
	while (l)
	{
		if (*(int *)l->data == e)
			return (i);
		i++;
		l = l->next;
	}
	return (0);
}

t_list						*l_copy(t_list *a)
{
	t_list					*res;

	res = 0;
	while (a)
	{
		ld_push_back(&res, ft_int_get_mass(*(int *)a->data));
		a = a->next;
	}
	return (res);
}

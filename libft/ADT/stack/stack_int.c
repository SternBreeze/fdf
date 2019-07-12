/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 20:04:48 by jjacobso          #+#    #+#             */
/*   Updated: 2019/02/08 18:41:00 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					s_int_find(t_stack *s, int t)
{
	size_t			i;

	if (!s || s->size == 0)
		return (0);
	i = 0;
	while (i < s->size)
	{
		if (*(int *)s->body[i] == t)
			return (1);
		i++;
	}
	return (0);
}

int					s_int_min(t_stack *s, size_t *pos)
{
	size_t			size;
	int				e;

	*pos = 0;
	if (s_is_empty(s))
		return (0);
	e = *(int *)s->body[0];
	size = s->size;
	while (--size > 0)
		e = *(int *)s->body[size] < e ? *(int *)s->body[size] : e;
	*pos = size;
	return (e);
}

int					s_int_max(t_stack *s)
{
	size_t			size;
	int				e;

	if (s_is_empty(s))
		return (0);
	e = *(int *)s->body[0];
	size = s->size;
	while (--size > 0)
		e = *(int *)s->body[size] > e ? *(int *)s->body[size] : e;
	return (e);
}

ssize_t				s_int_positon(t_stack *s, int e)
{
	ssize_t			size;

	if (s_is_empty(s))
		return (-1);
	size = s->size;
	while (--size >= 0)
		if (*(int *)s->body[size] == e)
			return (size + 1);
	return (-1);
}

size_t				s_size(t_stack *s)
{
	return (s->size);
}

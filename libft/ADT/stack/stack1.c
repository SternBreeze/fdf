/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 20:52:12 by jjacobso          #+#    #+#             */
/*   Updated: 2019/05/16 21:00:34 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					s_reverse(t_stack *s)
{
	size_t			i;
	size_t			size;
	void			*b;

	size = s_size(s);
	if (size != 0)
		size--;
	i = 0;
	while (i < size)
	{
		b = s->body[i];
		s->body[i] = s->body[size];
		s->body[size] = b;
		i++;
		size--;
	}
	return (1);
}

t_stack				*s_copy(t_stack *s, void *(*copy_data)(void *))
{
	t_stack			*res;
	size_t			i;

	if (!s_init(&res))
		return (NULL);
	i = 0;
	while (i < s->size)
	{
		if (!(s_push(res, copy_data(s->body[i]))))
			return (NULL);
		i++;
	}
	return (res);
}

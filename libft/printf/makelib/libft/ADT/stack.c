/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:57:53 by jjacobso          #+#    #+#             */
/*   Updated: 2018/12/12 17:40:36 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				s_init(t_stack **s)
{
	if (!(*s = (t_stack*)malloc(sizeof(t_stack))))
		return (0);
	(*s)->size = 0;
	(*s)->max_size = 6;
	if (!((*s)->body = (void**)ft_malloc((*s)->max_size * sizeof(void*))))
		return (0);
	return (1);
}

int				s_is_empty(t_stack *s)
{
	if (!s)
		return (1);
	return (s->size <= 0);
}

void			*s_pop(t_stack *s)
{
	void		*res;

	res = NULL;
	if (s && !s_is_empty(s))
	{
		res = s->body[s->size - 1];
		s->size--;
		if (s->size * 2 <= s->max_size)
		{
			s->max_size /= 2;
			if (!(s->body = (void**)ft_realloc(s->body, s->max_size
												* sizeof(void*))))
				return (NULL);
		}
	}
	return (res);
}

int				s_push(t_stack *s, void *data)
{
	if (!s || !s || !data)
		return (0);
	if (s->size >= s->max_size)
	{
		s->max_size = 1.5 * s->max_size + 1;
		if (!(s->body = (void**)ft_realloc(s->body,
			s->max_size * sizeof(void*))))
			return (0);
	}
	s->body[s->size] = data;
	s->size++;
	return (1);
}

int				s_destroy(t_stack **s)
{
	ft_free((*s)->body);
	free(*s);
	*s = NULL;
	return (1);
}

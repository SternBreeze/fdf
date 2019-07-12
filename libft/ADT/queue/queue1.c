/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 20:48:31 by jjacobso          #+#    #+#             */
/*   Updated: 2019/05/16 20:44:23 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					q_reverse(t_queue *q)
{
	return (s_reverse(q->in) && s_reverse(q->out));
}

t_queue				*q_copy(t_queue *q, void *(*copy_data)(void *))
{
	t_queue			*res;

	if (!(res = (t_queue *)malloc(sizeof(t_queue))))
		return (NULL);
	if (!(res->in = s_copy(q->in, copy_data)))
		return (NULL);
	if (!(res->out = s_copy(q->out, copy_data)))
		return (NULL);
	return (res);
}

int					q_size(t_queue *q)
{
	return (s_size(q->in) + s_size(q->out));
}

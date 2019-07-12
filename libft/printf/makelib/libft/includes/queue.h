/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 10:35:28 by jjacobso          #+#    #+#             */
/*   Updated: 2018/12/12 17:51:48 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H

# define QUEUE_H

# include "stack.h"

typedef struct		s_queue
{
	t_stack			*in;
	t_stack			*out;
}					t_queue;

int					q_init(t_queue **q);
int					q_is_empty(t_queue *q);
void				*q_pop(t_queue *q);
int					q_push(t_queue *q, void *data);
int					q_destroy(t_queue **q);
#endif

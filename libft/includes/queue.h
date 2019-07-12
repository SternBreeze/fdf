/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 10:35:28 by jjacobso          #+#    #+#             */
/*   Updated: 2019/05/16 20:44:31 by jjacobso         ###   ########.fr       */
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
t_queue				*q_copy(t_queue *q, void *(*copy_data)(void *));
int					q_destroy(t_queue **q);
int					q_reverse(t_queue *q);
int					q_size(t_queue *q);
/*
**					carefull with ft_realloc
*/
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:57:14 by jjacobso          #+#    #+#             */
/*   Updated: 2019/01/27 18:56:25 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H

# define STACK_H

typedef struct		s_stack
{
	size_t			size;
	size_t			max_size;
	void			**body;
}					t_stack;

int					s_init(t_stack **s);
int					s_is_empty(t_stack *s);
void				*s_pop(t_stack *s);
int					s_push(t_stack *s, void *data);
int					s_destroy(t_stack **s);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:57:14 by jjacobso          #+#    #+#             */
/*   Updated: 2019/04/22 21:24:27 by jjacobso         ###   ########.fr       */
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
int					s_int_find(t_stack *s, int t);
int					s_int_min(t_stack *s, size_t *pos);
int					s_int_max(t_stack *s);
ssize_t				s_int_positon(t_stack *s, int e);
size_t				s_size(t_stack *s);
int					s_destroy(t_stack **s);
int					s_reverse(t_stack *s);
t_stack				*s_copy(t_stack *s, void *(*copy_data)(void *));
/*
**					carefull with ft_realloc
*/
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_int2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 13:55:40 by jjacobso          #+#    #+#             */
/*   Updated: 2019/04/15 20:22:39 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			l_int_sort(t_list *l)
{
	t_list	*t;
	int		*b;
	int		stop;

	stop = 0;
	if (!l)
		return (0);
	while (!stop)
	{
		t = l;
		stop = 1;
		while (t && t->next)
		{
			if (*(int *)t->data > *(int *)t->next->data)
			{
				b = t->data;
				t->data = t->next->data;
				t->next->data = b;
				stop = 0;
			}
			t = t->next;
		}
	}
	return (1);
}

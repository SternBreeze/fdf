/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 19:47:34 by jjacobso          #+#    #+#             */
/*   Updated: 2018/12/10 21:17:35 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** malloc and free for ft_realloc
** ft_malloc also save size of allocated memory before pointer
** ft_free free this type of pointers
*/

void		*ft_malloc(size_t size)
{
	size_t	*res;

	if (!(res = malloc(size + sizeof(size_t))))
		return (NULL);
	*res = size;
	return (res + 1);
}

int			ft_free(void *ptr)
{
	free((size_t*)ptr - 1);
	return (1);
}

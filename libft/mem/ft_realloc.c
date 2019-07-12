/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 16:37:38 by jjacobso          #+#    #+#             */
/*   Updated: 2019/04/23 17:07:45 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 	dont work without ft_malloc and ft_free
*/

static size_t	ft_mem_size(void *p)
{
	return (((size_t *)p)[-1]);
}

void			*ft_realloc(void *ptr, size_t newsize)
{
	char		*p;

	if (!ptr)
		return (ft_malloc(newsize));
	if (ft_mem_size(ptr) >= newsize)
		return (ptr);
	if (!(p = (char*)ft_malloc(newsize)))
		return (NULL);
	ft_memcpy(p, ptr, ft_mem_size(ptr) > newsize ? newsize : ft_mem_size(ptr));
	ft_free(ptr);
	return (p);
}

/*
**	realization without ft_free/ft_malloc
*/

void			*ft_frealloc(void *ptr, size_t size, size_t newsize)
{
	char		*p;

	if (!ptr)
		return (malloc(newsize));
	if (!(p = (char*)malloc(newsize)))
		return (NULL);
	ft_memcpy(p, ptr, (size < newsize) ? size : newsize);
	free(ptr);
	return (p);
}

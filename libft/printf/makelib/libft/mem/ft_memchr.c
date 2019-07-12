/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:44:47 by jjacobso          #+#    #+#             */
/*   Updated: 2018/11/26 16:38:06 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	const char *s;

	s = src;
	while (n--)
		if (*(unsigned char*)s++ == (unsigned char)c)
			return ((void*)(s - 1));
	return (NULL);
}

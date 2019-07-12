/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 20:32:53 by jjacobso          #+#    #+#             */
/*   Updated: 2018/11/26 16:37:24 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dest, const void *src, int c, size_t len)
{
	char			*d;
	const char		*s;

	d = dest;
	s = src;
	while (len--)
		if ((unsigned char)(*d++ = *s++) == (unsigned char)c)
			return ((void*)d);
	return (NULL);
}

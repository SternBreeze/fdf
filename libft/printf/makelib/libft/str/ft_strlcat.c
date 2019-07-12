/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:40:39 by jjacobso          #+#    #+#             */
/*   Updated: 2018/11/26 15:58:50 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(char *s, size_t len)
{
	size_t		l;

	l = 0;
	while (*s && l < len)
	{
		s++;
		l++;
	}
	return (l);
}

size_t			ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t		dlen;
	size_t		slen;

	slen = ft_strlen((char*)src);
	dlen = ft_strnlen(dst, len);
	if (dlen == len)
		return (dlen + slen);
	if (slen + dlen < len)
	{
		ft_memcpy(dst + dlen, src, slen + 1);
		dst[dlen + slen] = '\0';
	}
	else
	{
		ft_memcpy(dst + dlen, src, len - dlen - 1);
		dst[len - 1] = '\0';
	}
	return (dlen + slen);
}

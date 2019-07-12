/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:05:15 by jjacobso          #+#    #+#             */
/*   Updated: 2018/11/26 15:09:56 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strncpy(char *dst, const char *src, size_t len)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	while (len--)
		if (*s)
			*d++ = *s++;
		else
			*d++ = '\0';
	return (dst);
}

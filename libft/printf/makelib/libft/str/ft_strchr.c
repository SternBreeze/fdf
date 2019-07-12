/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:49:42 by jjacobso          #+#    #+#             */
/*   Updated: 2019/01/21 16:57:11 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strchr(const char *src, int c)
{
	const char	*s;

	s = src;
	if (c == '\0')
		return (NULL);
	if (s == NULL || *s == (char)c)
		return ((char*)s);
	while (*s)
		if (*++s == (char)c)
			return ((char*)s);
	return (NULL);
}

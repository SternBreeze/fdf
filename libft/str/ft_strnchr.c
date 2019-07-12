/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:55:39 by jjacobso          #+#    #+#             */
/*   Updated: 2019/01/21 17:14:16 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnchr(const char *src, int c, int n)
{
	const char	*s;

	s = src;
	if (c == '\0' || n <= 0)
		return (NULL);
	if (s == NULL || *s == (char)c)
		return ((char*)s);
	while (*s && n--)
		if (*++s == (char)c)
			return ((char*)s);
	return (NULL);
}

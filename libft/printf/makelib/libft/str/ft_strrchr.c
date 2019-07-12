/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:09:02 by jjacobso          #+#    #+#             */
/*   Updated: 2018/11/22 17:45:35 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *src, int c)
{
	char	*s;
	char	*res;

	s = (char*)src;
	res = 0;
	while (*s)
	{
		if (*s == (char)c)
			res = s;
		s++;
	}
	if (c == '\0')
		return (s);
	return ((res == 0) ? 0 : res);
}

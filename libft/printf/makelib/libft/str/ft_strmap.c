/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 10:03:32 by jjacobso          #+#    #+#             */
/*   Updated: 2018/11/26 17:48:32 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f) (char))
{
	char	*res;
	char	*r;

	if (!s)
		return (NULL);
	if (!(res = ft_strnew(ft_strlen(s))))
		return (NULL);
	r = res;
	while (*s)
		*r++ = f(*(char*)s++);
	return (res);
}

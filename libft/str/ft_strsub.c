/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 10:21:57 by jjacobso          #+#    #+#             */
/*   Updated: 2018/11/22 17:47:06 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	char	*r;

	res = ft_strnew(len);
	if (!res)
		return (NULL);
	r = res;
	while (len--)
		*r++ = *(s + start++);
	return (res);
}

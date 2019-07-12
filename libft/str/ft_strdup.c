/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:05:22 by jjacobso          #+#    #+#             */
/*   Updated: 2018/11/26 17:49:10 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_strdup(const char *src)
{
	char		*res;
	char		*p;

	if (!(res = (char *)malloc(ft_strlen(src) + 1)))
		return (NULL);
	p = res;
	while (*src)
		*res++ = *src++;
	*res = 0;
	return (p);
}

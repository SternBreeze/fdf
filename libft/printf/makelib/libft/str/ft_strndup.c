/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 18:06:43 by jjacobso          #+#    #+#             */
/*   Updated: 2019/01/07 18:07:31 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_strndup(const char *src, int len)
{
	char		*res;
	char		*p;

	if (!(res = (char *)malloc(len + 1)))
		return (NULL);
	p = res;
	while (len--)
		*res++ = *src++;
	*res = 0;
	return (p);
}

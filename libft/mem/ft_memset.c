/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 20:00:59 by jjacobso          #+#    #+#             */
/*   Updated: 2019/04/22 19:28:34 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *dest, int c, size_t len)
{
	char	*d;

	d = (char*)dest;
	while (len--)
		*d++ = c;
	return (dest);
}

void		*ft_intset(void *dest, int c, size_t len)
{
	int		*d;

	d = (int *)dest;
	while (len--)
		*d++ = c;
	return (d);
}

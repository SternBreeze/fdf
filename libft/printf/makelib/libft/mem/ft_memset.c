/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 20:00:59 by jjacobso          #+#    #+#             */
/*   Updated: 2018/11/30 17:48:20 by jjacobso         ###   ########.fr       */
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

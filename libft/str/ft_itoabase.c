/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 10:38:34 by jjacobso          #+#    #+#             */
/*   Updated: 2019/04/15 16:24:27 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoabase(uintmax_t num, int mbase)
{
	char		*res;
	char		*i;
	char		*base;
	int			len;

	base = "0123456789ABCDEF";
	len = ft_nlen(num, mbase);
	if (!(res = ft_strnew(len)))
		return (NULL);
	i = res + len - 1;
	while (len--)
	{
		*i-- = base[num % mbase];
		num /= mbase;
	}
	return (res);
}

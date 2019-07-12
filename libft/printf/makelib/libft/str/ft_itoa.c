/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:03:17 by jjacobso          #+#    #+#             */
/*   Updated: 2019/01/10 10:57:43 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_negative_case(char **r, int *n, int *len)
{
	*(*r)++ = '-';
	if (*n == -2147483648)
	{
		*(*r)++ = '2';
		(*len)--;
		*n = -147483648;
	}
	*n *= -1;
}

char			*ft_itoa(int n)
{
	char		*res;
	char		*r;
	int			len;

	len = ft_nlen(n, 10);
	if (!(res = ft_strnew((n < 0) ? len + 1 : len)))
		return (NULL);
	r = res;
	if (n < 0)
		ft_negative_case(&r, &n, &len);
	r += len - 1;
	while (len--)
	{
		*r-- = n % 10 + '0';
		n /= 10;
	}
	return (res);
}

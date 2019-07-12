/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 13:06:16 by jjacobso          #+#    #+#             */
/*   Updated: 2019/01/27 16:41:29 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_putnwstr(wchar_t *s, int n)
{
	int			len;

	len = 0;
	if (!s)
		return (0);
	if (n > 0)
		while (*s)
		{
			len += ft_wcharlen(*s);
			if (n < len)
			{
				len -= ft_wcharlen(*s);
				break ;
			}
			ft_putwchar(*s++);
		}
	else if (n < 0)
		while (*s)
			len += ft_putwchar(*s++);
	return (len);
}

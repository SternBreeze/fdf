/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 13:37:11 by jjacobso          #+#    #+#             */
/*   Updated: 2019/01/26 17:38:18 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strwlen(wchar_t *s)
{
	int			len;

	if (!s)
		return (0);
	len = 0;
	while (*s)
		len += ft_wcharlen(*s++);
	return (len);
}

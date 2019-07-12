/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nfree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 15:14:14 by jjacobso          #+#    #+#             */
/*   Updated: 2019/01/26 17:27:40 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int				ft_nfree(int n, ...)
{
	va_list		ap;

	va_start(ap, n);
	while (n--)
		ft_memdel(va_arg(ap, void**));
	va_end(ap);
	return (1);
}

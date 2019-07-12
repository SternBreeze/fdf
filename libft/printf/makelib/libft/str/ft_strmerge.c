/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 14:11:45 by jjacobso          #+#    #+#             */
/*   Updated: 2019/01/26 17:38:06 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strmerge(int num, ...)
{
	char		*res;
	char		**arg;
	va_list		ap;
	int			size;
	int			n;

	if (num < 2)
		return (NULL);
	size = 0;
	n = num;
	va_start(ap, num);
	while (n--)
		size += ft_strlen(*(va_arg(ap, char**)));
	va_end(ap);
	if (!(res = ft_strnew(size)))
		return (NULL);
	va_start(ap, num);
	while (num--)
	{
		arg = va_arg(ap, char**);
		res = (*arg) ? ft_strcat(res, *arg) : res;
		ft_memdel((void**)arg);
	}
	va_end(ap);
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnfjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:54:21 by jjacobso          #+#    #+#             */
/*   Updated: 2019/01/21 14:08:43 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnfjoin(char **str1, char const *str2, int len)
{
	char	*res;
	char	*r;
	char	*s1;

	if (!*str1)
		return (ft_strndup(str2, len));
	s1 = *str1;
	if (!(res = ft_strnew(ft_strlen(s1) + ft_strlen(str2))))
		return (NULL);
	r = res;
	while (*s1)
		*r++ = *s1++;
	while (len--)
		*r++ = *str2++;
	ft_memdel(&*(void**)str1);
	return (res);
}

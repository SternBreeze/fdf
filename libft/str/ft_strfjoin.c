/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 14:16:22 by jjacobso          #+#    #+#             */
/*   Updated: 2019/04/01 19:46:55 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strfjoin(char **str1, char const *str2)
{
	char	*res;
	char	*r;
	char	*s1;

	if (!*str1)
		return (ft_strdup(str2));
	s1 = *str1;
	if (!(res = ft_strnew(ft_strlen(s1) + ft_strlen(str2))))
		return (NULL);
	r = res;
	while (*s1)
		*r++ = *s1++;
	while (*str2)
		*r++ = *str2++;
	ft_memdel(&*(void**)str1);
	return (res);
}

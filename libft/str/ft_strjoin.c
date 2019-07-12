/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 10:51:10 by jjacobso          #+#    #+#             */
/*   Updated: 2018/12/03 18:54:08 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	char	*r;

	res = (char*)ft_strnew(ft_strlen(s1)
			+ ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	r = res;
	while (s1 && *s1)
		*r++ = *s1++;
	while (s2 && *s2)
		*r++ = *s2++;
	return (res);
}

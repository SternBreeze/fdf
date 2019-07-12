/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:37:45 by jjacobso          #+#    #+#             */
/*   Updated: 2019/01/07 17:52:02 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strncat(char *str1, const char *str2, size_t len)
{
	char		*s1;
	const char	*s2;

	s1 = str1;
	s2 = str2;
	while (*s1)
		s1++;
	while (*s2 && len--)
		*s1++ = *s2++;
	*s1 = '\0';
	return (str1);
}

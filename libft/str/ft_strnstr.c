/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:52:19 by jjacobso          #+#    #+#             */
/*   Updated: 2018/11/26 12:57:18 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *stack, const char *needle, size_t len)
{
	const char	*s;

	s = stack - 1;
	if (!*needle)
		return ((char*)stack);
	while (*++s && len--)
		if (ft_strncmp(s, needle, ft_strlen(needle)) == 0
			&& len + 1 >= ft_strlen(needle))
			return ((char*)s);
	return (NULL);
}

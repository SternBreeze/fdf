/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:22:26 by jjacobso          #+#    #+#             */
/*   Updated: 2018/11/26 12:57:44 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strstr(const char *stack, const char *needle)
{
	const char	*s;

	s = stack - 1;
	if (!*needle)
		return ((char*)stack);
	while (*++s)
		if (ft_strncmp(s, needle, ft_strlen(needle)) == 0)
			return ((char*)s);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 10:57:53 by jjacobso          #+#    #+#             */
/*   Updated: 2018/11/26 16:27:16 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_is_space(char c)
{
	return (c == '\t' || c == '\n' || c == ' ');
}

char			*ft_strtrim(char const *src)
{
	char const	*start;
	char const	*s;
	size_t		len;

	s = src;
	start = s;
	while (ft_is_space(*s++))
		start++;
	while (*s)
		s++;
	while (--s != start && ft_is_space(*s))
		;
	len = s - start + 1;
	return (ft_strsub(start, 0, len));
}

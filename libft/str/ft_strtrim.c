/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 10:57:53 by jjacobso          #+#    #+#             */
/*   Updated: 2019/01/30 20:37:33 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *src)
{
	char const	*start;
	char const	*s;
	size_t		len;

	s = src;
	start = s;
	while (ft_isspace(*s++))
		start++;
	while (*s)
		s++;
	while (--s != start && ft_isspace(*s))
		;
	len = s - start + 1;
	return (ft_strsub(start, 0, len));
}

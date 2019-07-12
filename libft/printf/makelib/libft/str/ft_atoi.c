/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:40:34 by jjacobso          #+#    #+#             */
/*   Updated: 2019/01/12 12:16:22 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_space(char c)
{
	return (c == '\t' || c == '\n' || c == ' '
			|| c == '\r' || c == '\v' || c == '\f');
}

int				ft_atoi(const char *str)
{
	const char	*s;
	int			res;
	int			sign;

	res = 0;
	s = str - 1;
	sign = 1;
	while (is_space(*++s))
		;
	if (*s == '+' || *s == '-')
		sign = (*s++ == '-') ? (-sign) : (sign);
	else if (!ft_isdigit(*s))
		return (0);
	while (ft_isdigit(*s))
		res = res * 10 + *s++ - '0';
	return (res * sign);
}

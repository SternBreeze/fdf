/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:40:34 by jjacobso          #+#    #+#             */
/*   Updated: 2019/01/30 14:26:19 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t		ft_atoi(const char *str)
{
	const char	*s;
	intmax_t	res;
	int			sign;

	if (!str)
		return (LONG_MAX);
	res = 0;
	s = str - 1;
	sign = 1;
	while (ft_isspace(*++s))
		;
	if (*s == '+' || *s == '-')
		sign = (*s++ == '-') ? (-sign) : (sign);
	else if (!ft_isdigit(*s))
		return (0);
	while (ft_isdigit(*s))
		res = res * 10 + *s++ - '0';
	return (res * sign);
}

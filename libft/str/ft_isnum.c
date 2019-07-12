/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:05:53 by jjacobso          #+#    #+#             */
/*   Updated: 2019/03/07 18:18:14 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_isnum(char *s)
{
	int			i;
	long		num;
	int			sign;

	num = 0;
	sign = 1;
	i = 0;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	else if (*s == '+')
		s++;
	while (s && *s)
	{
		if (!ft_isdigit(*s))
			return (0);
		num = (*s++ - '0') + num * 10;
		i++;
		if (i > 10 || ((sign > 0 && num > INT_MAX)
					|| (sign < 0 && -num < INT_MIN)))
			return (0);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoibase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 10:38:34 by jjacobso          #+#    #+#             */
/*   Updated: 2019/05/21 22:01:23 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				to_int(char c)
{
	if (ft_isalpha(c))
		return (15 - ('f' - c));
	return (c - '0');
}

int				ft_atoibase(char *s, int mbase)
{
	int			res;

	s = ft_strlower(s);
	res = 0;
	while (s && *s)
	{
		res = res * mbase + to_int(*s);
		s++;
	}
	return (res);
}

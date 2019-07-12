/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lento.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:18:15 by jjacobso          #+#    #+#             */
/*   Updated: 2018/12/03 16:29:13 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlento(char *s, char c)
{
	size_t	res;

	res = 0;
	while (*s && *s != c)
	{
		res++;
		s++;
	}
	return (res);
}

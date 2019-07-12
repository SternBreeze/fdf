/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fpow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:14:14 by jjacobso          #+#    #+#             */
/*   Updated: 2019/01/26 17:26:54 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double						ft_fpow(long double base, long double ex)
{
	long double					res;

	res = 1;
	if (ex < 0)
	{
		ex *= -1;
		while (ex-- > 0)
			res /= base;
	}
	else
		while (ex-- > 0)
			res *= base;
	return (res);
}

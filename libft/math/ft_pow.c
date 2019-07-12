/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 15:37:13 by jjacobso          #+#    #+#             */
/*   Updated: 2019/01/26 17:27:06 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long				ft_pow(int a, int b)
{
	unsigned long long			res;

	res = 1;
	if (!a)
		return (0);
	if (b < 0)
	{
		b *= -1;
		while (b--)
			res /= a;
	}
	else
		while (b--)
			res *= a;
	return (res);
}

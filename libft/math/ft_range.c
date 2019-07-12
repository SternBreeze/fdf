/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:21:48 by jjacobso          #+#    #+#             */
/*   Updated: 2019/03/25 19:10:39 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_range(int x, int y)
{
	if ((x < 0 && y < 0) || (x > 0 && y > 0))
		return (x > y ? x - y : y - x);
	else
		return (ABS(y) + ABS(x));
}

float			ft_frange(float x, float y)
{
	if ((x < 0 && y < 0) || (x > 0 && y > 0))
		return (x > y ? x - y : y - x);
	else
		return (ABS(y) + ABS(x));
}

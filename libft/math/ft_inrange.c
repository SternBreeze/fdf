/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inrange.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:17:37 by jjacobso          #+#    #+#             */
/*   Updated: 2019/04/22 14:38:20 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_inrange(int x, int s, int e)
{
	if ((x >= s && x <= e) || (x >= e && x <= s))
		return (1);
	return (0);
}

int			ft_finrange(double x, double s, double e)
{
	if ((x >= s && x <= e) || (x >= e && x <= s))
		return (1);
	return (0);
}

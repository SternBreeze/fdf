/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 15:39:13 by jjacobso          #+#    #+#             */
/*   Updated: 2019/02/08 17:21:01 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

int			ft_min3(int a, int b, int c)
{
	return (ft_min(a, ft_min(b, c)));
}

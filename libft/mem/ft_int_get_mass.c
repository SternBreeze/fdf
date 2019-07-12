/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_get_mass.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:38:01 by jjacobso          #+#    #+#             */
/*   Updated: 2019/01/30 19:38:41 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_int_get_mass(int m)
{
	long				*i;

	EXITIF(!(i = malloc(sizeof(long))));
	*i = m;
	return ((void *)i);
}

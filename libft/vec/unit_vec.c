/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_vec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:09:06 by jjacobso          #+#    #+#             */
/*   Updated: 2019/04/23 17:39:40 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		unit_vec3(double v[3], double x, double y, double z)
{
	double		len;

	len = sqrt(x * x + y * y + z * z);
	v[0] = x / len;
	v[1] = y / len;
	v[2] = z / len;
}

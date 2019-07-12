/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:16:49 by jjacobso          #+#    #+#             */
/*   Updated: 2019/04/23 19:53:53 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_tetra				*tetra_mas(t_tetra t)
{
	t_tetra			*res;

	if (!(res = malloc(sizeof(t_tetra))))
		error("malloc error");
	*res = t;
	return (res);
}

void				*copy_tetra(void *tetra)
{
	return (tetra_mas(*(t_tetra *)tetra));
}

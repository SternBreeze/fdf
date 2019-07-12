/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:44:03 by jjacobso          #+#    #+#             */
/*   Updated: 2019/05/21 16:21:05 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int						map_reset(t_view *view)
{
	MAP.offset.x = 0;
	MAP.offset.y = 0;
	MAP.last_offset.x = 0;
	MAP.last_offset.y = 0;
	PROPS.alpha = 0;
	PROPS.beta = 0;
	PROPS.brightness = 100;
	auto_scale(view);
	project(view);
	print_map(view);
	return (1);
}

t_coord					dot_center_coord(t_view *view)
{
	double				x;
	double				y;

	x = DOT(0, 0).x / 4 + DOT(0, MAP.max_x - 1).x / 4
						+ DOT(MAP.max_y - 1, 0).x / 4
						+ DOT(MAP.max_y - 1, MAP.max_x - 1).x / 4;
	y = DOT(0, 0).y / 4 + DOT(0, MAP.max_x - 1).y / 4
						+ DOT(MAP.max_y - 1, 0).y / 4
						+ DOT(MAP.max_y - 1, MAP.max_x - 1).y / 4;
	return (C((int)x, (int)y, 0));
}

void					coord_reset(t_coord *c)
{
	*c = C(0, 0, 0);
}

double					dist2d(t_coord a, t_coord b)
{
	return (sqrt(pow(ft_frange(a.x, b.x), 2) + pow(ft_frange(a.y, b.y), 2)));
}

double					dist3d(t_coord a, t_coord b)
{
	return (sqrt(pow(ft_frange(a.x, b.x), 2) + pow(ft_frange(a.y, b.y), 2)
												+ pow(ft_frange(a.z, b.z), 2)));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 21:28:55 by jjacobso          #+#    #+#             */
/*   Updated: 2019/05/20 21:29:37 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		scale_adjust(t_view *view, int key)
{
	double	delta;

	delta = (double)IO.wheel_speed / 100;
	if (key == KEY_MOUSE_DOWN)
	{
		PROPS.fscale += delta;
		if (PROPS.fscale > 2.0)
			PROPS.fscale = 2.0;
	}
	else if (key == KEY_MOUSE_UP)
	{
		PROPS.fscale -= delta;
		if (PROPS.fscale <= 0)
			PROPS.fscale = 0.01;
	}
}

void		auto_scale(t_view *view)
{
	int		diag;

	PROPS.fscale = 2.0;
	MAP.center = dot_center_coord(view);
	diag = (int)sqrt(pow(view->ww / 2, 2) + pow(view->wh / 2, 2)) / 2;
	while (PROPS.fscale * dist2d(MAP.center, DOT(0, 0)) > diag)
	{
		PROPS.fscale -= 0.01;
		if (PROPS.fscale <= 0)
		{
			PROPS.fscale = 0.01;
			break ;
		}
	}
}

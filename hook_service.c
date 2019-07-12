/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_service.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:38:11 by jjacobso          #+#    #+#             */
/*   Updated: 2019/04/23 20:06:42 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			lock_angle(double *angle, double min, double max)
{
	if (*angle * 180 / M_PI >= max)
		*angle = 0;
	else if (*angle * 180 / M_PI <= min)
		*angle = 0;
}

int				get_line_number(int y, int wh)
{
	if (!ft_inrange(y, 0, wh))
		return (-1);
	return (y / 34);
}

void			set_angles(t_view *view, int x, int y)
{
	double		a;
	double		b;
	float		k;

	k = (float)PROPS.rotation_speed / 100;
	a = k * ft_frange(x, MOUSE.x) / fmax(x, MOUSE.x) * (x > MOUSE.x ? 1 : -1);
	b = k * ft_frange(y, MOUSE.y) / fmax(y, MOUSE.y) * (y > MOUSE.y ? -1 : 1);
	if (OPTIONS.rotation_global_sens == INT_SENS)
	{
		PROPS.alpha = (int)((PROPS.alpha + a) * 180 / M_PI) * M_PI / 180;
		PROPS.beta = (int)((PROPS.beta + b) * 180 / M_PI) * M_PI / 180;
	}
	else
	{
		PROPS.alpha = PROPS.alpha + a;
		PROPS.beta = PROPS.beta + b;
	}
}

void			set_hooks(t_view *view)
{
	mlx_hook(view->win, 2, 0, key_press_hook, view);
	mlx_hook(view->win, 4, 0, mouse_press_hook, view);
	mlx_hook(view->win, 5, 0, mouse_release_hook, view);
	mlx_hook(view->win, 6, 0, motion_hook, view);
	mlx_hook(view->win, 17, 0, exit_hook, view);
}

void			set_clr(t_view *view)
{
	int			*clr;
	int			c;

	clr = (IO.read_mode == LINE_CLR) ? (&PROPS.line_clr) : (&PROPS.bg_clr);
	c = IO.input;
	if (IO.read_err == WRONG_NUM)
		*clr = IO.saved_clr;
	else if (IO.to_read == 'r')
		*clr = (*clr & 0x00FFFF) | (c << 16);
	else if (IO.to_read == 'g')
		*clr = (*clr & 0xFF00FF) | (c << 8);
	else
		*clr = (*clr & 0xFFFF00) | (c);
	if (IO.read_mode == LINE_CLR)
	{
		set_line_color(view);
		apply_light(view);
		project(view);
	}
}
